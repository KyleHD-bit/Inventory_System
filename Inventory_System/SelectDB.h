#pragma once
#include "User.h"

namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SelectDB
	/// </summary>
	public ref class SelectDB : public System::Windows::Forms::Form
	{
	public:
		SelectDB(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SelectDB()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button1;
	protected:
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button2;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button3;


	private: System::Windows::Forms::Label^ label1;
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;


	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox1;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel2;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox2;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox1;



	private: System::ComponentModel::IContainer^ components;

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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SelectDB::typeid));
			this->guna2Button1 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button2 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button3 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			this->guna2PictureBox1 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->guna2Panel2 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2ControlBox1 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2ControlBox2 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->BeginInit();
			this->guna2Panel2->SuspendLayout();
			this->guna2Panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// guna2Button1
			// 
			this->guna2Button1->CheckedState->Parent = this->guna2Button1;
			this->guna2Button1->CustomImages->Parent = this->guna2Button1;
			this->guna2Button1->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button1->ForeColor = System::Drawing::Color::Black;
			this->guna2Button1->HoverState->Parent = this->guna2Button1;
			this->guna2Button1->Location = System::Drawing::Point(347, 124);
			this->guna2Button1->Margin = System::Windows::Forms::Padding(4);
			this->guna2Button1->Name = L"guna2Button1";
			this->guna2Button1->ShadowDecoration->Parent = this->guna2Button1;
			this->guna2Button1->Size = System::Drawing::Size(501, 55);
			this->guna2Button1->TabIndex = 0;
			this->guna2Button1->Text = L"LEE";
			this->guna2Button1->Click += gcnew System::EventHandler(this, &SelectDB::guna2Button1_Click);
			// 
			// guna2Button2
			// 
			this->guna2Button2->CheckedState->Parent = this->guna2Button2;
			this->guna2Button2->CustomImages->Parent = this->guna2Button2;
			this->guna2Button2->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button2->ForeColor = System::Drawing::Color::Black;
			this->guna2Button2->HoverState->Parent = this->guna2Button2;
			this->guna2Button2->Location = System::Drawing::Point(347, 187);
			this->guna2Button2->Margin = System::Windows::Forms::Padding(4);
			this->guna2Button2->Name = L"guna2Button2";
			this->guna2Button2->ShadowDecoration->Parent = this->guna2Button2;
			this->guna2Button2->Size = System::Drawing::Size(501, 55);
			this->guna2Button2->TabIndex = 1;
			this->guna2Button2->Text = L"General Fund";
			this->guna2Button2->Click += gcnew System::EventHandler(this, &SelectDB::guna2Button2_Click);
			// 
			// guna2Button3
			// 
			this->guna2Button3->CheckedState->Parent = this->guna2Button3;
			this->guna2Button3->CustomImages->Parent = this->guna2Button3;
			this->guna2Button3->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button3->ForeColor = System::Drawing::Color::Black;
			this->guna2Button3->HoverState->Parent = this->guna2Button3;
			this->guna2Button3->Location = System::Drawing::Point(347, 250);
			this->guna2Button3->Margin = System::Windows::Forms::Padding(4);
			this->guna2Button3->Name = L"guna2Button3";
			this->guna2Button3->ShadowDecoration->Parent = this->guna2Button3;
			this->guna2Button3->Size = System::Drawing::Size(501, 55);
			this->guna2Button3->TabIndex = 2;
			this->guna2Button3->Text = L"Trust Fund";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"TechnicBold", 12));
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(26, 16);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(334, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"CHOOSE THE DATA TO BE OPENED";
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->TargetControl = this;
			// 
			// guna2PictureBox1
			// 
			this->guna2PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox1.Image")));
			this->guna2PictureBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->guna2PictureBox1->Location = System::Drawing::Point(31, 60);
			this->guna2PictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->guna2PictureBox1->Name = L"guna2PictureBox1";
			this->guna2PictureBox1->ShadowDecoration->Parent = this->guna2PictureBox1;
			this->guna2PictureBox1->Size = System::Drawing::Size(281, 268);
			this->guna2PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->guna2PictureBox1->TabIndex = 12;
			this->guna2PictureBox1->TabStop = false;
			// 
			// guna2Panel2
			// 
			this->guna2Panel2->BackColor = System::Drawing::Color::Blue;
			this->guna2Panel2->Controls->Add(this->guna2PictureBox1);
			this->guna2Panel2->Location = System::Drawing::Point(0, 0);
			this->guna2Panel2->Margin = System::Windows::Forms::Padding(4);
			this->guna2Panel2->Name = L"guna2Panel2";
			this->guna2Panel2->ShadowDecoration->Parent = this->guna2Panel2;
			this->guna2Panel2->Size = System::Drawing::Size(355, 383);
			this->guna2Panel2->TabIndex = 13;
			// 
			// guna2ControlBox1
			// 
			this->guna2ControlBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox1->BorderColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->HoverState->Parent = this->guna2ControlBox1;
			this->guna2ControlBox1->IconColor = System::Drawing::Color::Black;
			this->guna2ControlBox1->Location = System::Drawing::Point(447, 15);
			this->guna2ControlBox1->Margin = System::Windows::Forms::Padding(4);
			this->guna2ControlBox1->Name = L"guna2ControlBox1";
			this->guna2ControlBox1->ShadowDecoration->Parent = this->guna2ControlBox1;
			this->guna2ControlBox1->Size = System::Drawing::Size(40, 36);
			this->guna2ControlBox1->TabIndex = 1;
			// 
			// guna2ControlBox2
			// 
			this->guna2ControlBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox2->BorderColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MinimizeBox;
			this->guna2ControlBox2->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->HoverState->Parent = this->guna2ControlBox2;
			this->guna2ControlBox2->IconColor = System::Drawing::Color::Black;
			this->guna2ControlBox2->Location = System::Drawing::Point(403, 15);
			this->guna2ControlBox2->Margin = System::Windows::Forms::Padding(4);
			this->guna2ControlBox2->Name = L"guna2ControlBox2";
			this->guna2ControlBox2->ShadowDecoration->Parent = this->guna2ControlBox2;
			this->guna2ControlBox2->Size = System::Drawing::Size(36, 36);
			this->guna2ControlBox2->TabIndex = 2;
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->BackColor = System::Drawing::Color::Transparent;
			this->guna2Panel1->Controls->Add(this->guna2ControlBox2);
			this->guna2Panel1->Controls->Add(this->guna2ControlBox1);
			this->guna2Panel1->Controls->Add(this->label1);
			this->guna2Panel1->Location = System::Drawing::Point(347, 0);
			this->guna2Panel1->Margin = System::Windows::Forms::Padding(4);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->ShadowDecoration->Parent = this->guna2Panel1;
			this->guna2Panel1->Size = System::Drawing::Size(501, 52);
			this->guna2Panel1->TabIndex = 4;
			// 
			// SelectDB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(849, 382);
			this->Controls->Add(this->guna2Panel2);
			this->Controls->Add(this->guna2Panel1);
			this->Controls->Add(this->guna2Button3);
			this->Controls->Add(this->guna2Button2);
			this->Controls->Add(this->guna2Button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"SelectDB";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Select DataBase";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->EndInit();
			this->guna2Panel2->ResumeLayout(false);
			this->guna2Panel1->ResumeLayout(false);
			this->guna2Panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//on cpp
		void guna2Button1_Click(System::Object^ sender, System::EventArgs^ e);
		void guna2Button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
