#pragma once

#include <vector>

std::vector<std::vector<double>> explicitEuler( const double length,
                                                const double totalTime,
                                                const double c,
                                                const double cfl,
                                                const size_t nx);