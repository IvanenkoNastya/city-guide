#pragma once
#include "Institution.h"

ref class Museum : Institution {
public:
	enum class MuseumTypeEnum {
		General,
		Art,
		Music,
		Archeological,
		History,
		Military,
		Maritime,
		Business,
		Technology,
		Science,
		Nature,
		Medical,
		Sports,
		Facion,
		Astronautic,
		Ceramic,
		Religion,
		Virtual,
		Other
	};

	MuseumTypeEnum MuseumType;

	void UpdateEntity(String^ museumType) {
		MuseumType = GetTranportTypeEnum(museumType);
	}

private:
	MuseumTypeEnum GetTranportTypeEnum(String^ museumTypeStr) {
		MuseumTypeEnum result;
		if (!Enum::TryParse<MuseumTypeEnum>(museumTypeStr, result)) {
			return MuseumTypeEnum::General;
		}
		return result;
	}
};