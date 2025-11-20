#pragma once
#include "Institution.h"

ref class School : Institution {
public:
	int NumberOfFaculties;

	void UpdateEntity(int numberOfFaculties) {
		NumberOfFaculties = numberOfFaculties;
	}
};