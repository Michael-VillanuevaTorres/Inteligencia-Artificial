#ifndef BUSQUEDA_A.H
#define BUSQUEDA_A.H

#include <iostream>
#include "nodo.h"
#include <vector>
#include <stack>


class busqueda_A{

    private:
        std::map<nodo*, int > lista;
        std::stack<std::string> camino_n;
        std::map<std::string,int > expandidos;
        nodo* mejor();
        int cost;
    public:
        busqueda_A(nodo* inicial,nodo* final);
        void virtual camino();
        void virtual costo();
        void virtual n_expandidos();

};  


  
   
#endif