#pragma once

namespace InventorySystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class EditForm : public System::Windows::Forms::Form
    {
    public:
        // Declare controls
        System::Windows::Forms::TextBox^ textBoxArticle;
        System::Windows::Forms::TextBox^ textBoxDesc;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::TextBox^ textBoxPn;
        System::Windows::Forms::TextBox^ textBoxDa;
        System::Windows::Forms::TextBox^ textBoxUom;
        System::Windows::Forms::TextBox^ textBoxAo;
        System::Windows::Forms::Label^ label7;
        System::Windows::Forms::Label^ label8;
        System::Windows::Forms::Label^ label9;
        System::Windows::Forms::Label^ label10;
        System::Windows::Forms::Label^ label11;
        System::Windows::Forms::Label^ label12;
        System::Windows::Forms::Label^ label13;
        System::Windows::Forms::TextBox^ textBoxLn;
        System::Windows::Forms::TextBox^ textBoxUov;
        System::Windows::Forms::TextBox^ textBoxBpq;
        System::Windows::Forms::TextBox^ textBoxOpq;
        System::Windows::Forms::TextBox^ textBoxQty;
        System::Windows::Forms::TextBox^ textBoxVal;
        System::Windows::Forms::TextBox^ textBoxRm;  
        System::Windows::Forms::Button^ okButton;

        EditForm(String^ currentValue, String^ currentDesc, String^ currentPn, String^ currentDa, String^ currentUom, String^ currentUov, String^ currentAo, String^ currentLn, String^ currentBpq, String^ currentOpq, String^ currentQty, String^ currentVal, String^ currentRm)
        {
            InitializeComponent();

            // Initialize the text boxes with the passed values
            textBoxArticle->Text = currentValue;
            textBoxDesc->Text = currentDesc;
            textBoxPn->Text = currentPn;
            textBoxDa->Text = currentDa;
            textBoxUom->Text = currentUom;
            textBoxUov->Text = currentUov;
            textBoxAo->Text = currentAo;
            textBoxLn->Text = currentLn;
            textBoxBpq->Text = currentBpq;
            textBoxOpq->Text = currentOpq;
            textBoxQty->Text = currentQty;
            textBoxVal->Text = currentVal;
            textBoxRm->Text = currentRm;

        }

    protected:
        ~EditForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
      System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditForm::typeid));
            this->textBoxArticle = (gcnew System::Windows::Forms::TextBox());
            this->textBoxDesc = (gcnew System::Windows::Forms::TextBox());
            this->okButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->textBoxPn = (gcnew System::Windows::Forms::TextBox());
            this->textBoxDa = (gcnew System::Windows::Forms::TextBox());
            this->textBoxUom = (gcnew System::Windows::Forms::TextBox());
            this->textBoxAo = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->textBoxLn = (gcnew System::Windows::Forms::TextBox());
            this->textBoxUov = (gcnew System::Windows::Forms::TextBox());
            this->textBoxBpq = (gcnew System::Windows::Forms::TextBox());
            this->textBoxOpq = (gcnew System::Windows::Forms::TextBox());
            this->textBoxQty = (gcnew System::Windows::Forms::TextBox());
            this->textBoxVal = (gcnew System::Windows::Forms::TextBox());
            this->textBoxRm = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // textBoxArticle
            // 
            this->textBoxArticle->Location = System::Drawing::Point(12, 41);
            this->textBoxArticle->Name = L"textBoxArticle";
            this->textBoxArticle->Size = System::Drawing::Size(202, 20);
            this->textBoxArticle->TabIndex = 0;
            // 
            // textBoxDesc
            // 
            this->textBoxDesc->Location = System::Drawing::Point(12, 89);
            this->textBoxDesc->Name = L"textBoxDesc";
            this->textBoxDesc->Size = System::Drawing::Size(202, 20);
            this->textBoxDesc->TabIndex = 1;
            // 
            // okButton
            // 
            this->okButton->Location = System::Drawing::Point(714, 336);
            this->okButton->Name = L"okButton";
            this->okButton->Size = System::Drawing::Size(75, 23);
            this->okButton->TabIndex = 2;
            this->okButton->Text = L"OK";
            this->okButton->Click += gcnew System::EventHandler(this, &EditForm::okButton_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 19);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(36, 13);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Article";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(12, 70);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(60, 13);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Description";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(12, 123);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(86, 13);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Property Number";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(12, 177);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(69, 13);
            this->label4->TabIndex = 6;
            this->label4->Text = L"Date Aquired";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(12, 228);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(82, 13);
            this->label5->TabIndex = 7;
            this->label5->Text = L"Unit of Measure";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(12, 285);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(77, 13);
            this->label6->TabIndex = 8;
            this->label6->Text = L"Acctble Officer";
            // 
            // textBoxPn
            // 
            this->textBoxPn->Location = System::Drawing::Point(15, 139);
            this->textBoxPn->Name = L"textBoxPn";
            this->textBoxPn->Size = System::Drawing::Size(199, 20);
            this->textBoxPn->TabIndex = 9;
            // 
            // textBoxDa
            // 
            this->textBoxDa->Location = System::Drawing::Point(15, 193);
            this->textBoxDa->Name = L"textBoxDa";
            this->textBoxDa->Size = System::Drawing::Size(199, 20);
            this->textBoxDa->TabIndex = 10;
            // 
            // textBoxUom
            // 
            this->textBoxUom->Location = System::Drawing::Point(15, 247);
            this->textBoxUom->Name = L"textBoxUom";
            this->textBoxUom->Size = System::Drawing::Size(199, 20);
            this->textBoxUom->TabIndex = 11;
            // 
            // textBoxAo
            // 
            this->textBoxAo->Location = System::Drawing::Point(15, 303);
            this->textBoxAo->Name = L"textBoxAo";
            this->textBoxAo->Size = System::Drawing::Size(199, 20);
            this->textBoxAo->TabIndex = 12;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(318, 19);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(48, 13);
            this->label7->TabIndex = 13;
            this->label7->Text = L"Location";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(318, 70);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(84, 13);
            this->label8->TabIndex = 14;
            this->label8->Text = L"Balance Per Qty";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(318, 123);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(83, 13);
            this->label9->TabIndex = 15;
            this->label9->Text = L"Onhand Per Qty";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(318, 177);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(46, 13);
            this->label10->TabIndex = 16;
            this->label10->Text = L"Quantity";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(320, 228);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(34, 13);
            this->label11->TabIndex = 17;
            this->label11->Text = L"Value";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(320, 285);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(49, 13);
            this->label12->TabIndex = 18;
            this->label12->Text = L"Remarks";
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(618, 19);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(68, 13);
            this->label13->TabIndex = 19;
            this->label13->Text = L"Unit of Value";
            // 
            // textBoxLn
            // 
            this->textBoxLn->Location = System::Drawing::Point(321, 41);
            this->textBoxLn->Name = L"textBoxLn";
            this->textBoxLn->Size = System::Drawing::Size(199, 20);
            this->textBoxLn->TabIndex = 20;
            // 
            // textBoxUov
            // 
            this->textBoxUov->Location = System::Drawing::Point(621, 41);
            this->textBoxUov->Name = L"textBoxUov";
            this->textBoxUov->Size = System::Drawing::Size(202, 20);
            this->textBoxUov->TabIndex = 21;
            // 
            // textBoxBpq
            // 
            this->textBoxBpq->Location = System::Drawing::Point(321, 89);
            this->textBoxBpq->Name = L"textBoxBpq";
            this->textBoxBpq->Size = System::Drawing::Size(199, 20);
            this->textBoxBpq->TabIndex = 22;
            // 
            // textBoxOpq
            // 
            this->textBoxOpq->Location = System::Drawing::Point(321, 139);
            this->textBoxOpq->Name = L"textBoxOpq";
            this->textBoxOpq->Size = System::Drawing::Size(199, 20);
            this->textBoxOpq->TabIndex = 23;
            // 
            // textBoxQty
            // 
            this->textBoxQty->Location = System::Drawing::Point(321, 193);
            this->textBoxQty->Name = L"textBoxQty";
            this->textBoxQty->Size = System::Drawing::Size(199, 20);
            this->textBoxQty->TabIndex = 24;
            // 
            // textBoxVal
            // 
            this->textBoxVal->Location = System::Drawing::Point(321, 247);
            this->textBoxVal->Name = L"textBoxVal";
            this->textBoxVal->Size = System::Drawing::Size(199, 20);
            this->textBoxVal->TabIndex = 25;
            // 
            // textBoxRm
            // 
            this->textBoxRm->Location = System::Drawing::Point(323, 303);
            this->textBoxRm->Name = L"textBoxRm";
            this->textBoxRm->Size = System::Drawing::Size(197, 20);
            this->textBoxRm->TabIndex = 26;
            // 
            // EditForm
            // 
            this->ClientSize = System::Drawing::Size(833, 390);
            this->Controls->Add(this->textBoxRm);
            this->Controls->Add(this->textBoxVal);
            this->Controls->Add(this->textBoxQty);
            this->Controls->Add(this->textBoxOpq);
            this->Controls->Add(this->textBoxBpq);
            this->Controls->Add(this->textBoxUov);
            this->Controls->Add(this->textBoxLn);
            this->Controls->Add(this->label13);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->textBoxAo);
            this->Controls->Add(this->textBoxUom);
            this->Controls->Add(this->textBoxDa);
            this->Controls->Add(this->textBoxPn);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBoxArticle);
            this->Controls->Add(this->textBoxDesc);
            this->Controls->Add(this->okButton);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"EditForm";
            this->Text = L"Muncipality of Buenavista | Edit Form";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void okButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }
};
}
