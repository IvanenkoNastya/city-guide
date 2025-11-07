#include "CityGuide.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace cityguide;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	cityguide::CityGuideForm form;
	Application::Run(%form);
	return 0;
}