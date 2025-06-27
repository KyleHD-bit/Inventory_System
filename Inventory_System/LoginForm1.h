#pragma once
#include "User.h"
#include "NotificationForm.h"
#include "MainForm2.h"

namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for LoginForm1
	/// </summary>
	public ref class LoginForm1 : public System::Windows::Forms::Form
	{
	public:
		LoginForm1(void)
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
		~LoginForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox1;
	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox2;
	private: Guna::UI2::WinForms::Guna2GradientButton^ btnLogin2;
	private: Guna::UI2::WinForms::Guna2GradientButton^ btnCancel2;
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;
	private: System::Windows::Forms::Label^ label1;
	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox1;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox1;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox2;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: System::Windows::Forms::Label^ label2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm1::typeid));
			this->guna2TextBox1 = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2TextBox2 = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->btnLogin2 = (gcnew Guna::UI2::WinForms::Guna2GradientButton());
			this->btnCancel2 = (gcnew Guna::UI2::WinForms::Guna2GradientButton());
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->guna2PictureBox1 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->guna2ControlBox1 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2ControlBox2 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->BeginInit();
			this->guna2Panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// guna2TextBox1
			// 
			this->guna2TextBox1->BorderRadius = 15;
			this->guna2TextBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox1->DefaultText = L"";
			this->guna2TextBox1->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox1->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox1->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox1->DisabledState->Parent = this->guna2TextBox1;
			this->guna2TextBox1->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox1->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox1->FocusedState->Parent = this->guna2TextBox1;
			this->guna2TextBox1->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox1->HoverState->Parent = this->guna2TextBox1;
			this->guna2TextBox1->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox1.IconLeft")));
			this->guna2TextBox1->Location = System::Drawing::Point(347, 81);
			this->guna2TextBox1->Margin = System::Windows::Forms::Padding(4);
			this->guna2TextBox1->Name = L"guna2TextBox1";
			this->guna2TextBox1->PasswordChar = '\0';
			this->guna2TextBox1->PlaceholderText = L"Username";
			this->guna2TextBox1->SelectedText = L"";
			this->guna2TextBox1->ShadowDecoration->Parent = this->guna2TextBox1;
			this->guna2TextBox1->Size = System::Drawing::Size(276, 52);
			this->guna2TextBox1->TabIndex = 6;
			// 
			// guna2TextBox2
			// 
			this->guna2TextBox2->BorderRadius = 15;
			this->guna2TextBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox2->DefaultText = L"";
			this->guna2TextBox2->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox2->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox2->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox2->DisabledState->Parent = this->guna2TextBox2;
			this->guna2TextBox2->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox2->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox2->FocusedState->Parent = this->guna2TextBox2;
			this->guna2TextBox2->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox2->HoverState->Parent = this->guna2TextBox2;
			this->guna2TextBox2->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox2.IconLeft")));
			this->guna2TextBox2->Location = System::Drawing::Point(347, 160);
			this->guna2TextBox2->Margin = System::Windows::Forms::Padding(4);
			this->guna2TextBox2->Name = L"guna2TextBox2";
			this->guna2TextBox2->PasswordChar = '\0';
			this->guna2TextBox2->PlaceholderText = L"Password";
			this->guna2TextBox2->SelectedText = L"";
			this->guna2TextBox2->ShadowDecoration->Parent = this->guna2TextBox2;
			this->guna2TextBox2->Size = System::Drawing::Size(276, 52);
			this->guna2TextBox2->TabIndex = 7;
			this->guna2TextBox2->UseSystemPasswordChar = true;
			// 
			// btnLogin2
			// 
			this->btnLogin2->Animated = true;
			this->btnLogin2->AutoRoundedCorners = true;
			this->btnLogin2->BorderRadius = 18;
			this->btnLogin2->CheckedState->Parent = this->btnLogin2;
			this->btnLogin2->CustomImages->Parent = this->btnLogin2;
			this->btnLogin2->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnLogin2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnLogin2->ForeColor = System::Drawing::Color::White;
			this->btnLogin2->HoverState->Parent = this->btnLogin2;
			this->btnLogin2->Location = System::Drawing::Point(381, 231);
			this->btnLogin2->Name = L"btnLogin2";
			this->btnLogin2->ShadowDecoration->Parent = this->btnLogin2;
			this->btnLogin2->Size = System::Drawing::Size(100, 38);
			this->btnLogin2->TabIndex = 8;
			this->btnLogin2->Text = L"LOGIN";
			this->btnLogin2->Click += gcnew System::EventHandler(this, &LoginForm1::btnLogin2_Click);
			// 
			// btnCancel2
			// 
			this->btnCancel2->Animated = true;
			this->btnCancel2->AutoRoundedCorners = true;
			this->btnCancel2->BorderRadius = 18;
			this->btnCancel2->CheckedState->Parent = this->btnCancel2;
			this->btnCancel2->CustomImages->Parent = this->btnCancel2;
			this->btnCancel2->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->btnCancel2->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->btnCancel2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnCancel2->ForeColor = System::Drawing::Color::White;
			this->btnCancel2->HoverState->Parent = this->btnCancel2;
			this->btnCancel2->Location = System::Drawing::Point(495, 231);
			this->btnCancel2->Name = L"btnCancel2";
			this->btnCancel2->ShadowDecoration->Parent = this->btnCancel2;
			this->btnCancel2->Size = System::Drawing::Size(100, 38);
			this->btnCancel2->TabIndex = 9;
			this->btnCancel2->Text = L"Cancel";
			this->btnCancel2->Click += gcnew System::EventHandler(this, &LoginForm1::btnCancel2_Click);
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->BorderRadius = 20;
			this->guna2Elipse1->TargetControl = this;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label1->Location = System::Drawing::Point(416, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 25);
			this->label1->TabIndex = 10;
			this->label1->Text = L"User Login ";
			// 
			// guna2PictureBox1
			// 
			this->guna2PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox1.Image")));
			this->guna2PictureBox1->Location = System::Drawing::Point(20, 48);
			this->guna2PictureBox1->Name = L"guna2PictureBox1";
			this->guna2PictureBox1->ShadowDecoration->Parent = this->guna2PictureBox1;
			this->guna2PictureBox1->Size = System::Drawing::Size(295, 270);
			this->guna2PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->guna2PictureBox1->TabIndex = 11;
			this->guna2PictureBox1->TabStop = false;
			// 
			// guna2ControlBox1
			// 
			this->guna2ControlBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox1->BackColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->BorderColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->HoverState->Parent = this->guna2ControlBox1;
			this->guna2ControlBox1->IconColor = System::Drawing::Color::DimGray;
			this->guna2ControlBox1->Location = System::Drawing::Point(606, 12);
			this->guna2ControlBox1->Name = L"guna2ControlBox1";
			this->guna2ControlBox1->ShadowDecoration->Parent = this->guna2ControlBox1;
			this->guna2ControlBox1->Size = System::Drawing::Size(29, 29);
			this->guna2ControlBox1->TabIndex = 12;
			// 
			// guna2ControlBox2
			// 
			this->guna2ControlBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox2->BackColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->BorderColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MinimizeBox;
			this->guna2ControlBox2->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->HoverState->Parent = this->guna2ControlBox2;
			this->guna2ControlBox2->IconColor = System::Drawing::Color::DimGray;
			this->guna2ControlBox2->Location = System::Drawing::Point(571, 12);
			this->guna2ControlBox2->Name = L"guna2ControlBox2";
			this->guna2ControlBox2->ShadowDecoration->Parent = this->guna2ControlBox2;
			this->guna2ControlBox2->Size = System::Drawing::Size(29, 29);
			this->guna2ControlBox2->TabIndex = 13;
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->BackColor = System::Drawing::Color::Blue;
			this->guna2Panel1->BorderColor = System::Drawing::Color::Transparent;
			this->guna2Panel1->Controls->Add(this->label2);
			this->guna2Panel1->Controls->Add(this->guna2PictureBox1);
			this->guna2Panel1->Location = System::Drawing::Point(-8, -2);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->ShadowDecoration->Parent = this->guna2Panel1;
			this->guna2Panel1->Size = System::Drawing::Size(349, 337);
			this->guna2Panel1->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::AliceBlue;
			this->label2->Location = System::Drawing::Point(123, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 33);
			this->label2->TabIndex = 21;
			this->label2->Text = L"InvSys";
			// 
			// LoginForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(647, 328);
			this->Controls->Add(this->guna2Panel1);
			this->Controls->Add(this->guna2ControlBox2);
			this->Controls->Add(this->guna2ControlBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCancel2);
			this->Controls->Add(this->btnLogin2);
			this->Controls->Add(this->guna2TextBox2);
			this->Controls->Add(this->guna2TextBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"LoginForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Municipality of Buenavista | Login";
			this->Shown += gcnew System::EventHandler(this, &LoginForm1::LoginForm1_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->EndInit();
			this->guna2Panel1->ResumeLayout(false);
			this->guna2Panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: User^ user = nullptr;

	// Load on User TB
	private: System::Void LoginForm1_Shown(System::Object^ sender, System::EventArgs^ e) {
		this->guna2TextBox1->Focus();
		}

	private: System::Void btnLogin2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->guna2TextBox1->Text;
		String^ password = this->guna2TextBox2->Text;

		if (username->Length == 0 || password->Length == 0) {
			MessageBox::Show("Please enter user and password",
				"User or Password is Empty", MessageBoxButtons::OK);
			return;
		}

		try {
			String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Inventory_System;Integrated Security=True;";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "SELECT * FROM users WHERE username=@user AND password=@pwd;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@user", username);
			command.Parameters->AddWithValue("@pwd", password);

			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {
				user = gcnew User;
				user->id = reader->GetInt32(0);
				user->username = reader->GetString(1);
				user->password = reader->GetString(2);

				NotificationForm^ notifyForm = gcnew NotificationForm("Login Successful!", "Welcome, " + user->username + "!");
				notifyForm->Show();
				
				this->DialogResult = System::Windows::Forms::DialogResult::OK; 
				this->Close();
			}
			else {
				MessageBox::Show("User or password is incorrect",
					"User or Password Error", MessageBoxButtons::OK);
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to connect to database " + e->Message,
				"Database Connection Error", MessageBoxButtons::OK);
		}
	}
	private: System::Void btnCancel2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
}
};
}

