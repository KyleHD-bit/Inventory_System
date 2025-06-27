#pragma once

namespace InventorySystem {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class AddTableForm : public Form {
    public:
        String^ TableName; // Store the entered table name

        AddTableForm() {
            this->Text = "Enter Table Name";
            this->Size = System::Drawing::Size(300, 150);
            this->StartPosition = FormStartPosition::CenterScreen;

            Label^ label = gcnew Label();
            label->Text = "Enter Table Name:";
            label->Location = System::Drawing::Point(20, 20);
            this->Controls->Add(label);

            TextBox^ tableNameTextBox = gcnew TextBox();
            tableNameTextBox->Location = System::Drawing::Point(20, 50);
            tableNameTextBox->Size = System::Drawing::Size(200, 20);
            this->Controls->Add(tableNameTextBox);

            Button^ okButton = gcnew Button();
            okButton->Text = "OK";
            okButton->Location = System::Drawing::Point(80, 80);
            okButton->Click += gcnew EventHandler(this, &AddTableForm::OkButton_Click);
            this->Controls->Add(okButton);

            this->tableNameTextBox = tableNameTextBox;
        }

    private:
        TextBox^ tableNameTextBox;

        void OkButton_Click(System::Object^ sender, System::EventArgs^ e) {
            this->TableName = tableNameTextBox->Text->Trim();
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }
    private: System::Void InitializeComponent() {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddTableForm::typeid));
        this->SuspendLayout();
        // 
        // AddTableForm
        // 
        this->ClientSize = System::Drawing::Size(284, 261);
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->Name = L"AddTableForm";
        this->ResumeLayout(false);

    }
    };
}
