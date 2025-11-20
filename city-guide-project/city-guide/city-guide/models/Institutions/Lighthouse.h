#pragma once
#include "Institution.h"

ref class Lighthouse : public Institution {
public:
	String^ LightColour;

	void UpdateEntity(String^ lightColour) {
		LightColour = lightColour;
	}
};