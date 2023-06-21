#pragma once
#include <cmath>
#include <map>
#include <functional>
#include <stdexcept>


static class Calc_distance_handling
{
public:
    // Function to calculate the distance between two points based on the given norm
    double calculateDistance(double x1, double y1, double x2, double y2, int norm);

private:
	// Function to calculate the Euclidean distance
	double euclideanDistance(double x1, double y1, double x2, double y2);

	// Function to calculate the Chebyshev distance
	double chebyshevDistance(double x1, double y1, double x2, double y2);

	// Function to calculate the Manhattan distance
	double manhattanDistance(double x1, double y1, double x2, double y2);
};
