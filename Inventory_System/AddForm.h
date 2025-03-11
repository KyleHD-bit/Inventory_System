#pragma once

#include "MainForm.h"

namespace InventorySystem {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	//ref class MainForm;//- comment this if you want to edit this form!

	/// <summary>
	/// Summary for AddForm
	/// </summary>
	public ref class AddForm : public System::Windows::Forms::Form
	{
	public:
		AddForm(MainForm^ form) //-(void) //edit ka di kay daw may error
		{	//MainForm^ form
			InitializeComponent();
			mainForm = form;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MainForm^ mainForm; //-
	private: System::ComponentModel::Container^ components; //-
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ descriptionTextBox;
	private: System::Windows::Forms::TextBox^ propertyTextBox;
	private: System::Windows::Forms::TextBox^ dateaTextBox;
	private: System::Windows::Forms::TextBox^ unitomTextBox;
	private: System::Windows::Forms::TextBox^ acctbleTextBox;
	private: System::Windows::Forms::TextBox^ locationTextBox;
	private: System::Windows::Forms::TextBox^ balanceTextBox;
	private: System::Windows::Forms::TextBox^ onhandTextBox;
	private: System::Windows::Forms::TextBox^ quantityTextBox;
	private: System::Windows::Forms::TextBox^ valueTextBox;
	private: System::Windows::Forms::TextBox^ remarksTextBox;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ unitovtextBox;





	private: System::Windows::Forms::TextBox^ articleTextBox;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->articleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->descriptionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->propertyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dateaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->unitomTextBox = (gcnew System::Windows::Forms::TextBox());
			this->acctbleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->locationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->balanceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->onhandTextBox = (gcnew System::Windows::Forms::TextBox());
			this->quantityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->valueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->remarksTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->unitovtextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Article";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Description";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Property Number";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 198);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Date Aquired";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 254);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Unit Of Measure";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 322);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Acctble Officer";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(267, 18);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Location";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(267, 78);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(84, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Balance Per Qty";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(538, 325);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 47);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Add Item";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddForm::button1_Click);
			// 
			// articleTextBox
			// 
			this->articleTextBox->Location = System::Drawing::Point(20, 41);
			this->articleTextBox->Name = L"articleTextBox";
			this->articleTextBox->Size = System::Drawing::Size(166, 20);
			this->articleTextBox->TabIndex = 9;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(267, 138);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(83, 13);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Onhand Per Qty";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(267, 198);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(46, 13);
			this->label10->TabIndex = 11;
			this->label10->Text = L"Quantity";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(267, 254);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(34, 13);
			this->label11->TabIndex = 12;
			this->label11->Text = L"Value";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(267, 322);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(49, 13);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Remarks";
			// 
			// descriptionTextBox
			// 
			this->descriptionTextBox->Location = System::Drawing::Point(20, 105);
			this->descriptionTextBox->Name = L"descriptionTextBox";
			this->descriptionTextBox->Size = System::Drawing::Size(166, 20);
			this->descriptionTextBox->TabIndex = 14;
			// 
			// propertyTextBox
			// 
			this->propertyTextBox->Location = System::Drawing::Point(20, 163);
			this->propertyTextBox->Name = L"propertyTextBox";
			this->propertyTextBox->Size = System::Drawing::Size(166, 20);
			this->propertyTextBox->TabIndex = 15;
			// 
			// dateaTextBox
			// 
			this->dateaTextBox->Location = System::Drawing::Point(20, 225);
			this->dateaTextBox->Name = L"dateaTextBox";
			this->dateaTextBox->Size = System::Drawing::Size(170, 20);
			this->dateaTextBox->TabIndex = 16;
			// 
			// unitomTextBox
			// 
			this->unitomTextBox->Location = System::Drawing::Point(20, 288);
			this->unitomTextBox->Name = L"unitomTextBox";
			this->unitomTextBox->Size = System::Drawing::Size(166, 20);
			this->unitomTextBox->TabIndex = 17;
			// 
			// acctbleTextBox
			// 
			this->acctbleTextBox->Location = System::Drawing::Point(20, 352);
			this->acctbleTextBox->Name = L"acctbleTextBox";
			this->acctbleTextBox->Size = System::Drawing::Size(166, 20);
			this->acctbleTextBox->TabIndex = 18;
			// 
			// locationTextBox
			// 
			this->locationTextBox->Location = System::Drawing::Point(268, 41);
			this->locationTextBox->Name = L"locationTextBox";
			this->locationTextBox->Size = System::Drawing::Size(166, 20);
			this->locationTextBox->TabIndex = 19;
			// 
			// balanceTextBox
			// 
			this->balanceTextBox->Location = System::Drawing::Point(268, 110);
			this->balanceTextBox->Name = L"balanceTextBox";
			this->balanceTextBox->Size = System::Drawing::Size(166, 20);
			this->balanceTextBox->TabIndex = 20;
			// 
			// onhandTextBox
			// 
			this->onhandTextBox->Location = System::Drawing::Point(268, 171);
			this->onhandTextBox->Name = L"onhandTextBox";
			this->onhandTextBox->Size = System::Drawing::Size(166, 20);
			this->onhandTextBox->TabIndex = 21;
			// 
			// quantityTextBox
			// 
			this->quantityTextBox->Location = System::Drawing::Point(268, 225);
			this->quantityTextBox->Name = L"quantityTextBox";
			this->quantityTextBox->Size = System::Drawing::Size(166, 20);
			this->quantityTextBox->TabIndex = 22;
			// 
			// valueTextBox
			// 
			this->valueTextBox->Location = System::Drawing::Point(268, 288);
			this->valueTextBox->Name = L"valueTextBox";
			this->valueTextBox->Size = System::Drawing::Size(166, 20);
			this->valueTextBox->TabIndex = 23;
			// 
			// remarksTextBox
			// 
			this->remarksTextBox->Location = System::Drawing::Point(268, 352);
			this->remarksTextBox->Name = L"remarksTextBox";
			this->remarksTextBox->Size = System::Drawing::Size(166, 20);
			this->remarksTextBox->TabIndex = 24;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(522, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(68, 13);
			this->label13->TabIndex = 25;
			this->label13->Text = L"Unit of Value";
			// 
			// unitovtextBox
			// 
			this->unitovtextBox->Location = System::Drawing::Point(525, 41);
			this->unitovtextBox->Name = L"unitovtextBox";
			this->unitovtextBox->Size = System::Drawing::Size(166, 20);
			this->unitovtextBox->TabIndex = 26;
			// 
			// AddForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(726, 422);
			this->Controls->Add(this->unitovtextBox);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->remarksTextBox);
			this->Controls->Add(this->valueTextBox);
			this->Controls->Add(this->quantityTextBox);
			this->Controls->Add(this->onhandTextBox);
			this->Controls->Add(this->balanceTextBox);
			this->Controls->Add(this->locationTextBox);
			this->Controls->Add(this->acctbleTextBox);
			this->Controls->Add(this->unitomTextBox);
			this->Controls->Add(this->dateaTextBox);
			this->Controls->Add(this->propertyTextBox);
			this->Controls->Add(this->descriptionTextBox);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->articleTextBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddForm";
			this->Text = L"Municipality of Buenavista | Add Inventory";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void button1_Click(System::Object^ sender, System::EventArgs^ e);

	//private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//String^ itemArticle = articleTextBox->Text;

	//String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
	//SqlConnection^ connection = gcnew SqlConnection(connectionString);
	//SqlCommand^ command = gcnew SqlCommand("INSERT INTO items (article) VALUES (@article)", connection);
	//command->Parameters->AddWithValue("@article", itemArticle);

	//try {
	//connection->Open();
	//command->ExecuteNonQuery();
	//MessageBox::Show("Item added successfully!");

	//// Refresh the data grid view
	//SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM items", connection);
	//DataTable^ dataTable = gcnew DataTable();
	//dataAdapter->Fill(dataTable);
	//mainForm->dataGridView1->DataSource = dataTable; //dataGridView1->DataSource = dataTable;
	//}
	//catch (SqlException^ e) {
	//MessageBox::Show("SQL Error: " + e->Message);
	//}
	//catch (Exception^ e) {
	//MessageBox::Show("Error: " + e->Message);
	//}
	//finally {
	//connection->Close();
	//}
	//}
};
}
