#pragma once
#include "../models/User.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

ref class UserManager {
public:
	static UserManager^ Instance = gcnew UserManager();
	static String^ fileName = "users.txt";

	User^ CurrentUser = nullptr;

	void LoadUsersFromFile() {
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
				_usersList->Add(user);
			}
			sr->Close();
		} catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e)) {
				Console::WriteLine("file '{0}' not found", fileName);
			} else {
				Console::WriteLine("problem reading file '{0}'", fileName);
			}
		}
	}

	bool TryLogin(String^ username, String^ password) {
		for each (User ^ currentUser in _usersList) {
			if (currentUser->Username == username && currentUser->Password == password) {
				CurrentUser = currentUser;
				return true;
			}
		}
		return false;
	}

	List<String^>^ GetUsers() {
		List<String^>^ res = gcnew List<String^>();
		for each (User^ user in _usersList) {
			String^ userInfo = gcnew String("");
			if (user->IsAdmin) {
				userInfo += "admin:";
			} else {
				userInfo += "user:";
			}
			userInfo += user->Username;
			res->Add(userInfo);
		}
		return res;
	}

	User^ FindUser(String^ userInfo) {
		if (userInfo == nullptr) {
			return nullptr;
		}
		String^ usernameToFind = userInfo->Split(':')[1];
		for each (User ^ user in _usersList) {
			if (user->Username == usernameToFind) {
				return user;
			}
		}
		return nullptr;
	}

	bool TryDeleteUser(String^ userInfo) {
		User^ userToDelete = FindUser(userInfo);
		if (userToDelete == nullptr) {
			return false;
		}
		if (userToDelete == CurrentUser) {
			return false;
		}
		_usersList->Remove(userToDelete);
		UpdateFileWithUsers();
		return true;
	}

private:
	List<User^>^ _usersList = gcnew List<User^>();

	void UpdateFileWithUsers() {
		try {
			StreamWriter^ sw = File::CreateText(fileName);
			for each (User^ user in _usersList) {
				if (user->IsAdmin) {
					sw->Write("admin:");
				} else {
					sw->Write("user:");
				}
				sw->Write(user->Username);
				sw->Write(" ");
				sw->Write(user->Password);
				sw->WriteLine();
			}
			sw->Close();
		} catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e)) {
				Console::WriteLine("file '{0}' not found", fileName);
			} else {
				Console::WriteLine("problem writing file '{0}'", fileName);
			}
		}
	}

};
