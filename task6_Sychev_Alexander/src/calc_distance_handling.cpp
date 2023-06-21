#pragma once
#include "calc_distance_handling.h"


double Calc_distance_handling::euclideanDistance(double x1, double y1, double x2, double y2)
{
	return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}


double Calc_distance_handling::chebyshevDistance(double x1, double y1, double x2, double y2)
{
	return std::max(std::abs(x1 - x2), std::abs(y1 - y2));
}


double Calc_distance_handling::manhattanDistance(double x1, double y1, double x2, double y2)
{
	return std::abs(x1 - x2) + std::abs(y1 - y2);
}

double Calc_distance_handling::calculateDistance(double x1, double y1, double x2, double y2, int norm)
{
    std::map<int, std::function<double(double, double, double, double)>> distanceCalculations = {
        {0, [this](double x1, double y1, double x2, double y2) { return euclideanDistance(x1, y1, x2, y2); }},
        {1, [this](double x1, double y1, double x2, double y2) { return chebyshevDistance(x1, y1, x2, y2); }},
        {2, [this](double x1, double y1, double x2, double y2) { return manhattanDistance(x1, y1, x2, y2); }}
    };

    auto distanceCalculation = distanceCalculations.find(norm);
    if (distanceCalculation != distanceCalculations.end()) {
        return distanceCalculation->second(x1, y1, x2, y2);
    }
    else {
        throw std::invalid_argument("Invalid norm value");
    }
}