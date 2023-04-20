#include "busqueda_G.h"




busqueda_G::busqueda_G(nodo* inicial, nodo* final){
    
    std::cout<<"Busqueda gready"<<std::endl;
    int prox;
    nodo* actual=inicial;
    cost=0;
    while(!actual->vecinos.empty() and actual!=final){  
        camino_n.push_back(actual->get_N()); // Se guarda el camino recorrido
        prox=mejor(actual);// Sacamos el proximo nodo
        expandidos[actual->get_N()]++; // Dejamos constancia que actual se expandio
        cost=cost+prox; // Vamos obteniendo el costo 
        actual=actual->vecinos.at(prox); 
    }
    
    camino_n.push_back(actual->get_N());

    if (actual==final){ //Si se encontro la solucion, se genera la salida que se pide en la tarea
        std::cout<<"Nodo Encontrado"<<std::endl;
        camino();
        costo();
        n_expandidos();
    }else{
        std::cout<<"Nodo No Encontrado"<<std::endl;
    }
    
}

int busqueda_G::mejor(nodo* aux){ //Sacamos al mejor sucesor comparando las heuristicas de estos
    int m=INT8_MAX;
    int a=0;
    for ( auto it= aux->vecinos.begin();it!=aux->vecinos.end(); it++){
        if (it->second->get_H()<m){
            m=it->second->get_H();
            a=it->first;
        }
    }
    return a;
}
void busqueda_G::camino(){
    std::cout<<"Camino: ";
    for (int i = 0; i < camino_n.size(); i++){
        std::cout<<camino_n[i]<<" ";
    }
    std::cout<<std::endl;
}
        
void busqueda_G::costo(){
    std::cout<<"Costo: "<<cost<<std::endl;
}


void busqueda_G::n_expandidos(){ 
    int total=0;
    for (auto it = expandidos.begin(); it != expandidos.end(); it++){
        std::cout<<it->first<<" expanciones= "<<it->first<<std::endl;
        total+=it->second;
    }
    std::cout<<"Expanciones totales = "<<total<<std::endl;

}

