#pragma once
#include "User.h"
#include "LoginForm1.h"

// Database SQL
/* #include <sql.h> // depota na sql ni!!
#include <sqlext.h> //
#include <sqltypes.h> //
#include <msclr/marshal_cppstd.h> // */

namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MainForm2
	/// </summary>
	public ref class MainForm2 : public System::Windows::Forms::Form
	{
	private:
		User^ currentUser; //lgout lgin
	public:
		MainForm2(User^ user)
		{
			InitializeComponent();
			LoadDatabases();
			ConnectBtn->Enabled = false;
			tableSelectBox->Enabled = false;

			//	 Allow users to edit cells
			dataGridView1->ReadOnly = false;
			dataGridView1->SelectionMode = DataGridViewSelectionMode::CellSelect;
			dataGridView1->AllowUserToAddRows = false;  // Disable adding new rows manually

			//  Attach event to detect edits
			dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm2::dataGridView1_CellValueChanged);

			//  Auto-size columns to fill the DataGridView
			dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::None;

			//  Prevent extra empty row at the bottom
			//dataGridView1->AllowUserToAddRows = false;
			dataGridView1->AllowUserToAddRows = true;

			//  Enable scrolling
			dataGridView1->ScrollBars = ScrollBars::Both;

			//  Set font for table cells
			dataGridView1->DefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI", 10);
			dataGridView1->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
			dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::White;

			//  Apply alternating row colors
			dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::LightGray;

			//  Column header styling
			dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI", 11, FontStyle::Bold);
			dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::RoyalBlue;
			dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			dataGridView1->EnableHeadersVisualStyles = false; // Apply custom styling

			//  Border styling
			dataGridView1->GridColor = System::Drawing::Color::Silver;
			dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::Single;
			dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;
			dataGridView1->RowHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;

			//  Adjust row height for better spacing
			dataGridView1->RowTemplate->Height = 30;

			//  Enable word wrap in all cells
			dataGridView1->DefaultCellStyle->WrapMode = DataGridViewTriState::True;

			//  Automatically resize rows based on content
			dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;

			//  Row Selecting
			dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dataGridView1->MultiSelect = true; // Optional: Allow only one row to be selected at a time

			this->currentUser = user; //lgout lgin


			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;
	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: Guna::UI2::WinForms::Guna2Button^ LogOutBtn;
	private: Guna::UI2::WinForms::Guna2Button^ RefBtn;
	private: Guna::UI2::WinForms::Guna2Button^ AddBtn;
	private: Guna::UI2::WinForms::Guna2Button^ ConnectBtn;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox3;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox2;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: Guna::UI2::WinForms::Guna2ComboBox^ dataSelectBox;
	private: Guna::UI2::WinForms::Guna2Button^ SaveBtn;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ labelTime;
	private: Guna::UI2::WinForms::Guna2ComboBox^ tableSelectBox;
	private: Guna::UI2::WinForms::Guna2Button^ DeleteBtn;
	private: Guna::UI2::WinForms::Guna2Button^ DelTBBtn;

	private: Guna::UI2::WinForms::Guna2Button^ AddTBBtn;





	private: System::Windows::Forms::Label^ labelDate;

	private: System::Void LoadDatabases() {
		dataSelectBox->Items->Clear(); // Clear previous entries to avoid duplicates

		// Manually add the available databases
		dataSelectBox->Items->Add("LEE");
		dataSelectBox->Items->Add("General Fund");
		dataSelectBox->Items->Add("Trust Fund");

		// Optional: Set placeholder text
		dataSelectBox->Text = "Select a Database";
	}

	private: System::Void dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		SaveBtn->Enabled = true; //  Enable Save button when data is modified
	}

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	public: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		DateTime now = DateTime::Now;

		//labelDate->Text = "Date: " + now.ToString("yyyy-MM-dd");
		//labelTime->Text = "Time: " + now.ToString("HH:mm:ss tt");
		labelDate->Text = now.ToString("MMMM, dd yyyy");
		labelTime->Text = now.ToString("hh:mm:ss tt");
	}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm2::typeid));
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			this->guna2PictureBox1 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AddBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->RefBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->LogOutBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->ConnectBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2ControlBox1 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2ControlBox2 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2ControlBox3 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataSelectBox = (gcnew Guna::UI2::WinForms::Guna2ComboBox());
			this->SaveBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->labelDate = (gcnew System::Windows::Forms::Label());
			this->tableSelectBox = (gcnew Guna::UI2::WinForms::Guna2ComboBox());
			this->DeleteBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->AddTBBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->DelTBBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->TargetControl = this;
			// 
			// guna2PictureBox1
			// 
			this->guna2PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox1.Image")));
			this->guna2PictureBox1->Location = System::Drawing::Point(21, 15);
			this->guna2PictureBox1->Name = L"guna2PictureBox1";
			this->guna2PictureBox1->ShadowDecoration->Parent = this->guna2PictureBox1;
			this->guna2PictureBox1->Size = System::Drawing::Size(141, 126);
			this->guna2PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->guna2PictureBox1->TabIndex = 19;
			this->guna2PictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label1->Location = System::Drawing::Point(168, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(245, 48);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Inventory System";
			// 
			// AddBtn
			// 
			this->AddBtn->Animated = true;
			this->AddBtn->BorderRadius = 10;
			this->AddBtn->CheckedState->Parent = this->AddBtn;
			this->AddBtn->CustomImages->Parent = this->AddBtn;
			this->AddBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->AddBtn->ForeColor = System::Drawing::Color::White;
			this->AddBtn->HoverState->Parent = this->AddBtn;
			this->AddBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddBtn.Image")));
			this->AddBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->AddBtn->Location = System::Drawing::Point(1277, 107);
			this->AddBtn->Name = L"AddBtn";
			this->AddBtn->ShadowDecoration->Parent = this->AddBtn;
			this->AddBtn->Size = System::Drawing::Size(120, 45);
			this->AddBtn->TabIndex = 21;
			this->AddBtn->Text = L"Add Item";
			this->AddBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->AddBtn->Click += gcnew System::EventHandler(this, &MainForm2::AddBtn_Click);
			// 
			// RefBtn
			// 
			this->RefBtn->Animated = true;
			this->RefBtn->BorderRadius = 10;
			this->RefBtn->CheckedState->Parent = this->RefBtn;
			this->RefBtn->CustomImages->Parent = this->RefBtn;
			this->RefBtn->FillColor = System::Drawing::Color::White;
			this->RefBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->RefBtn->ForeColor = System::Drawing::Color::Black;
			this->RefBtn->HoverState->Parent = this->RefBtn;
			this->RefBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefBtn.Image")));
			this->RefBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->RefBtn->Location = System::Drawing::Point(1655, 107);
			this->RefBtn->Name = L"RefBtn";
			this->RefBtn->ShadowDecoration->Parent = this->RefBtn;
			this->RefBtn->Size = System::Drawing::Size(125, 45);
			this->RefBtn->TabIndex = 22;
			this->RefBtn->Text = L"Refresh";
			this->RefBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->RefBtn->Click += gcnew System::EventHandler(this, &MainForm2::RefBtn_Click);
			// 
			// LogOutBtn
			// 
			this->LogOutBtn->Animated = true;
			this->LogOutBtn->BorderRadius = 10;
			this->LogOutBtn->CheckedState->Parent = this->LogOutBtn;
			this->LogOutBtn->CustomImages->Parent = this->LogOutBtn;
			this->LogOutBtn->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->LogOutBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->LogOutBtn->ForeColor = System::Drawing::Color::White;
			this->LogOutBtn->HoverState->Parent = this->LogOutBtn;
			this->LogOutBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogOutBtn.Image")));
			this->LogOutBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->LogOutBtn->Location = System::Drawing::Point(1786, 107);
			this->LogOutBtn->Name = L"LogOutBtn";
			this->LogOutBtn->ShadowDecoration->Parent = this->LogOutBtn;
			this->LogOutBtn->Size = System::Drawing::Size(120, 45);
			this->LogOutBtn->TabIndex = 23;
			this->LogOutBtn->Text = L"Logout";
			this->LogOutBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->LogOutBtn->Click += gcnew System::EventHandler(this, &MainForm2::LogOutBtn_Click);
			// 
			// ConnectBtn
			// 
			this->ConnectBtn->Animated = true;
			this->ConnectBtn->BorderRadius = 7;
			this->ConnectBtn->CheckedState->Parent = this->ConnectBtn;
			this->ConnectBtn->CustomImages->Parent = this->ConnectBtn;
			this->ConnectBtn->FillColor = System::Drawing::Color::DodgerBlue;
			this->ConnectBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->ConnectBtn->ForeColor = System::Drawing::Color::Black;
			this->ConnectBtn->HoverState->Parent = this->ConnectBtn;
			this->ConnectBtn->Location = System::Drawing::Point(176, 95);
			this->ConnectBtn->Name = L"ConnectBtn";
			this->ConnectBtn->ShadowDecoration->Parent = this->ConnectBtn;
			this->ConnectBtn->Size = System::Drawing::Size(306, 38);
			this->ConnectBtn->TabIndex = 24;
			this->ConnectBtn->Text = L"Connect to Database";
			this->ConnectBtn->Click += gcnew System::EventHandler(this, &MainForm2::ConnectBtn_Click);
			// 
			// guna2ControlBox1
			// 
			this->guna2ControlBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox1->Animated = true;
			this->guna2ControlBox1->BackColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->HoverState->Parent = this->guna2ControlBox1;
			this->guna2ControlBox1->IconColor = System::Drawing::Color::Black;
			this->guna2ControlBox1->Location = System::Drawing::Point(1875, 3);
			this->guna2ControlBox1->Name = L"guna2ControlBox1";
			this->guna2ControlBox1->ShadowDecoration->Parent = this->guna2ControlBox1;
			this->guna2ControlBox1->Size = System::Drawing::Size(31, 29);
			this->guna2ControlBox1->TabIndex = 25;
			this->guna2ControlBox1->UseTransparentBackground = true;
			// 
			// guna2ControlBox2
			// 
			this->guna2ControlBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox2->Animated = true;
			this->guna2ControlBox2->BackColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MinimizeBox;
			this->guna2ControlBox2->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->HoverState->Parent = this->guna2ControlBox2;
			this->guna2ControlBox2->IconColor = System::Drawing::Color::Black;
			this->guna2ControlBox2->Location = System::Drawing::Point(1801, 3);
			this->guna2ControlBox2->Name = L"guna2ControlBox2";
			this->guna2ControlBox2->ShadowDecoration->Parent = this->guna2ControlBox2;
			this->guna2ControlBox2->Size = System::Drawing::Size(31, 29);
			this->guna2ControlBox2->TabIndex = 26;
			this->guna2ControlBox2->UseTransparentBackground = true;
			// 
			// guna2ControlBox3
			// 
			this->guna2ControlBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox3->Animated = true;
			this->guna2ControlBox3->BackColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox3->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MaximizeBox;
			this->guna2ControlBox3->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox3->HoverState->Parent = this->guna2ControlBox3;
			this->guna2ControlBox3->IconColor = System::Drawing::Color::Black;
			this->guna2ControlBox3->Location = System::Drawing::Point(1838, 3);
			this->guna2ControlBox3->Name = L"guna2ControlBox3";
			this->guna2ControlBox3->ShadowDecoration->Parent = this->guna2ControlBox3;
			this->guna2ControlBox3->Size = System::Drawing::Size(31, 29);
			this->guna2ControlBox3->TabIndex = 27;
			this->guna2ControlBox3->UseTransparentBackground = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 158);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1894, 902);
			this->dataGridView1->TabIndex = 28;
			// 
			// dataSelectBox
			// 
			this->dataSelectBox->Animated = true;
			this->dataSelectBox->BackColor = System::Drawing::Color::Transparent;
			this->dataSelectBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->dataSelectBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->dataSelectBox->FocusedColor = System::Drawing::Color::Empty;
			this->dataSelectBox->FocusedState->Parent = this->dataSelectBox;
			this->dataSelectBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->dataSelectBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)));
			this->dataSelectBox->FormattingEnabled = true;
			this->dataSelectBox->HoverState->Parent = this->dataSelectBox;
			this->dataSelectBox->ItemHeight = 25;
			this->dataSelectBox->ItemsAppearance->Parent = this->dataSelectBox;
			this->dataSelectBox->Location = System::Drawing::Point(176, 58);
			this->dataSelectBox->Name = L"dataSelectBox";
			this->dataSelectBox->ShadowDecoration->Parent = this->dataSelectBox;
			this->dataSelectBox->Size = System::Drawing::Size(306, 31);
			this->dataSelectBox->TabIndex = 29;
			this->dataSelectBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm2::dataSelectBox_SelectedIndexChanged);
			// 
			// SaveBtn
			// 
			this->SaveBtn->Animated = true;
			this->SaveBtn->BorderRadius = 10;
			this->SaveBtn->CheckedState->Parent = this->SaveBtn;
			this->SaveBtn->CustomImages->Parent = this->SaveBtn;
			this->SaveBtn->Enabled = false;
			this->SaveBtn->FillColor = System::Drawing::Color::LightGreen;
			this->SaveBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->SaveBtn->ForeColor = System::Drawing::Color::Black;
			this->SaveBtn->HoverState->Parent = this->SaveBtn;
			this->SaveBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SaveBtn.Image")));
			this->SaveBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->SaveBtn->Location = System::Drawing::Point(1529, 107);
			this->SaveBtn->Name = L"SaveBtn";
			this->SaveBtn->ShadowDecoration->Parent = this->SaveBtn;
			this->SaveBtn->Size = System::Drawing::Size(120, 45);
			this->SaveBtn->TabIndex = 30;
			this->SaveBtn->Text = L"Save Changes";
			this->SaveBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->SaveBtn->Click += gcnew System::EventHandler(this, &MainForm2::SaveBtn_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm2::timer1_Tick);
			// 
			// labelTime
			// 
			this->labelTime->AutoSize = true;
			this->labelTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTime->Location = System::Drawing::Point(1761, 44);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(57, 20);
			this->labelTime->TabIndex = 31;
			this->labelTime->Text = L"Time: ";
			// 
			// labelDate
			// 
			this->labelDate->AutoSize = true;
			this->labelDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDate->Location = System::Drawing::Point(1762, 69);
			this->labelDate->Name = L"labelDate";
			this->labelDate->Size = System::Drawing::Size(58, 20);
			this->labelDate->TabIndex = 32;
			this->labelDate->Text = L"Date: ";
			// 
			// tableSelectBox
			// 
			this->tableSelectBox->Animated = true;
			this->tableSelectBox->BackColor = System::Drawing::Color::Transparent;
			this->tableSelectBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->tableSelectBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->tableSelectBox->Enabled = false;
			this->tableSelectBox->FocusedColor = System::Drawing::Color::Empty;
			this->tableSelectBox->FocusedState->Parent = this->tableSelectBox;
			this->tableSelectBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->tableSelectBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(68)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)));
			this->tableSelectBox->FormattingEnabled = true;
			this->tableSelectBox->HoverState->Parent = this->tableSelectBox;
			this->tableSelectBox->ItemHeight = 25;
			this->tableSelectBox->ItemsAppearance->Parent = this->tableSelectBox;
			this->tableSelectBox->Location = System::Drawing::Point(488, 58);
			this->tableSelectBox->Name = L"tableSelectBox";
			this->tableSelectBox->ShadowDecoration->Parent = this->tableSelectBox;
			this->tableSelectBox->Size = System::Drawing::Size(297, 31);
			this->tableSelectBox->TabIndex = 33;
			this->tableSelectBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm2::tableSelectBox_SelectedIndexChanged);
			// 
			// DeleteBtn
			// 
			this->DeleteBtn->Animated = true;
			this->DeleteBtn->BorderRadius = 10;
			this->DeleteBtn->CheckedState->Parent = this->DeleteBtn;
			this->DeleteBtn->CustomImages->Parent = this->DeleteBtn;
			this->DeleteBtn->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->DeleteBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->DeleteBtn->ForeColor = System::Drawing::Color::White;
			this->DeleteBtn->HoverState->Parent = this->DeleteBtn;
			this->DeleteBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteBtn.Image")));
			this->DeleteBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->DeleteBtn->Location = System::Drawing::Point(1403, 107);
			this->DeleteBtn->Name = L"DeleteBtn";
			this->DeleteBtn->ShadowDecoration->Parent = this->DeleteBtn;
			this->DeleteBtn->Size = System::Drawing::Size(120, 45);
			this->DeleteBtn->TabIndex = 34;
			this->DeleteBtn->Text = L"Delete Item";
			this->DeleteBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->DeleteBtn->Click += gcnew System::EventHandler(this, &MainForm2::DeleteBtn_Click);
			// 
			// AddTBBtn
			// 
			this->AddTBBtn->BackColor = System::Drawing::Color::Transparent;
			this->AddTBBtn->BorderRadius = 7;
			this->AddTBBtn->CheckedState->Parent = this->AddTBBtn;
			this->AddTBBtn->CustomImages->Parent = this->AddTBBtn;
			this->AddTBBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->AddTBBtn->ForeColor = System::Drawing::Color::White;
			this->AddTBBtn->HoverState->Parent = this->AddTBBtn;
			this->AddTBBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddTBBtn.Image")));
			this->AddTBBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->AddTBBtn->Location = System::Drawing::Point(488, 95);
			this->AddTBBtn->Name = L"AddTBBtn";
			this->AddTBBtn->ShadowDecoration->Parent = this->AddTBBtn;
			this->AddTBBtn->Size = System::Drawing::Size(144, 38);
			this->AddTBBtn->TabIndex = 37;
			this->AddTBBtn->Text = L"Add Table";
			this->AddTBBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->AddTBBtn->Click += gcnew System::EventHandler(this, &MainForm2::AddTBBtn_Click);
			// 
			// DelTBBtn
			// 
			this->DelTBBtn->BorderRadius = 7;
			this->DelTBBtn->CheckedState->Parent = this->DelTBBtn;
			this->DelTBBtn->CustomImages->Parent = this->DelTBBtn;
			this->DelTBBtn->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->DelTBBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->DelTBBtn->ForeColor = System::Drawing::Color::White;
			this->DelTBBtn->HoverState->Parent = this->DelTBBtn;
			this->DelTBBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DelTBBtn.Image")));
			this->DelTBBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->DelTBBtn->Location = System::Drawing::Point(641, 95);
			this->DelTBBtn->Name = L"DelTBBtn";
			this->DelTBBtn->ShadowDecoration->Parent = this->DelTBBtn;
			this->DelTBBtn->Size = System::Drawing::Size(144, 38);
			this->DelTBBtn->TabIndex = 38;
			this->DelTBBtn->Text = L"Delete Table";
			this->DelTBBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->DelTBBtn->Click += gcnew System::EventHandler(this, &MainForm2::DelTBBtn_Click);
			// 
			// MainForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1918, 1072);
			this->Controls->Add(this->DelTBBtn);
			this->Controls->Add(this->AddTBBtn);
			this->Controls->Add(this->DeleteBtn);
			this->Controls->Add(this->tableSelectBox);
			this->Controls->Add(this->labelDate);
			this->Controls->Add(this->labelTime);
			this->Controls->Add(this->SaveBtn);
			this->Controls->Add(this->dataSelectBox);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->guna2ControlBox3);
			this->Controls->Add(this->guna2ControlBox2);
			this->Controls->Add(this->guna2ControlBox1);
			this->Controls->Add(this->ConnectBtn);
			this->Controls->Add(this->LogOutBtn);
			this->Controls->Add(this->RefBtn);
			this->Controls->Add(this->AddBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->guna2PictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// Load Data Table When Saving and Adding
		void InventorySystem::MainForm2::LoadTableData() {
			if (tableSelectBox->SelectedIndex == -1) return; // Ensure a table is selected

			String^ selectedDB = dataSelectBox->SelectedItem->ToString();
			String^ selectedTable = tableSelectBox->SelectedItem->ToString();
			String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;";

			try {
				SqlConnection^ sqlConn = gcnew SqlConnection(connString);
				sqlConn->Open();

				String^ query = "SELECT * FROM [" + selectedTable + "]"; // Fetch all data from the table
				SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, sqlConn);
				DataTable^ dt = gcnew DataTable();
				adapter->Fill(dt);

				dataGridView1->DataSource = dt; // Set data source to DataGridView
				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading table: " + ex->Message, "Load Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		// Delete Empty Rows
		void InventorySystem::MainForm2::DeleteEmptyRows() {
			if (tableSelectBox->SelectedIndex == -1) return; // Ensure a table is selected

			String^ selectedDB = dataSelectBox->SelectedItem->ToString();
			String^ selectedTable = tableSelectBox->SelectedItem->ToString();
			String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=" + selectedDB + ";Integrated Security=True;";

			try {
				SqlConnection^ sqlConn = gcnew SqlConnection(connString);
				sqlConn->Open();

				// Construct DELETE query to remove empty rows
				String^ deleteQuery = "DELETE FROM [" + selectedTable + "] WHERE ";

				// Dynamically build a condition for each column (assuming columns are non-nullable)
				String^ getColumnQuery = "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '" + selectedTable + "'";
				SqlCommand^ getColumnCmd = gcnew SqlCommand(getColumnQuery, sqlConn);
				SqlDataReader^ reader = getColumnCmd->ExecuteReader();

				List<String^>^ conditions = gcnew List<String^>();

				while (reader->Read()) {
					String^ colName = reader["COLUMN_NAME"]->ToString();
					conditions->Add("[" + colName + "] IS NULL OR [" + colName + "] = ''");
				}
				reader->Close();

				if (conditions->Count > 0) {
					deleteQuery += "(" + String::Join(" AND ", conditions) + ")";
					SqlCommand^ deleteCmd = gcnew SqlCommand(deleteQuery, sqlConn);
					int rowsAffected = deleteCmd->ExecuteNonQuery();

					if (rowsAffected > 0) {
						MessageBox::Show(rowsAffected + " empty rows were deleted.", "Rows Deleted", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
				}

				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error deleting empty rows: " + ex->Message, "Delete Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

#pragma endregion
		//on cpp
	void LogOutBtn_Click(System::Object^ sender, System::EventArgs^ e);
	void ConnectBtn_Click(System::Object^ sender, System::EventArgs^ e);
	void dataSelectBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	void tableSelectBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	void SaveBtn_Click(System::Object^ sender, System::EventArgs^ e);
	void AddBtn_Click(System::Object^ sender, System::EventArgs^ e);
	void DeleteBtn_Click(System::Object^ sender, System::EventArgs^ e);
	void RefBtn_Click(System::Object^ sender, System::EventArgs^ e);
	void AddTBBtn_Click(System::Object^ sender, System::EventArgs^ e);
	void DelTBBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
