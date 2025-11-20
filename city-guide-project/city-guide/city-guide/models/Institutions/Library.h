#pragma once
#include "Institution.h"

ref class Library : Institution {
public:
	bool IsUniversityLibrary;

	void UpdateEntity(bool isUniversityLibrary) {
		IsUniversityLibrary = isUniversityLibrary;
	}
};