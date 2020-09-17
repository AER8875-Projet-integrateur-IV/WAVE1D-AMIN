#include <iostream>
#include <vector>
#include "explicitEuler.h"


int main() {

    const size_t nx = 61;
    const double length = 100.0;
    const double totalTime = 0.25;
    const double c = 300;
    const double cfl = 0.9;


    auto u = explicitEuler(length,totalTime,c,cfl,nx);
    for (auto rows : u) {

        for (double values : rows){
            std::cout << values << " ";
        }

        std::cout << std::endl;
    }
    
    return 0;
}


