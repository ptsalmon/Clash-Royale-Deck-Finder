#include "pch.h"
#include "Form1.h"
#include "Form2.h"

using namespace CppCLRWinFormsProject;

System::Void CppCLRWinFormsProject::Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void CppCLRWinFormsProject::Form1::uMapButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	mapChoice = false;
	this->Close();
}

System::Void CppCLRWinFormsProject::Form1::oMapButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	mapChoice = true;
	this->Close();
}



