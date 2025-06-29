#include "MainForm2.h"
#include "User.h"
#include "LoginForm1.h"
#include "NotificationForm.h"
#include "LoadingForm.h"
#include "AddTableForm.h"
#include "ViewAll.h"


using namespace System::Collections::Generic;


// Logout Button

void InventorySystem::MainForm2::LogOutBtn_Click(System::Object^ sender, System::EventArgs^ e) { //debug here!
    /*NotificationForm^ notifyForm = gcnew NotificationForm("Logout Successful!", "Please login again!");
    //NotificationForm^ notifyForm = gcnew NotificationForm("Login Successful!", "Welcome, " + user->username + "!");
    notifyForm->Show();
    notifyForm->Activate(); */
    
    this->DialogResult = System::Windows::Forms::DialogResult::Cancel;

    //this->Hide();

    //LoginForm1^ loginForm = gcnew LoginForm1(); 
    //loginForm->Show();  

    this->Close();
} 


// Connect to Database BTN

void InventorySystem::MainForm2::ConnectBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataSelectBox->SelectedIndex == -1) {
        MessageBox::Show("Please select a database!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Get the selected database name
    String^ selectedDB = dataSelectBox->SelectedItem->ToString();
    String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108

    // Loading Screen
    InventorySystem::LoadingForm^ loadingScreen = gcnew InventorySystem::LoadingForm();
    loadingScreen->Show();
    Application::DoEvents(); // Process UI updates


    try {
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        sqlConn->Open();

        // Fetch all table names
        String^ tableQuery = "SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE'";
        SqlCommand^ tableCommand = gcnew SqlCommand(tableQuery, sqlConn);
        SqlDataReader^ reader = tableCommand->ExecuteReader();

        tableSelectBox->Items->Clear(); // Clear previous selections
        while (reader->Read()) {
            tableSelectBox->Items->Add(reader["TABLE_NAME"]->ToString());
        }

        reader->Close();
        sqlConn->Close();

        //Close Loading
        loadingScreen->Close();

        // Enable the table selection ComboBox
        if (tableSelectBox->Items->Count > 0) {
            tableSelectBox->Enabled = true;
            MessageBox::Show("Connected to database: " + selectedDB + "\nPlease select a table.",
                "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("No tables found in the selected database!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            tableSelectBox->Enabled = false;
        }
    }
    catch (Exception^ ex) {
        loadingScreen->Close();
        MessageBox::Show("Error connecting to database: " + ex->Message, "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


// Data SelectBox
void InventorySystem::MainForm2::dataSelectBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    if (dataSelectBox->SelectedIndex != -1) { // If a valid item is selected
        ConnectBtn->Enabled = true;  //  Enable the "Connect" button

        if (IsDatabaseConnected()) {
            AddTBBtn->Enabled = true;  //  Enable "Add Table" button only if connected
            if (tableSelectBox->SelectedIndex != -1) {
                DelTBBtn->Enabled = true; //  Enable "Delete Table" button if a table is selected
            }
            else {
               // DelTBBtn->Enabled = false; //  Disable if no table selected
            }
        }
        else {
            AddTBBtn->Enabled = false; //  Disable "Add Table" button if not connected
            //DelTBBtn->Enabled = false; //  Also disable "Delete Table" button
        }
    }
    else {
        //  If no database is selected, disable all related buttons
        ConnectBtn->Enabled = false;
        AddTBBtn->Enabled = false;
       // DelTBBtn->Enabled = false;
    }
}

void InventorySystem::MainForm2::tableSelectBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    if (tableSelectBox->SelectedIndex == -1) return; // Ensure a valid table is selected

    // Show Loading Screen
    InventorySystem::LoadingForm^ loadingScreen = gcnew InventorySystem::LoadingForm();
    loadingScreen->Show();
    Application::DoEvents(); // Process UI updates to prevent freezing

    // Get the selected database and table name
    String^ selectedDB = dataSelectBox->SelectedItem->ToString();
    String^ selectedTable = tableSelectBox->SelectedItem->ToString();
    String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108

    try {
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        sqlConn->Open();

        // Fetch the table data
        String^ dataQuery = "SELECT * FROM [" + selectedTable + "]";
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(dataQuery, sqlConn);
        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);

        // Bind data to DataGridView
        dataGridView1->DataSource = dt;


        // Check if the 'ICS NO.' column exists and reorder it
        if (dataGridView1->Columns->Contains("ICS NO")) {
            // Set the display index to place it after the 'DESCRIPTION' column.
            // DESCRIPTION column is at index 1, so we set ICS NO. to be at index 2.
            dataGridView1->Columns["ICS NO"]->DisplayIndex = 2;
        }

        //  Enable text wrapping for "Description" column
        dataGridView1->Columns["Description"]->DefaultCellStyle->WrapMode = DataGridViewTriState::True;

        //  Expand the "Description" column width
        dataGridView1->Columns["Description"]->Width = 420;

        //  Reduce width for other columns
        dataGridView1->Columns["Balance Per Qty#"]->Width = 80;
        dataGridView1->Columns["ON HAND"]->Width = 80;
        dataGridView1->Columns["Property No#"]->Width = 80;
        //dataGridView1->Columns["Unit Value"]->Width = 80;

        //  Automatically resize row heights to fit text
        dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;

        sqlConn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error loading table data: " + ex->Message, "Data Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    //Close loading
    loadingScreen->Close();
}


// Save Button

void InventorySystem::MainForm2::SaveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->DataSource == nullptr) return; // Ensure there is data
    if (tableSelectBox->SelectedIndex == -1) return; // Ensure a table is selected

    String^ selectedDB = dataSelectBox->SelectedItem->ToString();
    String^ selectedTable = tableSelectBox->SelectedItem->ToString();
    String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108

    try {
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        sqlConn->Open();

        for each(DataGridViewRow ^ row in dataGridView1->Rows) {
            if (row->IsNewRow) continue; // Skip new empty row

            // Unique column to identify each row
            String^ uniqueColumn = "Property No#"; // Change this to your actual primary key column
            String^ uniqueValue = row->Cells[uniqueColumn]->Value->ToString();

            // Construct UPDATE query
            String^ updateQuery = "UPDATE [" + selectedTable + "] SET ";

            for each(DataGridViewCell ^ cell in row->Cells) {
                String^ columnName = cell->OwningColumn->Name;
                if (columnName != uniqueColumn) { // Skip primary key
                    updateQuery += "[" + columnName + "] = @val" + columnName->Replace(" ", "_")->Replace("/", "_")->Replace("#", "_") + ", ";
                }
            }

            // Remove last comma and add WHERE clause
            updateQuery = updateQuery->Substring(0, updateQuery->Length - 2);
            updateQuery += " WHERE [" + uniqueColumn + "] = @uniqueVal";

            SqlCommand^ cmd = gcnew SqlCommand(updateQuery, sqlConn);

            // Bind parameters
            for each(DataGridViewCell ^ cell in row->Cells) {
                String^ columnName = cell->OwningColumn->Name;
                if (columnName != uniqueColumn) {
                    String^ paramName = "@val" + columnName->Replace(" ", "_")->Replace("/", "_")->Replace("#", "_");
                    cmd->Parameters->AddWithValue(paramName, cell->Value == nullptr ? DBNull::Value : cell->Value);
                }
            }
            cmd->Parameters->AddWithValue("@uniqueVal", uniqueValue);
            cmd->ExecuteNonQuery();
        }

        sqlConn->Close();
        MessageBox::Show("Changes saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        SaveBtn->Enabled = false; // Disable Save button after saving

        NotificationForm^ notifyForm = gcnew NotificationForm("Notification", "Successfully saved!");
        notifyForm->Show();


        LoadTableData();
        DeleteEmptyRows();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error saving changes: " + ex->Message, "Save Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

// Add Button

void InventorySystem::MainForm2::AddBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (tableSelectBox->SelectedIndex == -1) return; // Ensure a table is selected

    String^ selectedDB = dataSelectBox->SelectedItem->ToString();
    String^ selectedTable = tableSelectBox->SelectedItem->ToString();
    String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108

    try {
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        sqlConn->Open();

        // Build INSERT query dynamically
        List<String^>^ columnNames = gcnew List<String^>();
        List<String^>^ valuePlaceholders = gcnew List<String^>();

        DataGridViewRow^ newRow = dataGridView1->Rows[dataGridView1->Rows->Count - 2]; // Get the last entered row

        SqlCommand^ cmd = gcnew SqlCommand();

        for each(DataGridViewColumn ^ col in dataGridView1->Columns) {
            if (col->Name != "ID") { // Exclude ID if it's auto-increment
                String^ colName = "[" + col->Name + "]";  // Ensure column name is SQL-safe
                String^ paramName = "@val" + col->Name->Replace(" ", "_")->Replace("/", "_")->Replace("#", "_");

                columnNames->Add(colName);
                valuePlaceholders->Add(paramName);

                cmd->Parameters->AddWithValue(paramName, newRow->Cells[col->Name]->Value == nullptr ? DBNull::Value : newRow->Cells[col->Name]->Value);
            }
        }

        // Construct INSERT query
        String^ insertQuery = "INSERT INTO [" + selectedTable + "] (" + String::Join(", ", columnNames) + ") VALUES (" + String::Join(", ", valuePlaceholders) + ")";
        cmd->CommandText = insertQuery;
        cmd->Connection = sqlConn;
        cmd->ExecuteNonQuery();

        sqlConn->Close();
        MessageBox::Show("New item added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

        NotificationForm^ notifyForm = gcnew NotificationForm("Notification", "Successfully added!");
        notifyForm->Show();

        LoadTableData();
        DeleteEmptyRows();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error adding new item: " + ex->Message, "Insert Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


// Delete Button

void InventorySystem::MainForm2::DeleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count == 0) {
        MessageBox::Show("Please select a row to delete.", "Delete Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Confirmation before deletion
    if (MessageBox::Show("Are you sure you want to delete the selected item?", "Confirm Delete",
        MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) {
        return;
    }

    // Show Loading Screen
    InventorySystem::LoadingForm^ loadingScreen = gcnew InventorySystem::LoadingForm();
    loadingScreen->Show();
    Application::DoEvents(); // Process UI updates to prevent freezing

    String^ selectedDB = dataSelectBox->SelectedItem->ToString();
    String^ selectedTable = tableSelectBox->SelectedItem->ToString();
    String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108 - tres. IP :: def - localhost no 1433

    try {
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        sqlConn->Open();

        for each (DataGridViewRow ^ row in dataGridView1->SelectedRows) {
            if (row->IsNewRow) continue; // Skip empty row

            //  Build DELETE query based on all column values
            String^ deleteQuery = "DELETE FROM [" + selectedTable + "] WHERE ";
            List<String^>^ conditions = gcnew List<String^>();
            SqlCommand^ cmd = gcnew SqlCommand();
            cmd->Connection = sqlConn;

            for each (DataGridViewCell ^ cell in row->Cells) {
                String^ columnName = cell->OwningColumn->Name;
                String^ paramName = "@val" + columnName->Replace(" ", "_")->Replace("/", "_")->Replace("#", "_");

                if (cell->Value != nullptr && cell->Value->ToString() != "") {
                    conditions->Add("[" + columnName + "] = " + paramName);
                    cmd->Parameters->AddWithValue(paramName, cell->Value);
                }
                else {
                    conditions->Add("[" + columnName + "] IS NULL OR [" + columnName + "] = ''");
                }
            }

            if (conditions->Count > 0) {
                deleteQuery += String::Join(" AND ", conditions);
                cmd->CommandText = deleteQuery;

                int rowsAffected = cmd->ExecuteNonQuery();

                if (rowsAffected > 0) {
                    dataGridView1->Rows->Remove(row);
                }
            }
        }

        //Close loading
        loadingScreen->Close();

        sqlConn->Close();
        MessageBox::Show("Item(s) deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

        NotificationForm^ notifyForm = gcnew NotificationForm("Notification", "Successfully deleted!");
        notifyForm->Show();

        LoadTableData();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error deleting item: " + ex->Message, "Delete Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


// Refresh Button

void InventorySystem::MainForm2::RefBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    // Show Loading Screen
    InventorySystem::LoadingForm^ loadingScreen = gcnew InventorySystem::LoadingForm();
    loadingScreen->Show();
    Application::DoEvents(); // Process UI updates to prevent freezing

    LoadTableData();

    NotificationForm^ notifyForm = gcnew NotificationForm("Notification", "Refreshed!");
    notifyForm->Show();


    //Close loading
    loadingScreen->Close();
}



// IsDataBaseConnected

bool InventorySystem::MainForm2::IsDatabaseConnected() {
    try {
        String^ selectedDB = dataSelectBox->SelectedItem != nullptr ? dataSelectBox->SelectedItem->ToString() : "";
        if (String::IsNullOrWhiteSpace(selectedDB)) return false;

        String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        sqlConn->Open();
        sqlConn->Close();

        return true; //  Connection is valid
    }
    catch (Exception^) {
        return false; //  Connection failed
    }
}



// Add Table Button

void InventorySystem::MainForm2::AddTBBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (!IsDatabaseConnected()) {
        MessageBox::Show("Not connected to a database. Please select a valid database first.", "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    AddTableForm^ addTableForm = gcnew AddTableForm();
    if (addTableForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        String^ tableName = addTableForm->TableName;
        if (String::IsNullOrWhiteSpace(tableName)) {
            MessageBox::Show("Table name cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        String^ selectedDB = dataSelectBox->SelectedItem->ToString();
        String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108

        String^ createTableQuery;

        // Check if the selected database is for SPHV
        if (selectedDB->ToUpper()->Contains("SPHV")) {
            // SPHV Table Format
            createTableQuery =
                "CREATE TABLE [" + tableName + "] ("
                "[Article] NVARCHAR(255),"
                "[DESCRIPTION] NVARCHAR(MAX),"
                "[ICS NO] NVARCHAR(255),"
                "[Property No#] FLOAT,"
                "[DATE AQUIRED] DATE,"
                "[UNIT OF MEASURE] NVARCHAR(255),"
                "[Unit Value] FLOAT,"
                "[ACCTBLE OFFICER] NVARCHAR(255),"
                "[LOCATION] NVARCHAR(255),"
                "[Balance Per Qty#] FLOAT,"
                "[ON HAND] FLOAT,"
                "[SHORTAGE/OVER] FLOAT,"
                "[REMARKS] NVARCHAR(255)"
                ");";
        }
        else {
            // Default Table Format
            createTableQuery =
                "CREATE TABLE [" + tableName + "] ("
                "[Article] NVARCHAR(255),"
                "[DESCRIPTION] NVARCHAR(MAX),"
                "[Property No#] FLOAT,"
                "[DATE AQUIRED] DATE,"
                "[UNIT OF MEASURE] NVARCHAR(255),"
                "[Unit Value] FLOAT,"
                "[ACCTBLE OFFICER] NVARCHAR(255),"
                "[LOCATION] NVARCHAR(255),"
                "[Balance Per Qty#] FLOAT,"
                "[ON HAND] FLOAT,"
                "[SHORTAGE/OVER] FLOAT,"
                "[REMARKS] NVARCHAR(255)"
                ");";
        }

        try {
            SqlConnection^ sqlConn = gcnew SqlConnection(connString);
            sqlConn->Open();

            SqlCommand^ cmd = gcnew SqlCommand(createTableQuery, sqlConn);
            cmd->ExecuteNonQuery();

            sqlConn->Close();
            MessageBox::Show("Table '" + tableName + "' created successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error creating table: " + ex->Message, "Table Creation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    
    NotificationForm^ notifyForm = gcnew NotificationForm("Successful!", "Added New Table!");
    notifyForm->Show();
    

}



// Remove Table Button

void InventorySystem::MainForm2::DelTBBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    // Ensure a database is selected and connected
    if (!IsDatabaseConnected()) {
        MessageBox::Show("No database connection. Please connect first.", "Delete Table Error",
            MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Ensure a table is selected
    if (tableSelectBox->SelectedIndex == -1) {
        MessageBox::Show("Please select a table to delete.", "Delete Table Error",
            MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    String^ selectedDB = dataSelectBox->SelectedItem->ToString();
    String^ selectedTable = tableSelectBox->SelectedItem->ToString();
    String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;"; //192.168.3.108

    // Confirm before deleting
    if (MessageBox::Show("Are you sure you want to delete the table: " + selectedTable + "?", "Confirm Delete",
        MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) {
        return;
    }

    try {
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        sqlConn->Open();

        // Delete (Drop) Table Query
        String^ deleteQuery = "DROP TABLE [" + selectedTable + "]";
        SqlCommand^ cmd = gcnew SqlCommand(deleteQuery, sqlConn);
        cmd->ExecuteNonQuery();

        sqlConn->Close();

        // Remove table from dropdown list
        tableSelectBox->Items->Remove(selectedTable);

        MessageBox::Show("Table '" + selectedTable + "' deleted successfully!", "Success",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error deleting table: " + ex->Message, "Delete Table Error",
            MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    
    NotificationForm^ notifyForm = gcnew NotificationForm("Sucessful!", "Table removed!");
    notifyForm->Show();
    

}



// View All Database

void InventorySystem::MainForm2::vAllBtn_Click(System::Object^ sender, System::EventArgs^ e){

    List<String^>^ selectedDatabases = gcnew List<String^>();

    for each (Object ^ item in dataSelectBox->Items) {
        selectedDatabases->Add(item->ToString());
    }

    InventorySystem::ViewAll^ viewAllForm = gcnew InventorySystem::ViewAll(selectedDatabases); // Correct declaration
    viewAllForm->Show(); // Show the form


}


/* 


*/

/*




*/