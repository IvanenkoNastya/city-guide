#pragma once
using namespace System;

enum TransportTypeEnum {
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

ref class Transport {
public:
	String^ Name;
	TransportTypeEnum TransportType;

	Transport() {
		Name = "";
		TransportType = Unknown;
	}

	Transport(String^ name, TransportTypeEnum transportType) {
		Name = name;
		TransportType = transportType;
	}

	TransportTypeEnum GetTranportTypeEnum(String^ transportTypeStr) {
		TransportTypeEnum result;
		if (!Enum::TryParse<TransportTypeEnum>(transportTypeStr, result)) {
			return TransportTypeEnum::Unknown;
		}
		return result;
	}

	String^ GetTranportTypeStr(TransportTypeEnum transportTypeEnum) {
		String^ result;
		/*String^ str = Type::GetEnumName(TransportTypeEnum::Bus);*/
		Type^ type = Type::GetType("TransportTypeEnum");
		Enum::GetName(type, (Object^)transportTypeEnum);
		
		/*result = Enum::GetName<TransportTypeEnum>(transportTypeEnum);*/
		/*Enum::GetName(Enum::GetType()
		Enum::Get*/

		return result;
	}
};

