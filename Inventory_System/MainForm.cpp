#include "MainForm.h"
#include "AddForm.h"
#include "EditForm.h"
#include "ICS.h"
#include <string> // to csv
#include <fstream> //


using namespace FastReport;
using namespace FastReport::Data;
using namespace System::Data;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System::Data::SqlClient;


//Add Button
void InventorySystem::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
			AddForm^ addForm = gcnew AddForm(this); //this
			addForm->ShowDialog();
		}


void InventorySystem::MainForm::gAddBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    AddForm^ addForm = gcnew AddForm(this); //this
    addForm->ShowDialog();
}

//Delete Buttonu
void InventorySystem::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0)
    {
        int selectedIndex = dataGridView1->SelectedRows[0]->Index;
        int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);

        String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ deleteCommand = gcnew SqlCommand("DELETE FROM items WHERE id = @id", connection);
        deleteCommand->Parameters->AddWithValue("@id", id);

        try
        {
            connection->Open();
            deleteCommand->ExecuteNonQuery();
            MessageBox::Show("Item deleted successfully!");

            // Refresh the data grid view
            SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM items", connection);
            DataTable^ dataTable = gcnew DataTable();
            dataAdapter->Fill(dataTable);
            dataGridView1->DataSource = dataTable;
            AdjustRowHeightForDescriptionColumn();

            // Get the maximum ID from the updated DataGridView
            int maxId = 0;
            for (int i = 0; i < dataGridView1->Rows->Count; i++)
            {
                int currentId = Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value);
                if (currentId > maxId)
                {
                    maxId = currentId;
                }
            }

            // Reseed the identity column to the maximum ID
            SqlCommand^ resetIdentityCommand = gcnew SqlCommand("DBCC CHECKIDENT ('items', RESEED, @newSeed);", connection);
            resetIdentityCommand->Parameters->AddWithValue("@newSeed", maxId);
            resetIdentityCommand->ExecuteNonQuery();
        }
        catch (SqlException^ e)
        {
            MessageBox::Show("SQL Error: " + e->Message);
        }
        catch (Exception^ e)
        {
            MessageBox::Show("Error: " + e->Message);
        }
        finally
        {
            connection->Close();
        }
    }
    else
    {
        MessageBox::Show("Please select a row to delete.");
    }
}



void InventorySystem::MainForm::gDelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0)
    {
        int selectedIndex = dataGridView1->SelectedRows[0]->Index;
        int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);

        String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ deleteCommand = gcnew SqlCommand("DELETE FROM items WHERE id = @id", connection);
        deleteCommand->Parameters->AddWithValue("@id", id);

        try
        {
            connection->Open();
            deleteCommand->ExecuteNonQuery();
            MessageBox::Show("Item deleted successfully!");

            // Refresh the data grid view
            SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM items", connection);
            DataTable^ dataTable = gcnew DataTable();
            dataAdapter->Fill(dataTable);
            dataGridView1->DataSource = dataTable;
            AdjustRowHeightForDescriptionColumn();

            // Get the maximum ID from the updated DataGridView
            int maxId = 0;
            for (int i = 0; i < dataGridView1->Rows->Count; i++)
            {
                int currentId = Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value);
                if (currentId > maxId)
                {
                    maxId = currentId;
                }
            }

            // Reseed the identity column to the maximum ID
            SqlCommand^ resetIdentityCommand = gcnew SqlCommand("DBCC CHECKIDENT ('items', RESEED, @newSeed);", connection);
            resetIdentityCommand->Parameters->AddWithValue("@newSeed", maxId);
            resetIdentityCommand->ExecuteNonQuery();
        }
        catch (SqlException^ e)
        {
            MessageBox::Show("SQL Error: " + e->Message);
        }
        catch (Exception^ e)
        {
            MessageBox::Show("Error: " + e->Message);
        }
        finally
        {
            connection->Close();
        }
    }
    else
    {
        MessageBox::Show("Please select a row to delete.");
    }
}

