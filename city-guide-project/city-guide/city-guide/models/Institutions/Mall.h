#pragma once
#include "Institution.h"

ref class Mall : Institution {
public:
	bool HasParking;
	bool HasGrocery;
	bool HasEntertainmentCenter;

	void UpdateEntity(bool hasParking, bool hasGrocery, bool hasEntertainmentCenter) {
		HasParking = hasParking;
		HasGrocery = hasGrocery;
		HasEntertainmentCenter = hasEntertainmentCenter;
	}
};