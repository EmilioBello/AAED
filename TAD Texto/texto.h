#ifndef _TEXTO_H_
#define _TEXTO_H_

#include <iostream>

#include "listaEnla.h"

using namespace std;

class Texto{
	public:
		Texto(const Lista<Lista<char>>& nuevoTexto);
		void MostrarTexto();
		
	private:
		Lista<Lista<char>> texto;
};

#endif
