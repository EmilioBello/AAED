#include <iostream>

#include "simbolo.h"

using namespace std;

int main(){
	int opcion;
	
	Simbolo simbolo;
	
	do{
		do{
			simbolo.mostrar();
			
			cout << "Selecciona una opcion: " << endl;
			cout << "(1)Añadir un trazo" << endl;
			cout << "(2)Deshacer el ultimo trazo" << endl;
			cout << "(3)Mostrar simetria X" << endl;
			cout << "(4)Mostrar simetria Y" << endl;
			cout << "(5)Mostrar simetria XY" << endl;
			
			cin >> opcion;
			
		}while(opcion < 1 || opcion > 5);
		
		switch(opcion){
			case 1:{
				char trazo;
				cout << "Inserta el elemento añadir: ";
				cin >> trazo;
				
				simbolo.add(trazo);
				break;
			}
			
			case 2:{
				simbolo.deshacer();				
				break;
			}
			
			case 3:{
				Lista<char> simetrica = simbolo.simetriaX();
				simbolo.mostrar(simetrica);
				break;
			}
			
			case 4:{
				Lista<char> simetrica = simbolo.simetriaY();
				simbolo.mostrar(simetrica);
				break;
			}
			
			case 5:{
				Lista<char> simetrica = simbolo.simetriaXY();
				simbolo.mostrar(simetrica);
				break;
			}
		}
	}while(true);
	
	return 0;
}
