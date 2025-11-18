#pragma once
#include "../models/Institutions/Institution.h"
#include "../models/Institutions/Lighthouse.h"
#include "../models/Institutions/Wharf.h"
#include "../models/Institutions/Museum.h"
#include "../models/Institutions/Theatre.h"
#include "../models/Institutions/Library.h"
#include "../models/Institutions/Hospital.h"
#include "../models/Institutions/Airport.h"
#include "../models/Institutions/Restaurant.h"
#include "../models/Institutions/School.h"
#include "../models/Institutions/Mall.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace Newtonsoft::Json;

ref class InstitutionManager {
public:
	static InstitutionManager^ Instance = gcnew InstitutionManager();
	static String^ fileName = "institutions.json";

	void LoadInstitutionsFromFile() {
		try {
			StreamReader^ sr = File::OpenText(fileName);
			String^ allInfo = sr->ReadToEnd();
			Newtonsoft::Json::JsonSerializerSettings^ settings = gcnew Newtonsoft::Json::JsonSerializerSettings();
			settings->TypeNameHandling = Newtonsoft::Json::TypeNameHandling::Auto;
			_institutionsList = JsonConvert::DeserializeObject<List<Institution^>^>(allInfo, settings);
			sr->Close();
		} catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e)) {
				Console::WriteLine("file '{0}' not found", fileName);
			} else {
				Console::WriteLine("problem reading file '{0}'", fileName);
			}
		}
	}

	List<Institution^>^ GetInstitutionList() {
		return _institutionsList;
	}

	bool TryDeleteInstitution(Institution^ institutionToDelete) {
		if (institutionToDelete == nullptr) {
			return false;
		}
		_institutionsList->Remove(institutionToDelete);
		UpdateFileWithInstitutions();
		return true;
	}

	bool TryAddInstitution(Institution^ institution, InstitutionTypeEnum type) {
		if (IsInstitutionExisting(institution->Name, type)) {
			return false;
		}
		_institutionsList->Add(institution);
		UpdateFileWithInstitutions();
		return true;
	}

	bool TryEditInstitution(Institution^ institutionToEdit) {
		if (institutionToEdit == nullptr) {
			return false;
		}
		UpdateFileWithInstitutions();
		return true;
	}

	bool IsInstitutionExisting(String^ name, InstitutionTypeEnum type) {
		// to do
		return false;
	}


private:
	List<Institution^>^ _institutionsList = gcnew List<Institution^>();

	void UpdateFileWithInstitutions() {
		try {
			StreamWriter^ sw = File::CreateText(fileName);
			Newtonsoft::Json::JsonSerializerSettings^ settings = gcnew Newtonsoft::Json::JsonSerializerSettings();
			settings->TypeNameHandling = Newtonsoft::Json::TypeNameHandling::Auto;
			String^ tmp = JsonConvert::SerializeObject(_institutionsList, Newtonsoft::Json::Formatting::Indented, settings);
			sw->Write(tmp);
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