//Refresh Button
void InventorySystem::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
    RefreshData();
}

void InventorySystem::MainForm::gRefBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    RefreshData();
}


//Edit Button
void InventorySystem::MainForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        int selectedRowIndex = dataGridView1->SelectedRows[0]->Index;
        DataGridViewRow^ selectedRow = dataGridView1->Rows[selectedRowIndex];
        int id = Convert::ToInt32(selectedRow->Cells[0]->Value); // ID column

        // Get current value from the cell
        String^ currentArticle = selectedRow->Cells[1]->Value->ToString(); // Adjust column index
        String^ currentDesc = selectedRow->Cells[2]->Value->ToString(); //
        String^ currentPn = selectedRow->Cells[3]->Value->ToString();
        String^ currentDa = selectedRow->Cells[4]->Value->ToString();
        String^ currentUom = selectedRow->Cells[5]->Value->ToString();
        String^ currentUov = selectedRow->Cells[6]->Value->ToString();
        String^ currentAo = selectedRow->Cells[7]->Value->ToString();
        String^ currentLn = selectedRow->Cells[8]->Value->ToString();
        String^ currentBpq = selectedRow->Cells[9]->Value->ToString();
        String^ currentOpq = selectedRow->Cells[10]->Value->ToString();
        String^ currentQty = selectedRow->Cells[11]->Value->ToString();
        String^ currentVal = selectedRow->Cells[12]->Value->ToString();
        String^ currentRm = selectedRow->Cells[13]->Value->ToString();

        // Create an instance of the EditForm with the current value
        EditForm^ editForm = gcnew EditForm(currentArticle, currentDesc, currentPn, currentDa, currentUom, currentUov, currentAo, currentLn, currentBpq, currentOpq, currentQty, currentVal, currentRm); //

        // Show the EditForm as a dialog
        if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ newArticle = editForm->textBoxArticle->Text;
            String^ newDesc = editForm->textBoxDesc->Text; //
            String^ newPn = editForm->textBoxPn->Text;
            String^ newDa = editForm->textBoxDa->Text;
            String^ newUom = editForm->textBoxUom->Text;
            String^ newUov = editForm->textBoxUov->Text;
            String^ newAo = editForm->textBoxAo->Text;
            String^ newLn = editForm->textBoxLn->Text;
            String^ newBpq = editForm->textBoxBpq->Text;
            String^ newOpq = editForm->textBoxOpq->Text;
            String^ newQty = editForm->textBoxQty->Text;
            String^ newVal = editForm->textBoxVal->Text;
            String^ newRm = editForm->textBoxRm->Text;

            // Update the database with the new value
            String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
            SqlConnection^ connection = gcnew SqlConnection(connectionString);
            SqlCommand^ command = gcnew SqlCommand("UPDATE items SET [article] = @newArticle, [description] = @newDesc, [Property Number] = @newPn, [Date Aquired] = @newDa, [Unit of Measure] = @newUom, [Unit of Value] = @newUov, [Acctble Officer] = @newAo, [Location] = @newLn, [Balance Per Qty] = @newBpq, [Onhand Per Qty] = @newOpq, [Quantity] = @newQty, [Value] = @newVal, [Remarks] = @newRm WHERE id = @id", connection);
            command->Parameters->AddWithValue("@newArticle", newArticle);
            command->Parameters->AddWithValue("@newDesc", newDesc); //
            command->Parameters->AddWithValue("@newPn", newPn);
            command->Parameters->AddWithValue("@newDa", newDa);
            command->Parameters->AddWithValue("@newUom", newUom);
            command->Parameters->AddWithValue("@newUov", newUov);
            command->Parameters->AddWithValue("@newAo", newAo);
            command->Parameters->AddWithValue("@newLn", newLn);
            command->Parameters->AddWithValue("@newBpq", newBpq);
            command->Parameters->AddWithValue("@newOpq", newOpq);
            command->Parameters->AddWithValue("@newQty", newQty);
            command->Parameters->AddWithValue("@newVal", newVal);
            command->Parameters->AddWithValue("@newRm", newRm);
            command->Parameters->AddWithValue("@id", id);

            try {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Item updated successfully!");

                // Refresh the data grid view
                RefreshData();
            }
            catch (SqlException^ ex) {
                MessageBox::Show("SQL Error: " + ex->Message);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
            finally {
                connection->Close();
            }
        }
    }
    else {
        MessageBox::Show("Please select a row to edit.");
    }
}




