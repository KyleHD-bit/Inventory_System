public ref class TransparentButton : public System::Windows::Forms::Button
{
protected:
    virtual void OnPaint(System::Windows::Forms::PaintEventArgs^ pevent) override
    {
        // Make the background of the button transparent
        pevent->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Transparent), this->ClientRectangle);

        // Draw the button's text using TextRenderer
        System::Windows::Forms::TextRenderer::DrawText(pevent->Graphics, this->Text, this->Font, this->ClientRectangle, this->ForeColor);
    }

    virtual void OnPaintBackground(System::Windows::Forms::PaintEventArgs^ pevent) override
    {
        // Prevent the background from being painted
    }
};