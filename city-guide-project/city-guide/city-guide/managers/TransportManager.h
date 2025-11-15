#pragma once
#include "../models/Transport.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace Newtonsoft::Json;

ref class TransportManager {
public:
	static TransportManager^ Instance = gcnew TransportManager();
	static String^ fileName;

	TransportManager() {
		fileName = "transports.json";
		/*_transportsList->Add(gcnew Transport("12", Transport::TransportTypeEnum::Bus));
		_transportsList->Add(gcnew Transport("13", Transport::TransportTypeEnum::Bus));
		_transportsList->Add(gcnew Transport("14", Transport::TransportTypeEnum::Bus));
		_transportsList->Add(gcnew Transport("15", Transport::TransportTypeEnum::Bus));
		_transportsList->Add(gcnew Transport("15A", Transport::TransportTypeEnum::Bus));
		_transportsList->Add(gcnew Transport("3", Transport::TransportTypeEnum::Trolleybus));
		_transportsList->Add(gcnew Transport("4", Transport::TransportTypeEnum::Trolleybus));
		_transportsList->Add(gcnew Transport("5", Transport::TransportTypeEnum::Trolleybus));
		_transportsList->Add(gcnew Transport("125", Transport::TransportTypeEnum::Tram));
		_transportsList->Add(gcnew Transport("218", Transport::TransportTypeEnum::Tram));
		_transportsList->Add(gcnew Transport("1", Transport::TransportTypeEnum::Ferry));
		_transportsList->Add(gcnew Transport("Emergency", Transport::TransportTypeEnum::Helicopter));
		_transportsList->Add(gcnew Transport("2", Transport::TransportTypeEnum::Funicular));
		_transportsList->Add(gcnew Transport("3", Transport::TransportTypeEnum::Funicular));*/
		/*UpdateFileWithTransports();*/
	}

	void LoadTransportsFromFile() {
		try {
			StreamReader^ sr = File::OpenText(fileName);
			String^ allInfo = sr->ReadToEnd();
			_transportsList = JsonConvert::DeserializeObject<List<Transport^>^>(allInfo);
			sr->Close();
		} catch (Exception^ e) {
			if (dynamic_cast<FileNotFoundException^>(e)) {
				Console::WriteLine("file '{0}' not found", fileName);
			} else {
				Console::WriteLine("problem reading file '{0}'", fileName);
			}
		}
	}

	List<Transport^>^ GetTransportList() {
		return _transportsList;
	}

	bool TryDeleteTransport(Transport^ transportToDelete) {
		if (transportToDelete == nullptr) {
			return false;
		}
		_transportsList->Remove(transportToDelete);
		UpdateFileWithTransports();
		return true;
	}

	bool TryAddTransport(String^ name, Transport::TransportTypeEnum type) {
		if (IsTransportExisting(name, type)) {
			return false;
		}
		_transportsList->Add(gcnew Transport(name, type));
		UpdateFileWithTransports();
		return true;
	}

	bool TryEditTransport(Transport^ transportToEdit, String^ name, Transport::TransportTypeEnum type) {
		if (transportToEdit == nullptr || IsTransportExisting(name, type)) {
			return false;
		}
		transportToEdit->Name = name;
		transportToEdit->TransportType = type;
		UpdateFileWithTransports();
		return true;
	}

	bool IsTransportExisting(String^ name, Transport::TransportTypeEnum type) {
		// to do
		return false;
	}


private:
	List<Transport^>^ _transportsList = gcnew List<Transport^>();

	void UpdateFileWithTransports() {
		try {
			StreamWriter^ sw = File::CreateText(fileName);
			String^ tmp = JsonConvert::SerializeObject(_transportsList, Newtonsoft::Json::Formatting::Indented);
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