#include "nodo.h"

nodo::nodo(std::string n,int h){
    heuristica=h;
    nombre=n;
}

void nodo::agregar_nodo(int costo, nodo* n){
    nodo* aux = n;
    vecinos[costo]= aux ;
}

std::string nodo::get_N(){
    return nombre;
}

int nodo::get_H(){
    return heuristica;
}


