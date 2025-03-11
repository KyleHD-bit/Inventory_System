//DBCC CHECKIDENT ('items', RESEED, 1); -SQL COMMAND TO RESET IDENTITY TO SPECIFIC VALUE! (OPEN NEW QUERY)

#pragma once



#include "User.h"
#include "LoginForm1.h"

//#include "AddForm.h"

namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;
	using namespace System::Data::SqlClient;


	//using namespace System::

	/// <summary>
	/// Summary for MainForm
	/// </summary>

	//ref class AddForm; //-

	public ref class MainForm : public System::Windows::Forms::Form
	{


	public:
		DataGridView^ dataGridView1;
		//MainForm(void) -default
		//MainForm(User ^user) -to use User.h & link to program.cpp


	public: //added so it can be accesed from program.cpp
		MainForm(User^ user)
		{
			// Fit Screen
			System::Drawing::Rectangle workingArea = Screen::PrimaryScreen->WorkingArea;
			this->Bounds = workingArea;
			this->Width = workingArea.Width;
			this->Height = workingArea.Height;
			this->Location = Point(workingArea.X, workingArea.Y);


			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

		//property DataGridView^ InventoryDataGridView //-
		//{
		//	DataGridView^ get()
		//	{
		//		return dataGridView1;
		//	}
		//}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelDate;
	private: System::Windows::Forms::Label^ labelTime;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ filterButton;
	private: System::Windows::Forms::TextBox^ textBoxFilter;
	private: System::Windows::Forms::ComboBox^ comboBoxColumn;
	 //print objects
	private: System::Drawing::Printing::PrintDocument^ printDocument;
	private: System::Windows::Forms::PrintPreviewDialog^ printPreviewDialog;
	private: System::Windows::Forms::PrintDialog^ printDialog;
	private: Guna::UI2::WinForms::Guna2Button^ gAddBtn;
	private: Guna::UI2::WinForms::Guna2Button^ gRefBtn;
	private: Guna::UI2::WinForms::Guna2Button^ gEditBtn;
	private: Guna::UI2::WinForms::Guna2Button^ gDelBtn;
	private: Guna::UI2::WinForms::Guna2Button^ gPrintBtn;
	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: DataTable^ printDataTable;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button1;
	private: Guna::UI2::WinForms::Guna2Button^ gPrintICS;
	private: System::ComponentModel::IContainer^ components;



		   //private: System::Windows::Forms::DataGridView^ dataGridView1;
 //iContainer^

	//
	// article

	protected:

	protected:

	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->gPrintICS = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->guna2PictureBox1 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->labelDate = (gcnew System::Windows::Forms::Label());
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->gPrintBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->gRefBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->gEditBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->gDelBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->gAddBtn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->comboBoxColumn = (gcnew System::Windows::Forms::ComboBox());
			this->filterButton = (gcnew System::Windows::Forms::Button());
			this->textBoxFilter = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->printDocument = (gcnew System::Drawing::Printing::PrintDocument());
			this->printPreviewDialog = (gcnew System::Windows::Forms::PrintPreviewDialog());
			this->printDialog = (gcnew System::Windows::Forms::PrintDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->Location = System::Drawing::Point(287, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1603, 1009);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->ColumnHeaderMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::dataGridView1_ColumnHeaderMouseClick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::SkyBlue;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->gPrintICS);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->guna2PictureBox1);
			this->panel1->Controls->Add(this->labelDate);
			this->panel1->Controls->Add(this->labelTime);
			this->panel1->Controls->Add(this->gPrintBtn);
			this->panel1->Controls->Add(this->gRefBtn);
			this->panel1->Controls->Add(this->gEditBtn);
			this->panel1->Controls->Add(this->gDelBtn);
			this->panel1->Controls->Add(this->gAddBtn);
			this->panel1->Controls->Add(this->comboBoxColumn);
			this->panel1->Controls->Add(this->filterButton);
			this->panel1->Controls->Add(this->textBoxFilter);
			this->panel1->Location = System::Drawing::Point(19, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(262, 1009);
			this->panel1->TabIndex = 4;
			// 
			// gPrintICS
			// 
			this->gPrintICS->Animated = true;
			this->gPrintICS->CheckedState->Parent = this->gPrintICS;
			this->gPrintICS->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gPrintICS->CustomImages->Parent = this->gPrintICS;
			this->gPrintICS->FillColor = System::Drawing::Color::SkyBlue;
			this->gPrintICS->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->gPrintICS->ForeColor = System::Drawing::Color::Black;
			this->gPrintICS->HoverState->Parent = this->gPrintICS;
			this->gPrintICS->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gPrintICS.Image")));
			this->gPrintICS->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gPrintICS->Location = System::Drawing::Point(0, 560);
			this->gPrintICS->Name = L"gPrintICS";
			this->gPrintICS->ShadowDecoration->Parent = this->gPrintICS;
			this->gPrintICS->Size = System::Drawing::Size(261, 45);
			this->gPrintICS->TabIndex = 20;
			this->gPrintICS->Text = L"Print ICS";
			this->gPrintICS->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gPrintICS->Click += gcnew System::EventHandler(this, &MainForm::gPrintICS_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(43, 224);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 23);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Inventory System";
			// 
			// guna2PictureBox1
			// 
			this->guna2PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox1.Image")));
			this->guna2PictureBox1->Location = System::Drawing::Point(-1, 5);
			this->guna2PictureBox1->Name = L"guna2PictureBox1";
			this->guna2PictureBox1->ShadowDecoration->Parent = this->guna2PictureBox1;
			this->guna2PictureBox1->Size = System::Drawing::Size(262, 233);
			this->guna2PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->guna2PictureBox1->TabIndex = 18;
			this->guna2PictureBox1->TabStop = false;
			// 
			// labelDate
			// 
			this->labelDate->AutoSize = true;
			this->labelDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelDate->Location = System::Drawing::Point(4, 853);
			this->labelDate->Name = L"labelDate";
			this->labelDate->Size = System::Drawing::Size(74, 29);
			this->labelDate->TabIndex = 6;
			this->labelDate->Text = L"Date:";
			this->labelDate->Visible = false;
			// 
			// labelTime
			// 
			this->labelTime->AutoSize = true;
			this->labelTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTime->Location = System::Drawing::Point(4, 882);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(80, 29);
			this->labelTime->TabIndex = 7;
			this->labelTime->Text = L"Time:";
			this->labelTime->Visible = false;
			// 
			// gPrintBtn
			// 
			this->gPrintBtn->Animated = true;
			this->gPrintBtn->CheckedState->Parent = this->gPrintBtn;
			this->gPrintBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gPrintBtn->CustomImages->Parent = this->gPrintBtn;
			this->gPrintBtn->FillColor = System::Drawing::Color::SkyBlue;
			this->gPrintBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->gPrintBtn->ForeColor = System::Drawing::Color::Black;
			this->gPrintBtn->HoverState->Parent = this->gPrintBtn;
			this->gPrintBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gPrintBtn.Image")));
			this->gPrintBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gPrintBtn->Location = System::Drawing::Point(0, 510);
			this->gPrintBtn->Name = L"gPrintBtn";
			this->gPrintBtn->ShadowDecoration->Parent = this->gPrintBtn;
			this->gPrintBtn->Size = System::Drawing::Size(262, 45);
			this->gPrintBtn->TabIndex = 17;
			this->gPrintBtn->Text = L"Print";
			this->gPrintBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gPrintBtn->Click += gcnew System::EventHandler(this, &MainForm::gPrintBtn_Click);
			// 
			// gRefBtn
			// 
			this->gRefBtn->Animated = true;
			this->gRefBtn->CheckedState->Parent = this->gRefBtn;
			this->gRefBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gRefBtn->CustomImages->Parent = this->gRefBtn;
			this->gRefBtn->FillColor = System::Drawing::Color::SkyBlue;
			this->gRefBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->gRefBtn->ForeColor = System::Drawing::Color::Black;
			this->gRefBtn->HoverState->Parent = this->gRefBtn;
			this->gRefBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gRefBtn.Image")));
			this->gRefBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gRefBtn->Location = System::Drawing::Point(-1, 459);
			this->gRefBtn->Name = L"gRefBtn";
			this->gRefBtn->ShadowDecoration->Parent = this->gRefBtn;
			this->gRefBtn->Size = System::Drawing::Size(262, 45);
			this->gRefBtn->TabIndex = 16;
			this->gRefBtn->Text = L"Refresh Data";
			this->gRefBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gRefBtn->Click += gcnew System::EventHandler(this, &MainForm::gRefBtn_Click);
			// 
			// gEditBtn
			// 
			this->gEditBtn->Animated = true;
			this->gEditBtn->CheckedState->Parent = this->gEditBtn;
			this->gEditBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gEditBtn->CustomImages->Parent = this->gEditBtn;
			this->gEditBtn->FillColor = System::Drawing::Color::SkyBlue;
			this->gEditBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->gEditBtn->ForeColor = System::Drawing::Color::Black;
			this->gEditBtn->HoverState->Parent = this->gEditBtn;
			this->gEditBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gEditBtn.Image")));
			this->gEditBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gEditBtn->Location = System::Drawing::Point(0, 408);
			this->gEditBtn->Name = L"gEditBtn";
			this->gEditBtn->ShadowDecoration->Parent = this->gEditBtn;
			this->gEditBtn->Size = System::Drawing::Size(262, 45);
			this->gEditBtn->TabIndex = 15;
			this->gEditBtn->Text = L"Edit Item";
			this->gEditBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gEditBtn->Click += gcnew System::EventHandler(this, &MainForm::gEditBtn_Click);
			// 
			// gDelBtn
			// 
			this->gDelBtn->Animated = true;
			this->gDelBtn->CheckedState->Parent = this->gDelBtn;
			this->gDelBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gDelBtn->CustomImages->Parent = this->gDelBtn;
			this->gDelBtn->FillColor = System::Drawing::Color::SkyBlue;
			this->gDelBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->gDelBtn->ForeColor = System::Drawing::Color::Black;
			this->gDelBtn->HoverState->Parent = this->gDelBtn;
			this->gDelBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gDelBtn.Image")));
			this->gDelBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gDelBtn->Location = System::Drawing::Point(-1, 357);
			this->gDelBtn->Name = L"gDelBtn";
			this->gDelBtn->ShadowDecoration->Parent = this->gDelBtn;
			this->gDelBtn->Size = System::Drawing::Size(262, 45);
			this->gDelBtn->TabIndex = 14;
			this->gDelBtn->Text = L"Delete Item";
			this->gDelBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gDelBtn->Click += gcnew System::EventHandler(this, &MainForm::gDelBtn_Click);
			// 
			// gAddBtn
			// 
			this->gAddBtn->Animated = true;
			this->gAddBtn->CheckedState->Parent = this->gAddBtn;
			this->gAddBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gAddBtn->CustomImages->Parent = this->gAddBtn;
			this->gAddBtn->FillColor = System::Drawing::Color::SkyBlue;
			this->gAddBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->gAddBtn->ForeColor = System::Drawing::Color::Black;
			this->gAddBtn->HoverState->Parent = this->gAddBtn;
			this->gAddBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gAddBtn.Image")));
			this->gAddBtn->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gAddBtn->Location = System::Drawing::Point(0, 306);
			this->gAddBtn->Name = L"gAddBtn";
			this->gAddBtn->ShadowDecoration->Parent = this->gAddBtn;
			this->gAddBtn->Size = System::Drawing::Size(262, 45);
			this->gAddBtn->TabIndex = 13;
			this->gAddBtn->Text = L"Add Item";
			this->gAddBtn->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->gAddBtn->Click += gcnew System::EventHandler(this, &MainForm::gAddBtn_Click);
			// 
			// comboBoxColumn
			// 
			this->comboBoxColumn->FormattingEnabled = true;
			this->comboBoxColumn->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"Article", L"Description", L"Property Number",
					L"Date Aquired", L"Unit of Measure", L"Unit of Value", L"Acctble Officer", L"Location", L"Balance Per Qty", L"Onhand Per Qty",
					L"Quantity", L"Value", L"Remarks"
			});
			this->comboBoxColumn->Location = System::Drawing::Point(9, 925);
			this->comboBoxColumn->Name = L"comboBoxColumn";
			this->comboBoxColumn->Size = System::Drawing::Size(121, 21);
			this->comboBoxColumn->TabIndex = 11;
			// 
			// filterButton
			// 
			this->filterButton->Location = System::Drawing::Point(150, 932);
			this->filterButton->Name = L"filterButton";
			this->filterButton->Size = System::Drawing::Size(75, 23);
			this->filterButton->TabIndex = 10;
			this->filterButton->Text = L"Filter";
			this->filterButton->UseVisualStyleBackColor = true;
			this->filterButton->Click += gcnew System::EventHandler(this, &MainForm::filterButton_Click);
			// 
			// textBoxFilter
			// 
			this->textBoxFilter->Location = System::Drawing::Point(9, 951);
			this->textBoxFilter->Name = L"textBoxFilter";
			this->textBoxFilter->Size = System::Drawing::Size(121, 20);
			this->textBoxFilter->TabIndex = 9;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// printPreviewDialog
			// 
			this->printPreviewDialog->AutoScrollMargin = System::Drawing::Size(0, 0);
			this->printPreviewDialog->AutoScrollMinSize = System::Drawing::Size(0, 0);
			this->printPreviewDialog->ClientSize = System::Drawing::Size(1280, 720);
			this->printPreviewDialog->Enabled = true;
			this->printPreviewDialog->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"printPreviewDialog.Icon")));
			this->printPreviewDialog->Name = L"printPreviewDialog";
			this->printPreviewDialog->Visible = false;
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Municipality of Buenavista | Inventory System";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->EndInit();
			this->ResumeLayout(false);

		}

		//added
		/*void LoadData()
		{
			String^ connectionString = "your_connection_string_here";
			SqlConnection^ connection = gcnew SqlConnection(connectionString);
			SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM YourTable", connection);
			DataTable^ dataTable = gcnew DataTable();

			try
			{
				connection->Open();
				dataAdapter->Fill(dataTable);
				dataGridView1->DataSource = dataTable;
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
			} */


			/*public ref class MyForm : public Form
	{
	private:
		DataGridView^ dataGridView;

	public:
		MyForm()
		{
			InitializeComponent();
			LoadData();
		}

	private:
		void InitializeComponent()
		{
			this->dataGridView = gcnew DataGridView();
			this->dataGridView->Dock = DockStyle::Fill;
			this->Controls->Add(this->dataGridView);
			this->Text = "DataGridView Example";
		}

		void LoadData()
		{
			String^ connectionString = "your_connection_string_here";
			SqlConnection^ connection = gcnew SqlConnection(connectionString);
			SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM YourTable", connection);
			DataTable^ dataTable = gcnew DataTable();

			try
			{
				connection->Open();
				dataAdapter->Fill(dataTable);
				dataGridView->DataSource = dataTable;
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
	};
	*/

		void InventorySystem::MainForm::dataGridView1_ColumnHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e){
			AdjustRowHeightForDescriptionColumn();
		}


	public: System::Void AdjustRowHeightForDescriptionColumn()
	{
		// Ensure the column exists
		if (!dataGridView1->Columns->Contains("Description"))
		{
			MessageBox::Show("Description column not found.");
			return;
		}

		// Get the index of the "Description" column
		int descriptionColumnIndex = dataGridView1->Columns["Description"]->Index;
		int IDColumnIndex = dataGridView1->Columns["ID"]->Index;

		// Iterate through each row
		for (int i = 0; i < dataGridView1->Rows->Count; i++)
		{
			// Check if the cell value is not null
			if (dataGridView1->Rows[i]->Cells[descriptionColumnIndex]->Value != nullptr)
			{
				// Get the content of the "Description" column
				String^ descriptionContent = dataGridView1->Rows[i]->Cells[descriptionColumnIndex]->Value->ToString();

				// Calculate the desired height based on the content
				int desiredHeight = 50; // Default height

				if (!String::IsNullOrEmpty(descriptionContent))
				{
					// Calculate number of lines based on line breaks
					int numberOfLines = descriptionContent->Split(gcnew array<wchar_t>{'\n'}, StringSplitOptions::None)->Length;
					desiredHeight = 24 + (numberOfLines - 1) * 18; // Adjust multiplier as needed
				}

				// Set the row height
				dataGridView1->Rows[i]->Height = 80;
				dataGridView1->Columns[descriptionColumnIndex]->Width = 350;
				dataGridView1->Columns[IDColumnIndex]->Width = 25;
			}
		}
	}

	public: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		DateTime now = DateTime::Now;

		//labelDate->Text = "Date: " + now.ToString("yyyy-MM-dd");
		//labelTime->Text = "Time: " + now.ToString("HH:mm:ss tt");
		labelDate->Text = now.ToString("MMMM, dd yyyy");
		labelTime->Text = now.ToString("hh:mm:ss tt");

	}



	public: void RefreshData() {
		String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;"; //localhost
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM items", connection);
		DataTable^ dataTable = gcnew DataTable();

		try {
			connection->Open();
			dataAdapter->Fill(dataTable);
			dataGridView1->DataSource = dataTable;
			AdjustRowHeightForDescriptionColumn();
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

//########################################################################################################################################################

//########################################################################################################################################################


#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter("SELECT * FROM items", connection);
		DataTable^ dataTable = gcnew DataTable();
		dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::SkyBlue;
		dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
		dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Bold);

		try
		{
			connection->Open();
			dataAdapter->Fill(dataTable);
			dataGridView1->DataSource = dataTable;
			dataGridView1->Columns["Unit of Value"]->DefaultCellStyle->Format = "N2"; // add , in Value Number
			AdjustRowHeightForDescriptionColumn();
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


//########################################################################################################################################################

//########################################################################################################################################################



//on cpp
void button1_Click(System::Object^ sender, System::EventArgs^ e);
void button2_Click(System::Object^ sender, System::EventArgs^ e);
void button3_Click(System::Object^ sender, System::EventArgs^ e);
void button4_Click(System::Object^ sender, System::EventArgs^ e);
void filterButton_Click(System::Object^ sender, System::EventArgs^ e);
void printButton_Click(System::Object^ sender, System::EventArgs^ e);
void printDocument_PrintPage(System::Object ^ sender, System::Drawing::Printing::PrintPageEventArgs ^ e);
void gAddBtn_Click(System::Object^ sender, System::EventArgs^ e);
void gDelBtn_Click(System::Object^ sender, System::EventArgs^ e);
void gEditBtn_Click(System::Object^ sender, System::EventArgs^ e);
void gRefBtn_Click(System::Object^ sender, System::EventArgs^ e);
void gPrintBtn_Click(System::Object^ sender, System::EventArgs^ e);
void gPrintICS_Click(System::Object^ sender, System::EventArgs^ e);
};
}
