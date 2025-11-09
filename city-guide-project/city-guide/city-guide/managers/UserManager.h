#pragma once
#include "../models/User.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

ref class UserManager {
public:
	static UserManager^ Current = gcnew UserManager();

	User^ CurrentUser = nullptr;

	void LoadUsers() {
		String^ fileName = "users.txt";
		try {
			StreamReader^ sr = File::OpenText(fileName);
			while (sr->Peek() >= 0) {
				User^ user = gcnew User();
				String^ str = sr->ReadLine();
				array<String^>^ stringArray = str->Split(' ');

				user->Password = stringArray[1];
				array<String^>^ stringArray2 = stringArray[0]->Split(':');
				if (stringArray2[0] == "admin") {
					user->IsAdmin = true;
				} else {
					user->IsAdmin = false;
				}
				user->Username = stringArray2[1];
				usersList->Add(user);
			}
		} catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e))
				Console::WriteLine("file '{0}' not found", fileName);
			else
				Console::WriteLine("problem reading file '{0}'", fileName);
		}
	}

	bool TryLogin(String^ username, String^ password) {
		for each (User ^ currentUser in usersList) {
			if (currentUser->Username == username && currentUser->Password == password) {
				CurrentUser = currentUser;
				return true;
			}
		}
		return false;
	}

private:
	List<User^>^ usersList = gcnew List<User^>();

};
