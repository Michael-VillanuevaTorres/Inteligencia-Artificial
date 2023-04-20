
#include <iostream>
#include <fstream>
#include <sstream>
#include "nodo.h"
#include "busqueda_C.h"
#include "busqueda_G.h"
#include "busqueda_A.h"
#include "busqueda_P.h"

int costo(std::string s,int ver){  //Int ver es para diferenciar los espacios entre la entrada de los vectores y las conexiones
  int cost;
  std::string s_cost;
  if(ver==1)s_cost = s.substr(1, s.size());
  else s_cost = s.substr(5, s.size());
  std::istringstream ss(s_cost);
  ss>>cost;
  return cost;
}

int main(int argc,char *argv[] ){
  

  //Obteniendo la informacion de los nodos dentro del txt
  std::ifstream texto(argv[1]);
  std::string aux,N_inicio,N_final;
  //Nodo inicial y final 
  getline(texto,aux);
  N_inicio=aux[6];
  getline(texto,aux);
  N_final=aux[6];

  //Generando los nodos
  std::map<std::string, nodo* > nodos;  
  while (getline(texto,aux) and aux[1]!=','){
    std::string letra; 
    letra=aux[0];
    nodo* nodus = new nodo(letra,costo(aux,1));
    nodos[letra] = nodus;
  }
  
  //Conexion entre nodos, Generando los caminos
  std::string nodo1,nodo2; 
  nodo1=aux[0];
  nodo2=aux[3];
  nodos[nodo1]->agregar_nodo(costo(aux,0),nodos[nodo2]);
  
  while (getline(texto,aux)){
    nodo1=aux[0];
    nodo2=aux[3];
    nodos[nodo1]->agregar_nodo(costo(aux,0),nodos[nodo2]);
  }
  
  nodo* nodo_inicial= nodos[N_inicio];
  nodo* nodo_final= nodos[N_final]; 

  busqueda_A A(nodo_inicial,nodo_final); // A*
  std::cout<<std::endl;
  busqueda_C C(nodo_inicial,nodo_final); // Costo uniforme
  std::cout<<std::endl;
  busqueda_G G(nodo_inicial,nodo_final); // Gready
  std::cout<<std::endl;
  busqueda_P P(nodo_inicial,nodo_final); // Profundidad
  
  return 0;
}
