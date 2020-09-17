#include <iostream>
#include <vector>
#include "explicitEuler.h"
#include <fstream>


int main() {

    // Variable declaration
    size_t nx;
    double length, totalTime, c, cfl;

    //Prompt the user for input
    std:: cout << "[length totalTime c cfl nx] (without brackets) : " << std::endl;
    std::cin >> length >> totalTime >> c >> cfl >> nx;

    // Init file I/O object
    std::ofstream fileStream("../results/wave1DOutput.dat");

    if (!fileStream)
    {
        // Print an error and exit
        std::cerr << "Error while writing to file" << std::endl;
        return 1;
    }

    // writing simulation conditions to file
    fileStream << "length: " << length << " totalTime: " << totalTime << 
                " c: " << c << " cfl: " << cfl << " nx: " << nx << "\n\n\n";

    // writing x coordinates to file
    double dx = length/nx;
    fileStream << "X coordinates : ";
    for (size_t i=0; i < nx; i++ ){
        fileStream << i*dx << " ";
    }
    fileStream << "\n\n\n";

    // writing wave equation results to file
    auto u = explicitEuler(length,totalTime,c,cfl,nx);
    for (auto rows : u) {

        for (double values : rows){   
            fileStream << values << " ";
        }

        fileStream << "\n";
    }

    fileStream.close();
    
    return 0;
}


