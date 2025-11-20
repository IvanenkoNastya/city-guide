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
	String^ Address;

	Institution() {
		Name = "";
		InstitutionType = InstitutionTypeEnum::Unknown;
		TransportList = gcnew List<Transport^>();
		District = "";
		Address = "";
	}

	Institution(String^ name, InstitutionTypeEnum institutionType) {
		Name = name;
		InstitutionType = institutionType;
		TransportList = gcnew List<Transport^>();
		District = "";
		Address = "";
	}

	void UpdateBase(
		String^ name,
		InstitutionTypeEnum institutionType,
		List<Transport^>^ transportList,
		String^ district,
		String^ address
	) {
		Name = name;
		InstitutionType = institutionType;
		TransportList = transportList;
		District = district;
		Address = address;
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

