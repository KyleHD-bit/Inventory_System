#include "SelectDB.h"
#include "LeeForm.h"
#include "GeneralFund.h"


//############# LEE FORM #############//

void InventorySystem::SelectDB::guna2Button1_Click(System::Object^ sender, System::EventArgs^ e) {
    
    this->Hide();
    
    // Create an instance of LeeForm
    InventorySystem::LeeForm^ leeForm = gcnew InventorySystem::LeeForm();

    // Show the form
    leeForm->ShowDialog();

    this->Show();

}


//############# GF FORM #############//

void InventorySystem::SelectDB::guna2Button2_Click(System::Object^ sender, System::EventArgs^ e) {
   
    this->Hide();
    
    // instance of GF
    InventorySystem::GeneralFund^ generalFund = gcnew InventorySystem::GeneralFund();

    // Show the form
    generalFund->ShowDialog();

    this->Show();

}
