#include <iostream>

#include "hospital.h"
#include "paciente.h"

using namespace std;

int main(){
	int opcion, codigos = 0;
	
	Hospital hospital(2, 3);
	
	do{
		do{
			hospital.mostrarTodo();
			
			cout << "Selecciona una opcion: " << endl;
			cout << "(1)Ingresar Paciente" << endl;
			cout << "(2)Alta Paciente" << endl;
			cout << "(3)Muerte Paciente" << endl;
			cout << "(4)Mostrar pacientes gravedad determinada" << endl;
			
			cin >> opcion;
			
		}while(opcion < 1 || opcion > 4);
		
		switch(opcion){
			case 1:{
				Paciente persona;
				persona.codigo = codigos;
				codigos++;
				
				cout << "Introduce la gravedad del paciente: ";
				cin >> persona.gravedad;
				
				hospital.ingreso(persona);
				break;
			}
			
			case 2:{
				hospital.alta();			
				break;
			}
			
			case 3:{
				hospital.muerte();
				break;
			}
			
			case 4:{
				int gravedad;
				cout << "Introduce la gravedad de los pacientes: ";
				cin >> gravedad;
				
				Lista<Paciente> lista = hospital.pacientesGravedad(gravedad);
				hospital.mostrar(lista);
				break;
			}
		}
	}while(true);
	
	return 0;
}
