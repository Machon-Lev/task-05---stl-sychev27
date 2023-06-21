#pragma once
#include <vector>
#include "city.h"
#include <iostream>
#include <algorithm>

class IO_handling
{
public:
    City input_cityName(const std::vector<City>& cities);
    double input_radios();
    int input_norm();
    void output(std::vector<City> resultCities, const City& selectedCity);
};