void InventorySystem::MainForm::gEditBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        int selectedRowIndex = dataGridView1->SelectedRows[0]->Index;
        DataGridViewRow^ selectedRow = dataGridView1->Rows[selectedRowIndex];
        int id = Convert::ToInt32(selectedRow->Cells[0]->Value); // ID column

        // Get current value from the cell
        String^ currentArticle = selectedRow->Cells[1]->Value->ToString(); // Adjust column index
        String^ currentDesc = selectedRow->Cells[2]->Value->ToString(); //
        String^ currentPn = selectedRow->Cells[3]->Value->ToString();
        String^ currentDa = selectedRow->Cells[4]->Value->ToString();
        String^ currentUom = selectedRow->Cells[5]->Value->ToString();
        String^ currentUov = selectedRow->Cells[6]->Value->ToString();
        String^ currentAo = selectedRow->Cells[7]->Value->ToString();
        String^ currentLn = selectedRow->Cells[8]->Value->ToString();
        String^ currentBpq = selectedRow->Cells[9]->Value->ToString();
        String^ currentOpq = selectedRow->Cells[10]->Value->ToString();
        String^ currentQty = selectedRow->Cells[11]->Value->ToString();
        String^ currentVal = selectedRow->Cells[12]->Value->ToString();
        String^ currentRm = selectedRow->Cells[13]->Value->ToString();

        // Create an instance of the EditForm with the current value
        EditForm^ editForm = gcnew EditForm(currentArticle, currentDesc, currentPn, currentDa, currentUom, currentUov, currentAo, currentLn, currentBpq, currentOpq, currentQty, currentVal, currentRm); //

        // Show the EditForm as a dialog
        if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ newArticle = editForm->textBoxArticle->Text;
            String^ newDesc = editForm->textBoxDesc->Text; //
            String^ newPn = editForm->textBoxPn->Text;
            String^ newDa = editForm->textBoxDa->Text;
            String^ newUom = editForm->textBoxUom->Text;
            String^ newUov = editForm->textBoxUov->Text;
            String^ newAo = editForm->textBoxAo->Text;
            String^ newLn = editForm->textBoxLn->Text;
            String^ newBpq = editForm->textBoxBpq->Text;
            String^ newOpq = editForm->textBoxOpq->Text;
            String^ newQty = editForm->textBoxQty->Text;
            String^ newVal = editForm->textBoxVal->Text;
            String^ newRm = editForm->textBoxRm->Text;

            // Update the database with the new value
            String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
            SqlConnection^ connection = gcnew SqlConnection(connectionString);
            SqlCommand^ command = gcnew SqlCommand("UPDATE items SET [article] = @newArticle, [description] = @newDesc, [Property Number] = @newPn, [Date Aquired] = @newDa, [Unit of Measure] = @newUom, [Unit of Value] = @newUov, [Acctble Officer] = @newAo, [Location] = @newLn, [Balance Per Qty] = @newBpq, [Onhand Per Qty] = @newOpq, [Quantity] = @newQty, [Value] = @newVal, [Remarks] = @newRm WHERE id = @id", connection);
            command->Parameters->AddWithValue("@newArticle", newArticle);
            command->Parameters->AddWithValue("@newDesc", newDesc); //
            command->Parameters->AddWithValue("@newPn", newPn);
            command->Parameters->AddWithValue("@newDa", newDa);
            command->Parameters->AddWithValue("@newUom", newUom);
            command->Parameters->AddWithValue("@newUov", newUov);
            command->Parameters->AddWithValue("@newAo", newAo);
            command->Parameters->AddWithValue("@newLn", newLn);
            command->Parameters->AddWithValue("@newBpq", newBpq);
            command->Parameters->AddWithValue("@newOpq", newOpq);
            command->Parameters->AddWithValue("@newQty", newQty);
            command->Parameters->AddWithValue("@newVal", newVal);
            command->Parameters->AddWithValue("@newRm", newRm);
            command->Parameters->AddWithValue("@id", id);

            try {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Item updated successfully!");

                // Refresh the data grid view
                RefreshData();
            }
            catch (SqlException^ ex) {
                MessageBox::Show("SQL Error: " + ex->Message);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
            finally {
                connection->Close();
            }
        }
    }
    else {
        MessageBox::Show("Please select a row to edit.");
    }
}

