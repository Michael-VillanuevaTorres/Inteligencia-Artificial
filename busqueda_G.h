#ifndef BUSQUEDA_G.H
#define BUSQUEDA_G.H

#include <iostream>
#include "nodo.h"
#include <vector>


class busqueda_G{

    private:
        std::vector<std::string> camino_n;
        int cost;
        std::map<std::string,int > expandidos;
        int mejor(nodo* aux);
    public:
        busqueda_G(nodo* inicial,nodo* final);
        void virtual camino();
        void virtual costo();
        void virtual n_expandidos();
};  


  
   
#endif