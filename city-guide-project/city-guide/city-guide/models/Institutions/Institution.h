#pragma once

using namespace System;

public enum class InstitutionTypeEnum {
	Unknown = 0,
	Lighthouse,
	Wharf,
	Museum,
	Theatre,
	Library,
	Hospital,
	Airport,
	Restaurant,
	School,
	Mall
};

ref class Institution {
public:
	String^ Name;
	InstitutionTypeEnum InstitutionType;
	List<Transport^>^ TransportList;
	String^ District;

	Institution() {
		Name = "";
		InstitutionType = InstitutionTypeEnum::Unknown;
		TransportList = gcnew List<Transport^>();
		District = "";
	}

	Institution(String^ name, InstitutionTypeEnum institutionType) {
		Name = name;
		InstitutionType = institutionType;
		TransportList = gcnew List<Transport^>();
		District = "";
	}

	virtual String^ ToString() override {
		return InstitutionType.ToString() + ": " + Name;
	}

	static InstitutionTypeEnum GetTranportTypeEnum(String^ institutionTypeStr) {
		InstitutionTypeEnum result;
		if (!Enum::TryParse<InstitutionTypeEnum>(institutionTypeStr, result)) {
			return InstitutionTypeEnum::Unknown;
		}
		return result;
	}
};

