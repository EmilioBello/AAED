#ifndef _SIMBOLO_H_
#define _SIMNOLO_H_

#include <iostream>

#include "listaEnla.h"

using namespace std;

class Simbolo{
	public:
		Simbolo();
		void add(char trazo);
		void deshacer();
		
		//simetrias
		Lista<char> simetriaX();
		Lista<char> simetriaY();
		Lista<char> simetriaXY();
		
		//mostrar para comprobar que todo esta correcto, no necesario por enunciado problema
		void mostrar();
		void mostrar(const Lista<char>& figuraMostrar);
		
	private:
		Lista<char> figura;
		
		Lista<char> simetria(char opcion);
};

#endif
