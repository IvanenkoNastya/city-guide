#pragma once
using namespace System;

ref class Transport {
public:
	enum class TransportTypeEnum {
		Unknown = 0,
		Bus,
		Tram,
		Metro,
		Trolleybus,
		Train,
		Funicular,
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

