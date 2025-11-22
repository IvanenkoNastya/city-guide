#pragma once

using namespace System;
using namespace System::Collections::Generic;

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

	String^ GetNameWithTransportsAmount() {
		String^ res = ToString() + "; " + TransportList->Count + " transport";
		if (TransportList->Count != 1) {
			res += "s";
		}
		return res;
	}

	String^ GetNameWithDistrict() {
		return ToString() + "; " + District->ToString() + " district";
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

public ref class CompareInstitutionsByName : System::Collections::Generic::Comparer<Institution^> {
public:
	virtual int Compare(Institution^ a, Institution^ b) override {
		return a->Name->CompareTo(b->Name);
	}
};

public ref class CompareInstitutionsByAmountOfTransports : System::Collections::Generic::Comparer<Institution^> {
public:
	virtual int Compare(Institution^ a, Institution^ b) override {
		int aTransports = a->TransportList->Count;
		int bTransports = b->TransportList->Count;
		return aTransports.CompareTo(bTransports);
	}
};

public ref class CompareInstitutionsByType : System::Collections::Generic::Comparer<Institution^> {
public:
	virtual int Compare(Institution^ a, Institution^ b) override {
		return a->InstitutionType.CompareTo(b->InstitutionType);
	}
};

public ref class CompareInstitutionsByDistrict : System::Collections::Generic::Comparer<Institution^> {
public:
	virtual int Compare(Institution^ a, Institution^ b) override {
		return a->District->CompareTo(b->District);
	}
};