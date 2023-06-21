#pragma once
#include "search_handling.h"

bool Search_handling::isWithinRadius(const City& city, const City& selectedCity, double radius, int norm)
{
	return calc_distance.calculateDistance(selectedCity.x, selectedCity.y, city.x, city.y, norm) <= radius;
}


std::vector<City> Search_handling::searchCities(const std::vector<City>& cities, const City& selectedCity, double radius, int norm)
{
    std::vector<City> resultCities;

    // Find cities within the given radius using copy_if and back_inserter
    std::copy_if(cities.begin(), cities.end(), std::back_inserter(resultCities),
        [&](const City& city) {
            return city.name != selectedCity.name && isWithinRadius(city, selectedCity, radius, norm);
        });

    // Sort the result cities based on their distance from the selected city
    std::sort(resultCities.begin(), resultCities.end(), [&](const City& city1, const City& city2) {
        return calc_distance.calculateDistance(selectedCity.x, selectedCity.y, city1.x, city1.y, norm) <
            calc_distance.calculateDistance(selectedCity.x, selectedCity.y, city2.x, city2.y, norm);
        });

    return resultCities;
}