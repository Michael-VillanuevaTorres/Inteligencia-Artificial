#include "busqueda_A.h"

busqueda_A::busqueda_A(nodo* inicial, nodo* final){
    std::cout<<"Busqueda A*"<<std::endl;
    
    nodo* actual=inicial;
    actual->padre={0,NULL};
    lista[actual]=0;
    cost;
    nodo* hijo;
    int costo_acumulado; 
    while(!lista.empty() and actual!=final){ 
        lista.erase(actual); // Se borra el nodo actual de la lista ya que se expandio
        for(auto n=actual->vecinos.begin(); n!= actual->vecinos.end(); n++){ // Visitamos los hijos del nodo actual expandido
            hijo= n->second;
            costo_acumulado=n->first+ actual->padre.first; // obtenemos el costo acumulado

            if (lista.count(hijo)==0){//Si no esta en la lista
                lista[hijo]=costo_acumulado+hijo->get_H(); // Guardamos el hijo dentro de la lista con el costo acumulado y su heuristica
                hijo->padre={costo_acumulado,actual}; // Se le indica al hijo que su padre es el actual 
            }else{
                if (lista[hijo] > costo_acumulado+hijo->get_H() ){// Si esta se compraran los costos + la heuristica y se quedan con el mejor en la lista 
                    lista[hijo]=costo_acumulado+hijo->get_H();                
                    hijo->padre={costo_acumulado,actual}; // cambiamos al padre
                }
            }
        }
        expandidos[actual->get_N()]++;
        actual=mejor();
    }


    if (actual==final){ //Si se encontro la solucion, se genera la salida que se pide en la tarea
        std::cout<<"Nodo Encontrado"<<std::endl;
        cost=lista[actual];
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

nodo* busqueda_A::mejor(){ // Se obtiene al mejor sucesor sacando el menor numero(costo_acumulado + heuristica) dentro de la lista 
    int m=INT8_MAX;
    nodo* a;
    for ( auto it= lista.begin();it!=lista.end(); it++){
        if (it->second < m){
            m=it->second;
            a=it->first;
        }
    }
    return a;
}




void busqueda_A::camino(){
    int tam=camino_n.size();
    std::cout<<"Camino: ";
    for (int i = 0; i < tam; i++){
        std::cout<<camino_n.top() <<" ";
        camino_n.pop();
    }
    std::cout<<std::endl;
}
        
void busqueda_A::costo(){
    std::cout<<"Costo: "<<cost<<std::endl;
}


void busqueda_A::n_expandidos(){ 

    int total=0;
    for (auto it = expandidos.begin(); it != expandidos.end(); it++){
        std::cout<<it->first<<" expanciones= "<<it->second <<std::endl;
        total+=it->second;
    }
    std::cout<<"Expanciones totales = "<<total<<std::endl;


}