#pragma once
#include "Institution.h"

ref class Hospital : Institution {
public:
	enum class HospitalTypeEnum {
		General,
		Rehabilitation,
		Trauma,
		Clildren,
		Geriatric,
		Cardiology,
		Hospis
	};

	HospitalTypeEnum HospitalType;

	void UpdateEntity(String^ hospitalType) {
		HospitalType = GetTranportTypeEnum(hospitalType);
	}

private:
	HospitalTypeEnum GetTranportTypeEnum(String^ hospitalTypeStr) {
		HospitalTypeEnum result;
		if (!Enum::TryParse<HospitalTypeEnum>(hospitalTypeStr, result)) {
			return HospitalTypeEnum::General;
		}
		return result;
	}
};