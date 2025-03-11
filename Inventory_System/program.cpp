#include <windows.h>
#include <tchar.h>
#include "LoginForm1.h"
#include "MainForm.h"
#include "MainForm2.h"
#include "SelectDB.h"
#include "NotificationForm.h"
//#include "AddForm.h"


using namespace System;
using namespace System::Windows::Forms;
//using namespace InventorySystem;



/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//int main(array<System::String^>^ args)
//void main(array<String^>^ args)

{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InventorySystem::LoginForm1 loginForm;

	loginForm.ShowDialog();
	User^ user = loginForm.user;

	if (user != nullptr) {
		//MessageBox::Show("Successful Authentication of " + user->username,
			//"Municipality Of Buenavista", MessageBoxButtons::OK);

		//InventorySystem::MainForm mainForm(user);
		//Application::Run(% mainForm);

		//InventorySystem::MainForm2 mainForm2(user);
		//Application::Run(% mainForm2);

		//lgout lgin
		InventorySystem::MainForm2^ mainForm2 = gcnew InventorySystem::MainForm2(user);
		Application::Run(mainForm2);
		
		if (mainForm2->DialogResult == System::Windows::Forms::DialogResult::Cancel) {
			continue; // Restart Login
		}

		//InventorySystem::SelectDB selectDB(user);
		//Application::Run(% selectDB);

		//InventorySystem::MainForm mainForm(user);
		//Application::Run(% mainForm);

		//MessageBox::Show("Successful Authentication of " + user->username,
		//"program.cpp", MessageBoxButtons::OK);
	}
	else {
		MessageBox::Show("Authentication Canceled",
			"Municipality Of Buenavista", MessageBoxButtons::OK);
	}

} */



[STAThread]
//int main(array<String^>^ args) {
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {


int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	while (true) { // Loop to allow relogin after logout
		InventorySystem::LoginForm1 loginForm;

		// Show login form
		if (loginForm.ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			User^ user = loginForm.user; // Retrieve user from login form

			if (user != nullptr) {
				// Open MainForm2 with the logged-in user
				//InventorySystem::MainForm mainForm(user);
				//Application::Run(% mainForm);
				InventorySystem::MainForm2^ mainForm2 = gcnew InventorySystem::MainForm2(user);
				Application::Run(mainForm2);  // Runs MainForm2

				// Check if MainForm2 was closed intentionally (logout)
				if (mainForm2->DialogResult == System::Windows::Forms::DialogResult::Cancel) {
					continue; // Restart login process
				}
			}
		}
		else {
			break; // Exit loop if login was cancelled
		}
	}

	return 0;
}

