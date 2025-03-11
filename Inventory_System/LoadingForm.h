#pragma once

namespace InventorySystem {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Threading; // For animations

    public ref class LoadingForm : public Form {
    private:
        Label^ loadingLabel;
        ProgressBar^ progressBar;
        System::Windows::Forms::Timer^ loadingTimer;
        int progressValue = 0;

    public:
        LoadingForm() {
            //  Set Form Properties
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // No borders
            this->StartPosition = FormStartPosition::CenterScreen; // Center screen
            this->BackColor = Color::White; // Background color
            this->Size = Drawing::Size(350, 150);
            this->TopMost = true;  // Stay on top
            this->Opacity = 0.9;  // Slight transparency
            this->ShowInTaskbar = false;

            //  Create Rounded Corners
            this->Region = gcnew System::Drawing::Region(CreateRoundedRectangle(this->ClientRectangle, 15));

            //  Loading Label
            loadingLabel = gcnew Label();
            loadingLabel->Text = "Loading, please wait...";
            loadingLabel->Font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
            loadingLabel->ForeColor = Color::Black;
            loadingLabel->AutoSize = false;
            loadingLabel->Size = Drawing::Size(300, 30);
            loadingLabel->TextAlign = ContentAlignment::MiddleCenter;
            loadingLabel->Location = Point(25, 40);

            //  Progress Bar
            progressBar = gcnew ProgressBar();
            progressBar->Style = ProgressBarStyle::Marquee; // Animated effect
            progressBar->Size = Drawing::Size(300, 10);
            progressBar->Location = Point(25, 80);
            progressBar->ForeColor = Color::RoyalBlue; // Color of progress bar
            progressBar->BackColor = Color::LightGray;

            //  Timer for animation effect
            loadingTimer = gcnew System::Windows::Forms::Timer();
            loadingTimer->Interval = 100; // Every 100ms
            loadingTimer->Tick += gcnew EventHandler(this, &LoadingForm::AnimateProgress);
            loadingTimer->Start();

            //  Add Controls
            this->Controls->Add(loadingLabel);
            this->Controls->Add(progressBar);
        }

    private:
        void AnimateProgress(System::Object^ sender, System::EventArgs^ e) {
            // Simulate progress increase (Optional)
            progressValue += 5;
            if (progressValue > 100) progressValue = 0;
            progressBar->Value = progressValue;
        }

        //  Create Rounded Corners for Form
        GraphicsPath^ CreateRoundedRectangle(Rectangle rect, int radius) {
            GraphicsPath^ path = gcnew GraphicsPath();
            path->AddArc(rect.X, rect.Y, radius, radius, 180, 90);
            path->AddArc(rect.Right - radius, rect.Y, radius, radius, 270, 90);
            path->AddArc(rect.Right - radius, rect.Bottom - radius, radius, radius, 0, 90);
            path->AddArc(rect.X, rect.Bottom - radius, radius, radius, 90, 90);
            path->CloseFigure();
            return path;
        }
    };
}
