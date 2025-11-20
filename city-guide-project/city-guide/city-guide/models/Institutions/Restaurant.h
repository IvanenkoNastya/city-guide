#pragma once
#include "Institution.h"

ref class Restaurant : Institution {
public:
	String^ Cuisine;

	void UpdateEntity(String^ cuisine) {
		Cuisine = cuisine;
	}
};