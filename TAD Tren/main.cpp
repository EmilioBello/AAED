#include <iostream>

#include "tad.h"
#include "vagon.h"
#include "pilaEnla.h"

using namespace std;

void elementos(Tren trenecito);

int main(){
	
	int opcion;
	
	Tren trenecito;
	
	do{
		do{
			elementos(trenecito);
			
			cout << "Selecciona una opcion: " << endl;
			cout << "(1)Inserta un nuevo vagon" << endl;
			cout << "(2)Mover a la derecha un elemento" << endl;
			cout << "(3)Mover a la izquierda un elemento" << endl;
			cout << "(4)Eliminar el vago activo" << endl;
			
			cin >> opcion;
		}while(opcion < 1 || opcion > 4);
		
		switch(opcion){
			case 1:
				int elemento;
				
				cout << "Inserta un elemento para un nuevo vagon: ";
				cin >> elemento;
				
				Vagon vag;
				vag.numero = elemento;
				trenecito.insertar(vag);
				break;
			case 2:
				trenecito.mueveDer();
				break;
			case 3:
				trenecito.mueveIzq();
				break;
			case 4:
				trenecito.eliminar();
		}
		
	}while(true);
	
	return 0;
}

void elementos(Tren trenecito){
	Pila<Vagon> izquierda = trenecito.dameIzq();
	Pila<Vagon> derecha = trenecito.dameDer();
	Pila<Vagon> auxiliar;
	
	while(!izquierda.vacia()){
		auxiliar.push(izquierda.tope());
		izquierda.pop();
	}
	
	while(!auxiliar.vacia()){
		cout << auxiliar.tope().numero;
		auxiliar.pop();
	}
	
	while(!derecha.vacia()){
		cout << derecha.tope().numero;
		derecha.pop();
	}	
	
	cout << endl;
	cout << endl;
}
















