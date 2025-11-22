#pragma once
using namespace System;

// class representing a viechle object that can be assigned to any institution as its property
ref class Transport {
public:
	enum class TransportTypeEnum {
		Unknown = 0,
		Bus,
		Trolleybus,
		Tram,
		Metro,
		Funicular,
		Train,
		Ferry,
		Helicopter
	};

	String^ Name;
	TransportTypeEnum TransportType;

	Transport() {
		Name = "";
		TransportType = TransportTypeEnum::Unknown;
	}

	Transport(String^ name, TransportTypeEnum transportType) {
		Name = name;
		TransportType = transportType;
	}

	virtual String^ ToString() override {
		return TransportType.ToString() + ": " + Name;
	}

	virtual bool Equals(const Transport ^ other) override {
		return Name == other->Name && TransportType == other->TransportType;
	}

	static TransportTypeEnum GetTranportTypeEnum(String^ transportTypeStr) {
		TransportTypeEnum result;
		if (!Enum::TryParse<TransportTypeEnum>(transportTypeStr, result)) {
			return TransportTypeEnum::Unknown;
		}
		return result;
	}
};

public ref class CompareTransportsByName : System::Collections::Generic::Comparer<Transport^> {
public:
	virtual int Compare(Transport^ a, Transport^ b) override {
		return a->Name->CompareTo(b->Name);
	}
};

public ref class CompareTransportsByType : System::Collections::Generic::Comparer<Transport^> {
public:
	virtual int Compare(Transport^ a, Transport^ b) override {
		return a->TransportType.CompareTo(b->TransportType);
	}
};