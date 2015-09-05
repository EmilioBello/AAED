#ifndef _TADTREN_H_
#define _TADTREN_H_

#include "pilaEnla.h"
#include "vagon.h"

class Tren{
	public:
		Tren();
		void mueveIzq();
		void mueveDer();
		void eliminar();
		void insertar(const Vagon& elemento);
		Vagon observar() const;
		bool vacio();
		
		//Estos no entran dentro:
		Pila<Vagon> dameDer();
		Pila<Vagon> dameIzq();
		
	private:
		Pila<Vagon> izq, der;
};

#endif
