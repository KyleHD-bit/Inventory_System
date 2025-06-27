#pragma once

namespace InventorySystem {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Data::SqlClient;
    using namespace System::Collections::Generic;

    public ref class ViewAll : public Form {
    public:
        ViewAll(List<String^>^ selectedDatabases) {
            this->databases = selectedDatabases;
            InitializeComponent();
            LoadMergedTables();  // Load all database tables when the form opens
        }

    private:
        DataGridView^ dataGridView;  // Display merged data
        List<String^>^ databases;  // List of selected databases



        void InitializeComponent() {
            this->Text = "View All Data";
            this->Size = System::Drawing::Size(1918, 1072);
            this->StartPosition = FormStartPosition::CenterScreen;

            // DataGridView setup
            this->dataGridView = gcnew DataGridView();
            this->dataGridView->Dock = DockStyle::Fill;
            this->dataGridView->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
            this->dataGridView->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
            this->Controls->Add(this->dataGridView);
        }

        // Fetch and merge data from all tables in all databases
        void LoadMergedTables() {
            if (dataGridView == nullptr) {
                MessageBox::Show("Error: DataGridView is not initialized.", "Debug Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            String^ connString = "Data Source=localhost\\SQLEXPRESS;Integrated Security=True;"; //192.168.3.108,1433
            SqlConnection^ sqlConn = gcnew SqlConnection(connString);
            DataTable^ mergedData = gcnew DataTable();

            try {
                sqlConn->Open();
                List<Tuple<String^, String^>^>^ tableList = gcnew List<Tuple<String^, String^>^>();

                // Step 1: Get all table names from selected databases
                for each (String ^ dbName in databases) {
                    String^ query = "SELECT TABLE_NAME FROM [" + dbName + "].INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE';";
                    SqlCommand^ cmd = gcnew SqlCommand(query, sqlConn);
                    SqlDataReader^ reader = cmd->ExecuteReader();

                    while (reader->Read()) {
                        String^ tableName = reader["TABLE_NAME"]->ToString();
                        tableList->Add(gcnew Tuple<String^, String^>(dbName, tableName));
                    }
                    reader->Close();
                }

                // Step 2: Fetch and merge data
                for each (Tuple<String^, String^> ^ table in tableList) {
                    String^ dbName = table->Item1;
                    String^ tableName = table->Item2;

                    // Step 3: Check if "Shortage/Overage1" column exists
                    String^ checkColumnQuery = "SELECT COLUMN_NAME FROM [" + dbName + "].INFORMATION_SCHEMA.COLUMNS "
                        "WHERE TABLE_NAME = '" + tableName + "' AND COLUMN_NAME = 'Shortage/Overage1';";
                    SqlCommand^ checkCmd = gcnew SqlCommand(checkColumnQuery, sqlConn);
                    SqlDataReader^ columnReader = checkCmd->ExecuteReader();
                    bool hasShortageColumn = columnReader->HasRows;
                    columnReader->Close();

                    // Step 4: Build the fetch query
                    String^ fetchQuery = "SELECT '" + dbName + "' AS SourceDB, ";

                    if (hasShortageColumn) {
                        fetchQuery += "CAST([Property No#] AS NVARCHAR) AS [Property No#], ";
                        fetchQuery += "CAST([Shortage/Overage1] AS NVARCHAR) AS [Shortage/Overage1], ";
                    }

                    fetchQuery += "* FROM [" + dbName + "].[dbo].[" + tableName + "]";

                    // Step 5: Execute and store data
                    SqlDataAdapter^ adapter = gcnew SqlDataAdapter(fetchQuery, sqlConn);
                    DataTable^ tempTable = gcnew DataTable();
                    adapter->Fill(tempTable);

                    // Step 6: Ensure mergedData has the correct columns
                    if (mergedData->Columns->Count == 0) {
                        for each (DataColumn ^ col in tempTable->Columns) {
                            if (!mergedData->Columns->Contains(col->ColumnName)) {
                                mergedData->Columns->Add(col->ColumnName, String::typeid);
                            }
                        }
                    }

                    // Step 7: Add rows to merged table
                    for each (DataRow ^ row in tempTable->Rows) {
                        DataRow^ newRow = mergedData->NewRow();
                        for each (DataColumn ^ col in tempTable->Columns) {
                            newRow[col->ColumnName] = row[col->ColumnName]->ToString();
                        }
                        mergedData->Rows->Add(newRow);
                    }
                }

                sqlConn->Close();

                // Step 8: Bind to DataGridView
                dataGridView->DataSource = nullptr;  // Reset first
                if (mergedData->Columns->Count == 0) {
                    MessageBox::Show("No data found to display.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    return;
                }
                dataGridView->DataSource = mergedData;

                // Apply column settings
                SetColumnProperties();

            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading data: " + ex->Message + "\n\nStack Trace:\n" + ex->StackTrace,
                    "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void SetColumnProperties() {
            try {
                if (dataGridView == nullptr || dataGridView->Columns == nullptr || dataGridView->Columns->Count == 0) {
                    return;  // Avoid modifying null or empty columns
                }

                // Set fixed-width for important columns
                if (dataGridView->Columns->Contains("Description")) {
                    dataGridView->Columns["Description"]->Width = 500;
                    dataGridView->Columns["Description"]->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
                }
                if (dataGridView->Columns->Contains("Balance Per Qty#")) {
                    dataGridView->Columns["Balance Per Qty#"]->Width = 100;
                }
                if (dataGridView->Columns->Contains("ON HAND")) {
                    dataGridView->Columns["ON HAND"]->Width = 100;
                }
                if (dataGridView->Columns->Contains("Unit Value")) {
                    dataGridView->Columns["Unit Value"]->Width = 120;
                }
                if (dataGridView->Columns->Contains("SourceDB")) {
                    dataGridView->Columns["SourceDB"]->Width = 100;
                }

                // Fill remaining space dynamically
                for each (DataGridViewColumn ^ col in dataGridView->Columns) {
                    if (col->Width < 150) { // Avoid overriding fixed columns
                        col->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
                    }
                }

                // Refresh DataGridView
                dataGridView->Refresh();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error setting column properties: " + ex->StackTrace,
                    "DataGridView Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}

/*

YOU TELL ME!









*/