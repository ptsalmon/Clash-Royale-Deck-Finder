#pragma once
#include "pch.h"
#include "Form2.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

using namespace CppCLRWinFormsProject;

using namespace System::Windows::Forms;

[STAThread]

int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  Form2^ form2 = gcnew Form2();
  Application::Run(form2);

  return 0;
}