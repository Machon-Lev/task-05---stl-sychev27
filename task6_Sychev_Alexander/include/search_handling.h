#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "city.h"
#include "calc_distance_handling.h"

class Search_handling
{
public:
	// Function to search for cities within a given radius of a selected city
	std::vector<City> searchCities(const std::vector<City>& cities, const City& selectedCity, double radius, int norm);
private:
	Calc_distance_handling calc_distance;
	// Function to check if a city is within the given radius
	bool isWithinRadius(const City& city, const City& selectedCity, double radius, int norm);

};