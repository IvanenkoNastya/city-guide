#pragma once
using namespace System;

// class representing info about user
ref class User {
	public:
		bool IsAdmin;
		String^ Username;
		String^ Password;

		User() {
			IsAdmin = false;
			Username = "";
			Password = "";
		}

		User(bool isAdmin, String^ username, String^ password) {
			IsAdmin = isAdmin;
			Username = username;
			Password = password;
		}
};

