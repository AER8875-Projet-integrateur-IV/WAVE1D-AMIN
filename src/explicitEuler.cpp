#include <vector>


std::vector<std::vector<double>> explicitEuler( const double length,
                                                const double totalTime,
                                                const double c,
                                                const double cfl,
                                                const size_t nx) 

{
    const double dx = length/nx;
    const double dt = cfl*dx/c;
    const size_t nt = (int)((totalTime/dt) + 0.5);

    std::vector<std::vector<double> > u(nt,std::vector<double> (nx,0));

    // Conditions Initiales

    for (size_t ix = 0; ix < u[0].size(); ix++){

        if (dx*ix < 40.0 || dx*ix > 60.0){
            u[0][ix] = 0.0;
        }
        else
            u[0][ix] = 100.0;
    }

    // Euler explicite backward
    for (size_t it = 1 ; it < u.size() ; it++){
        
        //Conditions limites
        u[it-1][0] = u[it-1][u[0].size()-2];
        u[it-1][u[0].size()-1] = u[it-1][1];

        for (size_t ix = 1 ; ix < u[0].size()-1 ; ix++){                            //Boucle for commence a 1 et fini a size()-1 pour etablir les CL

                u[it][ix] = u[it -1][ix] - (c*dt/dx)*(u[it-1][ix] - u[it-1][ix-1]);

            }
        }
        
    return u;
}
