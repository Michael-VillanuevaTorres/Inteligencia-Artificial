#ifndef NODO.H
#define NODO.H

#include <iostream>
#include <utility>
#include <string>
#include <map>



class nodo{
    
    private:
        int heuristica;
        std::string nombre;
    
    public:
        nodo(std::string nombre, int h);
        std::pair<int,nodo* > padre;   //Guarda a su padre
        std::map<int, nodo*> vecinos;  // Sus nodos vecinos
        void agregar_nodo(int costo, nodo*);
        std::string get_N();
        int get_H();
        
        
};




#endif