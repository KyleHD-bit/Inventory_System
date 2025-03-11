#pragma once

#include "MainForm.h"

namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ICS
	/// </summary>
	
	public ref class ICS : public System::Windows::Forms::Form
	{
	private: MainForm^ mainForm;
	public:
		ICS(MainForm^ form)
		{
			InitializeComponent();
			mainForm = form;
			//
			//TODO: Add the constructor code here
			//
		}
	
	private: CrystalDecisions::Windows::Forms::CrystalReportViewer^ crystalReportViewer1;
	public:
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ICS()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->crystalReportViewer1 = (gcnew CrystalDecisions::Windows::Forms::CrystalReportViewer());
			this->SuspendLayout();
			// 
			// crystalReportViewer1
			// 
			this->crystalReportViewer1->ActiveViewIndex = -1;
			this->crystalReportViewer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->crystalReportViewer1->Cursor = System::Windows::Forms::Cursors::Default;
			this->crystalReportViewer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->crystalReportViewer1->Location = System::Drawing::Point(0, 0);
			this->crystalReportViewer1->Name = L"crystalReportViewer1";
			this->crystalReportViewer1->Size = System::Drawing::Size(1203, 667);
			this->crystalReportViewer1->TabIndex = 0;
			// 
			// ICS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1203, 667);
			this->Controls->Add(this->crystalReportViewer1);
			this->Name = L"ICS";
			this->Text = L"ICS";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
