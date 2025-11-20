#pragma once
#include "Institution.h"

ref class Wharf : Institution {
public:
	int NumberOfFloatingVehicles;

	void UpdateEntity(int numberOfFloatingVehicles) {
		NumberOfFloatingVehicles = numberOfFloatingVehicles;
	}
};