#include "io_handling.h"

City IO_handling::input_cityName(const std::vector<City>& cities)
{
    std::string cityName;
    City selectedCity;
    bool flag = false;

    while (!flag)
    {
        std::cout << "Please enter selected city name (with line break after it):" << std::endl;
        std::getline(std::cin, cityName);

        auto it = std::find_if(cities.begin(), cities.end(), [&](const City& city) {
            return city.name == cityName;
            });

        if (it == cities.end() && cityName != "0")
        {
            std::cout << "ERROR: \"" << cityName << "\" isn't found in the city list. Please try again." << std::endl;
        }
        else
        {
            flag = true;
            if (cityName != "0")
                selectedCity = *it;
        }
    }
    return selectedCity;
}


double IO_handling::input_radios()
{
    double radius;
    bool flag = false;

    while (!flag)
    {
        std::cout << "Please enter the wanted radius:" << std::endl;
        try
        {
            std::cin >> radius;
            if (std::cin.fail())
            {
                throw std::invalid_argument("Invalid input");
            }
        }
        catch (const std::exception& e)
        {
            // Exception occurred, handle the error here
            throw e;
        }

        if (radius < 0)
        {
            std::cout << "ERROR: incorect radius. Please try again." << std::endl;
        }
        else
        {
            flag = true;
        }
    }
    return radius;
}


int IO_handling::input_norm()
{
    int norm;
    bool flag = false;

    while (!flag)
    {
        std::cout << "Please enter the wanted norm (0 - L2, Euclidean distance, 1 - Linf, Chebyshev distance, 2 - L1, Manhattan distance):" << std::endl;
        try
        {
            std::cin >> norm;
            if (std::cin.fail())
            {
                throw std::invalid_argument("Invalid input");
            }
        }
        catch (const std::exception& e)
        {
            // Exception occurred, handle the error here
            throw e;
        }

        if (norm < 0 || norm > 2)
        {
            std::cout << "ERROR: incorect norm. Please try again." << std::endl;
        }
        else
        {
            flag = true;
        }
    }
    return norm;
}

void IO_handling::output(std::vector<City> resultCities, const City& selectedCity)
{
    // Print the search result
    std::cout << "Search result:" << std::endl;
    std::cout << resultCities.size() << " city/cities found in the given radius." << std::endl;
    int northCount = std::count_if(resultCities.begin(), resultCities.end(), [&](const City& city) {
        return city.y < selectedCity.y;
        });
    std::cout << northCount << " cities are to the north of the selected city." << std::endl;
    std::cout << "City list" << std::endl;

    for (const auto& city : resultCities) {
        std::cout << city.name << std::endl;
    }
}