#ifndef _HOSPITAL_H_
#define _HOSPITAL_H_

#include <iostream>

#include "listaEnla.h"
#include "paciente.h"

using namespace std;

class Hospital{
	public:
		Hospital(int tamUCI, int tamPlanta);
		void ingreso(const Paciente& persona);
		
		void alta();
		void alta(Lista<Paciente>::posicion& pos);
		void muerte();
		void muerte(Lista<Paciente>::posicion& pos);
		
		Lista<Paciente> pacientesUCI();
		Lista<Paciente> pacientesPlanta();
		Lista<Paciente> pacientesGravedad(int gravedad);
		
		~Hospital();
		
		//No necesario, solo para ver que funciona
		void mostrarTodo();
		void mostrar(const Lista<Paciente>& lista);
		
	private:
		Lista<Paciente> Planta;
		Lista<Paciente> UCI;
		
		int tamMaxUCI, tamMaxPlanta, tamActualUCI, tamActualPlanta;
		bool transladados;
		
		void transladar();
		void cabe(const Paciente& persona, char opcion);
		Lista<Paciente>::posicion menosGrave(const Lista<Paciente>& lista);
		Lista<Paciente>::posicion masGrave(const Lista<Paciente>& lista);
};

#endif
