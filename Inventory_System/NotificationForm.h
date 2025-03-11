#pragma once


namespace InventorySystem {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D; // For rounded corners

    public ref class NotificationForm : public Form
    {
    public:
        NotificationForm(String^ title, String^ message)
        {
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->BackColor = Color::FloralWhite; //  background
            this->ForeColor = Color::Black;
            this->Size = Drawing::Size(350, 100);
            //this->ClientSize = System::Drawing::Size(250, 100); // Ensure exact size
            this->StartPosition = FormStartPosition::Manual;

            // Ensure it appears on top
            this->TopMost = true;  //  Stays above all windows
            this->ShowInTaskbar = false;  //  Hides from taskbar
            this->Opacity = 0.80;  //  Slight transparency
            this->BringToFront(); //  Ensures visibility


            // rounded corner
            ApplyRoundedCorners(15);


            // Title (Bold)
            Label^ lblTitle = gcnew Label();
            lblTitle->Text = title;
            lblTitle->ForeColor = Color::Black;
            lblTitle->Size = Drawing::Size(240, 25);
            lblTitle->Location = Point(10, 10);
            lblTitle->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
            lblTitle->TextAlign = ContentAlignment::MiddleLeft;

            // Message (Regular)
            Label^ lblMessage = gcnew Label();
            lblMessage->Text = message;
            lblMessage->ForeColor = Color::Black;
            lblMessage->Size = Drawing::Size(240, 50);
            lblMessage->Location = Point(10, 25);
            lblMessage->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Regular);
            lblMessage->TextAlign = ContentAlignment::MiddleLeft;


            //controls
            this->Controls->Add(lblTitle);
            this->Controls->Add(lblMessage);

            // Set position to lower-right corner
            Screen^ screen = Screen::PrimaryScreen;
            int x = screen->WorkingArea.Width - this->Width - 30; // 10px from right
            int y = screen->WorkingArea.Height - this->Height - 20; // 10px from bottom
            this->Location = Point(x, y);

            // Timer to auto-close after 3 seconds
            Timer^ timer = gcnew Timer();
            timer->Interval = 5000; // 5 seconds
            timer->Tick += gcnew EventHandler(this, &NotificationForm::CloseForm);
            timer->Start();
        }
    


    private:
        void ApplyRoundedCorners(int radius)
        {
            GraphicsPath^ path = gcnew GraphicsPath();
            path->AddArc(0, 0, radius, radius, 180, 90);
            path->AddArc(this->Width - radius, 0, radius, radius, 270, 90);
            path->AddArc(this->Width - radius, this->Height - radius, radius, radius, 0, 90);
            path->AddArc(0, this->Height - radius, radius, radius, 90, 90);
            path->CloseFigure();

            this->Region = gcnew System::Drawing::Region(path);
        }

    /*protected:
        virtual void OnPaint(PaintEventArgs^ e) override
        {
            Form::OnPaint(e);
            Pen^ blackPen = gcnew Pen(Color::Black, 2); // 2px thick border

            //  Adjust the border by subtracting the pen width to avoid overflow
            int borderOffset = 2;
            e->Graphics->DrawRectangle(blackPen,
                borderOffset / 2, borderOffset / 2, // Prevent shifting
                this->ClientSize.Width - borderOffset,
                this->ClientSize.Height - borderOffset
            );
        } */

    private: //debug here!
        void CloseForm(System::Object^ sender, System::EventArgs^ e) {
            //this->Close();
            Timer^ timer = safe_cast<Timer^>(sender);
            timer->Stop();  // Stop the timer before closing
            delete timer;   // Clean up timer to prevent memory leaks

            this->Hide();   // Hide instead of closing, prevents unintended shutdown
        }
    private: System::Void InitializeComponent() {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NotificationForm::typeid));
        this->SuspendLayout();
        // 
        // NotificationForm
        // 
        this->ClientSize = System::Drawing::Size(284, 261);
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->Name = L"NotificationForm";
        this->ResumeLayout(false);
    }
    };
}