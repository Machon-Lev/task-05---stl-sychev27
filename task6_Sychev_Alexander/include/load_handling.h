#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "city.h"

class Load_handling
{
public:
	 std::vector<City> loadCities(const std::string& filename);
};