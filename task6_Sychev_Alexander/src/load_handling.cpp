#pragma once
#include "load_handling.h"

std::vector<City> Load_handling::loadCities(const std::string& filename)
{
    std::vector<City> cities;
    std::ifstream file(filename);
    std::string line;


    try {
        while (std::getline(file, line)) {
            City city;
            city.name = line;
            std::getline(file, line);
            std::istringstream iss(line);

            std::string dash;

            // Extract x and y coordinates using std::stod
            iss >> city.x >> dash >> city.y;

            cities.push_back(city);
        }
    } catch (const std::exception& e) {
        // Exception occurred, handle the error here
        throw e;
    }

    return cities;
}