#include "AddForm.h"


namespace InventorySystem {

}
void InventorySystem::AddForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ itemArticle = articleTextBox->Text;
	String^ itemDesc = descriptionTextBox->Text;
	String^ itemProp = propertyTextBox->Text;
	String^ itemDa = dateaTextBox->Text;
	String^ itemUom = unitomTextBox->Text;
	String^ itemUov = unitovtextBox->Text;
	String^ itemAo = acctbleTextBox->Text;
	String^ itemLoc = locationTextBox->Text;
	String^ itemBpq = balanceTextBox->Text;
	String^ itemOpq = onhandTextBox->Text;
	String^ itemQty = quantityTextBox->Text;
	String^ itemValue = valueTextBox->Text;
	String^ itemRks = remarksTextBox->Text;

	String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	SqlCommand^ command = gcnew SqlCommand("INSERT INTO items ([article], [description], [property number], [date aquired], [unit of measure], [unit of value], [acctble officer], [location], [balance per qty] , [onhand per qty], [quantity], [value], [remarks]) VALUES (@article, @desc, @prop, @da, @uom, @uov, @ao, @loc, @bpq, @opq, @qty, @value, @remarks)", connection);
	command->Parameters->AddWithValue("@article", itemArticle);
	command->Parameters->AddWithValue("@desc", itemDesc);
	command->Parameters->AddWithValue("@prop", itemProp);
	command->Parameters->AddWithValue("@da", itemDa);
	command->Parameters->AddWithValue("@uom", itemUom);
	command->Parameters->AddWithValue("@uov", itemUov);
	command->Parameters->AddWithValue("@ao", itemAo);
	command->Parameters->AddWithValue("@loc", itemLoc);
	command->Parameters->AddWithValue("@bpq", itemBpq);
	command->Parameters->AddWithValue("@opq", itemOpq);
	command->Parameters->AddWithValue("@qty", itemQty);
	command->Parameters->AddWithValue("@value", itemValue);
	command->Parameters->AddWithValue("@remarks", itemRks);

	try {
		connection->Open();
		command->ExecuteNonQuery();
		MessageBox::Show("Item added successfully!");

		// Refresh the data grid view
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM items", connection);
		DataTable^ dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);
		mainForm->dataGridView1->DataSource = dataTable; //dataGridView1->DataSource = dataTable;
		mainForm->AdjustRowHeightForDescriptionColumn(); //
	}
	catch (SqlException^ e) {
		MessageBox::Show("SQL Error: " + e->Message);
	}
	catch (Exception^ e) {
		MessageBox::Show("Error: " + e->Message);
	}
	finally {
		connection->Close();
	}
}