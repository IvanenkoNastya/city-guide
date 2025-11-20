#pragma once
#include "Institution.h"

ref class Theatre : Institution {
public:
	bool HasOrchestra;

	void UpdateEntity(int hasOrchestra) {
		HasOrchestra = hasOrchestra;
	}
};