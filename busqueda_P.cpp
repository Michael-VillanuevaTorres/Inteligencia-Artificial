#include "busqueda_P.h"



busqueda_P::busqueda_P(nodo* inicial, nodo* final){

    std::cout<<"Busqueda en profundidad"<<std::endl;
    nodo* actual=inicial;
    actual->padre={0,NULL};
    nodo* hijo;
    int costo_acumulado;
    while(actual!=NULL and actual!=final){ //Iniciamos la busqueda 
        int aux=siguiente(actual);
        if (aux==-1){ // Si es -1 significa que todos sus hijos fueron recorridos y no se encontro el objetivo
            actual=actual->padre.second; // por lo tanto vuelve al padre para seguir buscando
            continue;
        }

        nodo*sig=actual->vecinos[aux]; // Generamos el nodo siguiente 
        expandidos[actual->get_N()]++; // Agregamos su expansion
        visitados.push_back(actual->get_N()); // Indicamos que fue visitado
        costo_acumulado=aux + actual->padre.first;
        sig->padre={costo_acumulado,actual}; //Indicamos al nodo siguiente que su padre es el nodo actual
        actual=sig; 

    }

    if (actual==final){ //Si se encontro la solucion, se genera la salida que se pide en la tarea
        std::cout<<"Nodo Encontrado"<<std::endl;
        cost=costo_acumulado;
        while (actual!=inicial){  
            camino_n.push(actual->get_N());
            actual=actual->padre.second;            
        }
        camino_n.push(actual->get_N());

        camino();
        costo();
        n_expandidos();

    }else{
        std::cout<<"Nodo No Encontrado"<<std::endl;
        cost=0;
    }

}

int busqueda_P::siguiente(nodo* actual){ 
    srand (time(NULL));
    int azar;
    int sig;
    azar=rand() % actual->vecinos.size(); // Se escoje el sucesor al azar
    int aux=0;
    auto it= actual->vecinos.begin();
    while (aux<=azar){
        sig=it->first;
        aux++;
        it++;
    }

    if (std::count(visitados.begin(),visitados.end(),actual->vecinos[sig]->get_N())>0){   // Si ese nodo ya fue visitado busca dentro de los vecinos 
        for (auto p= actual->vecinos.begin();p!= actual->vecinos.end(); p++){             // para buscar el siguiente nodo
            sig=p->first;
            if (std::count(visitados.begin(),visitados.end(),actual->vecinos[sig]->get_N())==0){
                break;
            }
        }
    }
    if (std::count(visitados.begin(),visitados.end(),actual->vecinos[sig]->get_N())>0){ // Si salio del for anterior y no entro al if significa que 
        sig==-1;                                                                        // todos sus hijos fueron recorridos y dara como resultado -1            
    }

    return sig;
}




void busqueda_P::camino(){
    int tam=camino_n.size();
    std::cout<<"Camino: ";
    for (int i = 0; i < tam; i++){
        std::cout<<camino_n.top() <<" ";
        camino_n.pop();
    }
    std::cout<<std::endl;
}
        
void busqueda_P::costo(){
    std::cout<<"Costo: "<<cost<<std::endl;
}


void busqueda_P::n_expandidos(){ 
    int total=0;
    for (auto it = expandidos.begin(); it != expandidos.end(); it++){
        std::cout<<it->first<<": "<<it->second <<std::endl;
        total+=it->second;
    }
    std::cout<<"Expanciones totales = "<<total<<std::endl;
}