#ifndef BUSQUEDA_P.H
#define BUSQUEDA_P.H

#include <iostream>
#include "nodo.h"
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <algorithm> 

class busqueda_P{

    private:
        std::stack<std::string> camino_n;
        std::map<std::string,int > expandidos;
        std::vector<std::string> visitados;
        int siguiente(nodo*);
        int cost;
    public:
        busqueda_P(nodo* inicial,nodo* final);
        void virtual camino();
        void virtual costo();
        void virtual n_expandidos();

};  


  
   
#endif