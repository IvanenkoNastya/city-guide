#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace Newtonsoft::Json;

// district manager interacts with districts that are represented as String^ in Institution object
// stores list of districts as list of strings
// interacts with file "districts.json"
ref class DistrictManager {
public:
	static DistrictManager^ Instance = gcnew DistrictManager();
	static String^ fileName = "districts.json";

	void LoadDistrictsFromFile() {
		try {
			StreamReader^ sr = File::OpenText(fileName);
			String^ allInfo = sr->ReadToEnd();
			_districtsList = JsonConvert::DeserializeObject<List<String^>^>(allInfo);
			sr->Close();
		} catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e)) {
				Console::WriteLine("file '{0}' not found", fileName);
			} else {
				Console::WriteLine("problem reading file '{0}'", fileName);
			}
		}
	}

	List<String^>^ GetDistrictList() {
		return _districtsList;
	}

	bool TryDeleteDistrict(String^ districtToDelete) {
		if (!IsDistrictExisting(districtToDelete)) {
			return false;
		}
		_districtsList->Remove(districtToDelete);
		InstitutionManager::Instance->DistrictChanged(districtToDelete, nullptr);
		UpdateFileWithDistricts();
		return true;
	}

	bool TryAddDistrict(String^ newDistrict) {
		if (IsDistrictExisting(newDistrict)) {
			return false;
		}
		_districtsList->Add(newDistrict);
		UpdateFileWithDistricts();
		return true;
	}

	bool TryEditDistrict(String^ districtToEdit, String^ newDistrict) {
		if (!IsDistrictExisting(districtToEdit) || IsDistrictExisting(newDistrict)) {
			return false;
		}
		int index = _districtsList->IndexOf(districtToEdit);
		_districtsList[index] = newDistrict;
		InstitutionManager::Instance->DistrictChanged(districtToEdit, newDistrict);
		UpdateFileWithDistricts();
		return true;
	}

	bool IsDistrictExisting(String^ district) {
		return _districtsList->Contains(district);
	}

private:
	List<String^>^ _districtsList = gcnew List<String^>();

	void UpdateFileWithDistricts() {
		try {
			StreamWriter^ sw = File::CreateText(fileName);
			String^ tmp = JsonConvert::SerializeObject(_districtsList, Newtonsoft::Json::Formatting::Indented);
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