//Filter Button
void InventorySystem::MainForm::filterButton_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ filterText = this->textBoxFilter->Text;
    String^ selectedColumn = this->comboBoxColumn->SelectedItem->ToString();
    String^ columnForFilter = "[" + selectedColumn + "]";

    // Assuming `dataTable` is the DataTable you're displaying in the DataGridView
    DataTable^ dataTable = (DataTable^)this->dataGridView1->DataSource;

    if (String::IsNullOrEmpty(filterText))
    {
        // Remove any filter if the textbox is empty
        dataTable->DefaultView->RowFilter = "";
        AdjustRowHeightForDescriptionColumn();
    }
    else
    {   
        if (selectedColumn == "Location")
        {
            dataTable->DefaultView->RowFilter = String::Format("{0} = '{1}'", columnForFilter, filterText);
        }
        else
        {
            dataTable->DefaultView->RowFilter = String::Format("{0} LIKE '%{1}%'", columnForFilter, filterText);
        }
        // Filter the DataTable, assuming 'column_name' is the column you want to filter by
        //dataTable->DefaultView->RowFilter = String::Format("{0} = '{1}'", columnForFilter, filterText);
        //dataTable->DefaultView->RowFilter = String::Format("{0} LIKE '%{1}%'", columnForFilter, filterText); - not exact input search
        AdjustRowHeightForDescriptionColumn();
    }
}


//########### PRINT ###########



//print Button - to be worked on
void InventorySystem::MainForm::printButton_Click(System::Object^ sender, System::EventArgs^ e) {
    // Adjusted row and height
    AdjustRowHeightForDescriptionColumn();

    //landscape
    printDocument->DefaultPageSettings->Landscape = true;
    
    // Assign the PrintPage event handler
    printDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MainForm::printDocument_PrintPage);

    // Show the print preview dialog
    printPreviewDialog->Document = printDocument;
    printPreviewDialog->ShowDialog();
}


void InventorySystem::MainForm::gPrintBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    // Adjusted row and height
    AdjustRowHeightForDescriptionColumn();

    //landscape
    printDocument->DefaultPageSettings->Landscape = true;

    // Assign the PrintPage event handler
    printDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MainForm::printDocument_PrintPage);

    // Show the print preview dialog
    printPreviewDialog->Document = printDocument;
    printPreviewDialog->ShowDialog();
}

//ICS
void InventorySystem::MainForm::gPrintICS_Click(System::Object^ sender, System::EventArgs^ e) {
    ICS^ ics = gcnew ICS(this); //this
    ics->ShowDialog();
}

