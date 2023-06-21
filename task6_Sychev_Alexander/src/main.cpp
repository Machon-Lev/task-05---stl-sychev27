#pragma once
#include "load_handling.h"
#include "search_handling.h"
#include "io_handling.h"

int main() {
    Load_handling load_handling;
    Search_handling search_handling;
    IO_handling io_handling;
    std::vector<City> cities;
    std::vector<City> resultCities;
    City selectedCity;
    double radius;
    int norm;

    try
    {
        cities = load_handling.loadCities("data.txt");
    } catch (const std::exception& e) 
    {
        // Exception occurred, handle the error here
        std::cout << "Exception occurred while loading cities: " << e.what() << std::endl;
        return 1;
    }

    selectedCity = io_handling.input_cityName(cities);

    // Main loop to continuously ask the user for city name, radius, and norm
    while (selectedCity.name != "")
    {
        try
        {
            radius = io_handling.input_radios();
            norm = io_handling.input_norm();
        }
        catch (const std::exception& e)
        {
            // Exception occurred, handle the error here
            std::cout << "Input exception " << e.what() << std::endl;
            return 1;
        }
        std::cin.ignore(); // Ignore the newline character

        resultCities = search_handling.searchCities(cities, selectedCity, radius, norm);

        io_handling.output(resultCities, selectedCity);

        selectedCity = io_handling.input_cityName(cities);
    }

    std::cout << "Bye" << std::endl;

    return 0;
}