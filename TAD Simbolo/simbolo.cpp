#include "simbolo.h"

Simbolo::Simbolo(){
}

void Simbolo::add(char trazo){
	figura.insertar(trazo, figura.fin());
}

void Simbolo::deshacer(){
	Lista<char>::posicion pos = figura.fin();
	pos = figura.anterior(pos);
	figura.eliminar(pos);
}

Lista<char> Simbolo::simetriaX(){
	return simetria('X');
}

Lista<char> Simbolo::simetriaY(){
	return simetria('Y');
}

Lista<char> Simbolo::simetriaXY(){
	return simetria('A'); //A = Ambos
}

//Si no se le pasan parametros a buscar, se sobrecarga y se pasa a figura como parametro
void Simbolo::mostrar(){
	mostrar(figura);
}

void Simbolo::mostrar(const Lista<char>& figuraMostrar){
	Lista<char>::posicion pos = figuraMostrar.primera();
	
	while(pos != figuraMostrar.fin()){
		cout << figuraMostrar.elemento(pos);
		pos = figuraMostrar.siguiente(pos);
	}
	cout << endl;
}

//Funcion privada que realiza todas las simetrias segun la opcion que
//le pase, X = simetria eje X, Y = simetria eje Y y A = ambas simetrias
Lista<char> Simbolo::simetria(char opcion){	
	//Lista<char> simetrica(figura); //No funciona bien el constructor de copia de esta reprensentacion	
	Lista<char> simetrica;
	
	for(Lista<char>::posicion pos = figura.primera(); pos != figura.fin(); pos = figura.siguiente(pos)){
		simetrica.insertar(figura.elemento(pos), simetrica.fin());
	}
	
	Lista<char>::posicion pos = simetrica.primera();
	
	while(pos != simetrica.fin()){
		
		if(opcion == 'Y' || opcion == 'A'){// A = Ambos
		
			if(simetrica.elemento(pos) == 'D'){
				simetrica.elemento(pos) = 'I';
			}
			else if(simetrica.elemento(pos) == 'I'){
				simetrica.elemento(pos) = 'D';
			}
		}
		
		if(opcion == 'X' || opcion == 'A'){// A = Ambos
			
			if(simetrica.elemento(pos) == 'B'){
				simetrica.elemento(pos) = 'S';
			}
			else if(simetrica.elemento(pos) == 'S'){
				simetrica.elemento(pos) = 'B';
			}
		}
		
		pos = simetrica.siguiente(pos);
	}
	
	return simetrica;
}