// PrintPage event handler
void InventorySystem::MainForm::printDocument_PrintPage(System::Object^ sender, PrintPageEventArgs^ e) {
    // Set landscape orientation
    e->PageSettings->Landscape = true;
    
    // Create a bitmap from the DataGridView's content
    Bitmap^ bitmap = gcnew Bitmap(this->dataGridView1->Width, this->dataGridView1->Height);
    this->dataGridView1->DrawToBitmap(bitmap, this->dataGridView1->ClientRectangle);
    
    // Get the dimensions of the full page area (including margins)
    int pageWidth = e->PageBounds.Width;
    int pageHeight = e->PageBounds.Height;
    
    // Calculate scaling factor based on the full width of the page (not just the margin bounds)
    float scaleX = (float)pageWidth / (float)bitmap->Width;
    float scaleY = (float)pageHeight / (float)bitmap->Height;
    
    // Scale by the width to make sure the image fits across the entire page width
    float scale = scaleX; // Force scaling by width
    
    // Calculate the new dimensions for the scaled image
    int scaledWidth = (int)(bitmap->Width * scale);
    int scaledHeight = (int)(bitmap->Height * scale);
    
    // Draw the scaled image to fit the entire page width
    e->Graphics->DrawImage(bitmap, 0, 0, scaledWidth, scaledHeight);
    
    // No more pages to print
    e->HasMorePages = false;
}



    //// Adjusted row and height
    //AdjustRowHeightForDescriptionColumn();

    ////landscape
    //printDocument->DefaultPageSettings->Landscape = true;

    //// Assign the PrintPage event handler
    //printDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MainForm::printDocument_PrintPage);

    //// Show the print preview dialog
    //printPreviewDialog->Document = printDocument;
    //printPreviewDialog->ShowDialog();



// ##### BITMAP #####
//void InventorySystem::MainForm::printDocument_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
//    // Set landscape orientation
//    e->PageSettings->Landscape = true;
//
//    // Create a bitmap from the DataGridView's content
//    Bitmap^ bitmap = gcnew Bitmap(this->dataGridView1->Width, this->dataGridView1->Height);
//    this->dataGridView1->DrawToBitmap(bitmap, this->dataGridView1->ClientRectangle);
//
//    // Get the dimensions of the full page area (including margins)
//    int pageWidth = e->PageBounds.Width;
//    int pageHeight = e->PageBounds.Height;
//
//    // Calculate scaling factor based on the full width of the page (not just the margin bounds)
//    float scaleX = (float)pageWidth / (float)bitmap->Width;
//    float scaleY = (float)pageHeight / (float)bitmap->Height;
//
//    // Scale by the width to make sure the image fits across the entire page width
//    float scale = scaleX; // Force scaling by width
//
//    // Calculate the new dimensions for the scaled image
//    int scaledWidth = (int)(bitmap->Width * scale);
//    int scaledHeight = (int)(bitmap->Height * scale);
//
//    // Draw the scaled image to fit the entire page width
//    e->Graphics->DrawImage(bitmap, 0, 0, scaledWidth, scaledHeight);
//
//    // No more pages to print
//    e->HasMorePages = false;
//}





