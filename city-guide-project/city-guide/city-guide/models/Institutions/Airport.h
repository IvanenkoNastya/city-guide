#pragma once
#include "Institution.h"

ref class Airport : public Institution {
public:
	bool IsInternational;

	void UpdateEntity(bool isInternational) {
		IsInternational = isInternational;
	}
};