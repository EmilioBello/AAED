#include "tad.h"

Tren::Tren(){
	
}

void Tren::mueveDer(){
	if(!izq.vacia()){
		Vagon nuevoActivo = izq.tope();
		izq.pop();
		der.push(nuevoActivo);
	}
}

void Tren::mueveIzq(){
	if(!der.vacia()){
		Vagon nuevoActivo = der.tope();
		der.pop();
		izq.push(nuevoActivo);
	}
}

bool Tren::vacio(){
	return der.vacia();
}

void Tren::insertar(const Vagon& elemento){
	der.push(elemento);
}

void Tren::eliminar(){
	if(!vacio()){
		der.pop();
		
		if(der.vacia()){
			Vagon nuevoActivo = izq.tope();
			izq.pop();
			der.push(nuevoActivo);
		}
	}
}

Vagon Tren::observar() const{
	if(!vacio()){
		return der.tope();
	}
	else{
		return NULL;
	}	
}

//Estos no entran en la especificacion del tad

Pila<Vagon> Tren::dameDer(){
	return der;
}

Pila<Vagon> Tren::dameIzq(){
	return izq;
}
