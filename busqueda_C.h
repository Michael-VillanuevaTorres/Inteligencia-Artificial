#ifndef BUSQUEDA_C.H
#define BUSQUEDA_C.H

#include <iostream>
#include "nodo.h"
#include <vector>
#include <stack>


class busqueda_C{

    private:
        std::map<nodo*, int > lista;
        std::stack<std::string> camino_n;
        std::map<std::string,int > expandidos;
        nodo* mejor();
        int cost;
    public:
        busqueda_C(nodo* inicial,nodo* final);
        void virtual camino();
        void virtual costo();
        void virtual n_expandidos();

};  


  
   
#endif