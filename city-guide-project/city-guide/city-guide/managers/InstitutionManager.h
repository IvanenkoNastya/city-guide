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

// institution manager interacts with Institution objects
// interacts with file "institutions.json" where institutions are stored
// this manager interacts is called from different places where Institution objects or their properties are in need
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

	List<Institution^>^ GetInstitutionListByDistrict(String^ district) {
		List<Institution^>^ institutionsInDistrict = gcnew List<Institution^>();
		for each (Institution^ institution in _institutionsList) {
			if (institution->District == district) {
				institutionsInDistrict->Add(institution);
			}
		}
		return institutionsInDistrict;
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
		for each (Institution^ institution in _institutionsList) {
			if (institution->Name == name && institution->InstitutionType == type) {
				return true;
			}
		}
		return false;
	}

	List<Transport^>^ GetTransportList(Institution^ institutionFrom, Institution^ institutionTo) {
		List<Transport^>^ transports = gcnew List<Transport^>();
		for each (Transport^ fromTransport in institutionFrom->TransportList) {
			for each (Transport^ toTransport in institutionTo->TransportList) {
				if (fromTransport->Equals(toTransport)) {
					if (! transports->Contains(fromTransport)) {
						transports->Add(fromTransport);
					}
				}
			}
		}

		return transports;
	}

	void DistrictChanged(String^ districtOld, String^ districtNew) {
		for each (Institution ^ institution in _institutionsList) {
			if (institution->District == districtOld) {
				if (districtNew == nullptr) {
					institution->District = "";
				} else {
					institution->District = districtNew;
				}
			}
		}
		UpdateFileWithInstitutions();
	}

	void TransportChanged(Transport^ transportOld, String^ nameNew, Transport::TransportTypeEnum typeNew) {
		for each (Institution ^ institution in _institutionsList) {
			int length = institution->TransportList->Count;
			if (nameNew == nullptr) {
				// remove some elements
				List<Transport^>^ transportsToRemove = gcnew List<Transport^>();
				for each (Transport^ transport in institution->TransportList) {
					if (transport->Equals(transportOld)) {
						transportsToRemove->Add(transport);
					}
				}
				for each (Transport^ transport in transportsToRemove) {
					institution->TransportList->Remove(transport);
				}
			} else {
				// edit some elements
				for each (Transport^ transport in institution->TransportList) {
					if (transport->Equals(transportOld)) {
						transport->Name = nameNew;
						transport->TransportType = typeNew;
					}
				}
			}
		}
		UpdateFileWithInstitutions();
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