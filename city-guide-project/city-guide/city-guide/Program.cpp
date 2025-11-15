#include "Forms/FormCityGuide.h"
#include "Forms/Login/FormLogin.h"
#include "managers/UserManager.h"
#include "managers/TransportManager.h"
#include "managers/DistrictManager.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace cityguide;


[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TransportManager::Instance->LoadTransportsFromFile();
	UserManager::Instance->LoadUsersFromFile();
	DistrictManager::Instance->LoadDistrictsFromFile();

	FormLogin^ formLogin = gcnew FormLogin();
	if (formLogin->ShowDialog() == DialogResult::OK) {
		cityguide::FormCityGuide form;
		Application::Run(% form);
	}
	return 0;
}


