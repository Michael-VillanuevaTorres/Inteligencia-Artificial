#include "busqueda_C.h"



busqueda_C::busqueda_C(nodo* inicial, nodo* final){ 
    std::cout<<"Busqueda de costo uniforme"<<std::endl;
    
    nodo* actual=inicial;
    actual->padre={0,NULL};
    lista[actual]=0;
    nodo* hijo;
    int costo_acumulado;
    while(!lista.empty() and actual!=final){
        lista.erase(actual); //Se borra el nodo actual de la lista ya que se expande
        for(auto n=actual->vecinos.begin(); n!= actual->vecinos.end(); n++){ // Se ven sus hijos y se guardan en la lista con sus costos
            hijo= n->second;
            costo_acumulado=n->first+ actual->padre.first;
            if (lista.count(hijo)==0){ // Si no esta dentro de la lista se guarda el hijo y su costo
                lista[hijo]=costo_acumulado;
                hijo->padre={costo_acumulado,actual};
            }else{
                if (lista[hijo] > costo_acumulado ){// Si esta se compraran los costos y se quedan con el mejor 
                    lista[hijo]=costo_acumulado;                
                    hijo->padre={costo_acumulado,actual};
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

nodo* busqueda_C::mejor(){ // Se obtiene el mejor sucesor comparando los costos en la lista
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

void busqueda_C::camino(){
    int tam=camino_n.size();
    std::cout<<"Camino: ";
    for (int i = 0; i < tam; i++){
        std::cout<<camino_n.top() <<" ";
        camino_n.pop();
    }
    std::cout<<std::endl;
}
        
void busqueda_C::costo(){
    std::cout<<"Costo: "<<cost<<std::endl;
}


void busqueda_C::n_expandidos(){ 

    int total=0;
    for (auto it = expandidos.begin(); it != expandidos.end(); it++){
        std::cout<<it->first<<" expanciones= "<<it->second <<std::endl;
        total+=it->second;
    }
    std::cout<<"Expanciones totales = "<<total<<std::endl;


}