//##### DRAW DATAGRIDVIEW #####
// 
// 
//void InventorySystem::MainForm::printDocument_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
//    int rowHeight = 80;  // Desired row height
//    int totalWidth = 0;
//    int availableWidth = e->MarginBounds.Width; // The width of the printable area
//    int startX = e->MarginBounds.Left;  // Starting X position
//    int startY = e->MarginBounds.Top;   // Starting Y position
//
//    // Calculate the total width of all columns
//    for (int i = 0; i < dataGridView1->Columns->Count; i++) {
//        if (dataGridView1->Columns[i]->HeaderText == "Description") {
//            totalWidth += 350; // Description column width
//        }
//        else if (dataGridView1->Columns[i]->HeaderText == "ID") {
//            totalWidth += 25;  // ID column width
//        }
//        else {
//            totalWidth += 100; // Default width for other columns
//        }
//    }
//
//    // Calculate scaling factor based on the available width and total width
//    float scaleFactor = (float)availableWidth / (float)totalWidth;
//
//    // Print column headers with scaling
//    for (int i = 0; i < dataGridView1->Columns->Count; i++) {
//        int columnWidth;
//
//        // Set specific column widths
//        if (dataGridView1->Columns[i]->HeaderText == "Description") {
//            columnWidth = (int)(350 * scaleFactor);
//        }
//        else if (dataGridView1->Columns[i]->HeaderText == "ID") {
//            columnWidth = (int)(25 * scaleFactor);
//        }
//        else {
//            columnWidth = (int)(100 * scaleFactor);
//        }
//
//        // Print column header
//        e->Graphics->DrawString(dataGridView1->Columns[i]->HeaderText,
//            gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Bold),
//            Brushes::Black, startX, startY);
//
//        // Move to the next column
//        startX += columnWidth;
//    }
//
//    // Reset starting positions for row printing
//    startX = e->MarginBounds.Left;
//    startY += (int)(rowHeight * scaleFactor); // Adjust row height with scaling
//
//    // Print rows with scaling
//    for (int row = 0; row < dataGridView1->Rows->Count; row++) {
//        startX = e->MarginBounds.Left; // Reset X position for each row
//
//        for (int col = 0; col < dataGridView1->Columns->Count; col++) {
//            int columnWidth;
//
//            // Set specific column widths
//            if (dataGridView1->Columns[col]->HeaderText == "Description") {
//                columnWidth = (int)(350 * scaleFactor);
//            }
//            else if (dataGridView1->Columns[col]->HeaderText == "ID") {
//                columnWidth = (int)(25 * scaleFactor);
//            }
//            else {
//                columnWidth = (int)(100 * scaleFactor);
//            }
//
//            // Print the cell value
//            if (dataGridView1->Rows[row]->Cells[col]->Value != nullptr) {
//                e->Graphics->DrawString(dataGridView1->Rows[row]->Cells[col]->Value->ToString(),
//                    gcnew System::Drawing::Font("Arial", 10),
//                    Brushes::Black, startX, startY);
//            }
//
//            // Move to the next column
//            startX += columnWidth;
//        }
//
//        // Move to the next row
//        startY += (int)(rowHeight * scaleFactor);
//    }
//
//    // No more pages
//    e->HasMorePages = false;
//}






















// csv
//std::string ConvertString(System::String^ str) {
//    using namespace System::Runtime::InteropServices;
//    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(str)).ToPointer();
//    std::string nativeString = chars;
//    Marshal::FreeHGlobal(System::IntPtr((void*)chars));
//    return nativeString;
//}
//
//void InventorySystem::MainForm::printButton_Click(System::Object^ sender, System::EventArgs^ e) {
//    SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
//    saveFileDialog->Filter = "CSV files (*.csv)|*.csv";
//    saveFileDialog->DefaultExt = "csv";
//
//    if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
//        // Open a file stream to write the CSV file
//        std::ofstream file(ConvertString(saveFileDialog->FileName));
//
//        if (!file.is_open()) {
//            MessageBox::Show("Failed to open the file for writing.");
//            return;
//        }
//
//        // Write column headers
//        for (int col = 0; col < dataGridView1->ColumnCount; col++) {
//            file << ConvertString(dataGridView1->Columns[col]->HeaderText);
//            if (col < dataGridView1->ColumnCount - 1) {
//                file << ",";
//            }
//        }
//        file << "\n";
//
//        // Write rows
//        for (int row = 0; row < dataGridView1->RowCount; row++) {
//            for (int col = 0; col < dataGridView1->ColumnCount; col++) {
//                System::Object^ cellValue = dataGridView1->Rows[row]->Cells[col]->Value;
//                if (cellValue != nullptr) {
//                    file << ConvertString(cellValue->ToString());
//                }
//                if (col < dataGridView1->ColumnCount - 1) {
//                    file << ",";
//                }
//            }
//            file << "\n";
//        }
//
//        // Close the file
//        file.close();
//
//        MessageBox::Show("Data exported successfully.");
//    }
//}