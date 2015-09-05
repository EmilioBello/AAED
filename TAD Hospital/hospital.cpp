#include "hospital.h"

Hospital::Hospital(int tamUCI, int tamPlanta){
	tamMaxUCI = tamUCI;
	tamMaxPlanta = tamPlanta;
	
	tamActualUCI = 0;
	tamActualPlanta = 0;
	transladados = false;
}

void Hospital::ingreso(const Paciente& persona){
	if(persona.gravedad < 6){
		cabe(persona, 'U');
	}
	else{
		cabe(persona, 'P');
	}
}

void Hospital::alta(){
	if(tamActualPlanta != 0){
		Lista<Paciente>::posicion pos = NULL;
		alta(pos);
	}
}

void Hospital::alta(Lista<Paciente>::posicion& pos){
	if(pos == NULL){
		pos = menosGrave(Planta);
	}
	Planta.eliminar(pos);
	tamActualPlanta--;
}

void Hospital::muerte(){
	Lista<Paciente>::posicion pos = NULL;
	muerte(pos);
}

void Hospital::muerte(Lista<Paciente>::posicion& pos){
	if(tamActualUCI > 0){
		if(pos == NULL){
			pos = masGrave(UCI);			
		}
		UCI.eliminar(pos);
		tamActualUCI--;
		
		if(transladados > 0){
			transladar();
		}
			
			/*Paciente persona;
			for(Lista<Paciente>::posicion pos = UCI.primera(); pos != UCI.fin(); pos = UCI.siguiente(pos)){
				persona = UCI.elemento(pos);
				
				if(persona.gravedad == 0){
					UCI.eliminar(pos);
					if(transladados > 0){
						transladar();
					}
				}
			}*/
	}	
}

Lista<Paciente> Hospital::pacientesUCI(){
	return UCI;
}

Lista<Paciente> Hospital::pacientesPlanta(){
	return Planta;
}

Lista<Paciente> Hospital::pacientesGravedad(int gravedad){
	Lista<Paciente> pacientes;
	Paciente persona;
	
	for(Lista<Paciente>::posicion pos = Planta.primera(); pos != Planta.fin(); pos = Planta.siguiente(pos)){
		persona = Planta.elemento(pos);
		if(persona.gravedad == gravedad){
			pacientes.insertar(persona, pacientes.fin());
		}
	}
	
	for(Lista<Paciente>::posicion pos = UCI.primera(); pos != UCI.fin(); pos = UCI.siguiente(pos)){
		persona = UCI.elemento(pos);
		if(persona.gravedad == gravedad){
			pacientes.insertar(persona, pacientes.fin());
		}
	}
}

Hospital::~Hospital(){
	UCI.~Lista();
	Planta.~Lista();
}

//No necesario, solo para ver que funiona

void Hospital::mostrarTodo(){
	Paciente persona;
	
	cout << "Planta: ";
	mostrar(Planta);
	
	cout << endl << endl;
	
	cout << "UCI: ";	
	mostrar(UCI);
	
	cout << endl << endl;
}

void Hospital::mostrar(const Lista<Paciente>& lista){
	Paciente persona;
	
	for(Lista<Paciente>::posicion pos = lista.primera(); pos != lista.fin(); pos = lista.siguiente(pos)){
		persona = lista.elemento(pos);
		cout << persona.codigo << "(" << persona.gravedad << "), ";
	}
}

//privadas
void Hospital::transladar(){
	Paciente persona;
	
	Lista<Paciente>::posicion pos = masGrave(Planta);
	persona = Planta.elemento(pos);
	
	if(persona.gravedad > 5){
		transladados = false;
	}
	else{
		Planta.eliminar(pos);
		UCI.insertar(persona, UCI.fin());
		tamActualPlanta--;
		tamActualUCI++;
	}
	
	
}

void Hospital::cabe(const Paciente& persona, char opcion){
	int tam = 0;
	if(opcion == 'U'){
		UCI.insertar(persona, UCI.fin());
		tamActualUCI++;
		if(tamActualUCI > tamMaxUCI){
			Lista<Paciente>::posicion pos = menosGrave(UCI);
			Paciente transladado = UCI.elemento(pos);
			UCI.eliminar(pos);
			cabe(transladado, 'P');
			transladados = true;
			tamActualUCI--;
		}
	}
	else{
		Planta.insertar(persona, Planta.fin());
		tamActualPlanta++;
		if(tamActualPlanta > tamMaxPlanta){			
			alta();
		}
	}
}

Lista<Paciente>::posicion Hospital::menosGrave(const Lista<Paciente>& lista){
	int gravedad = 0;
	Paciente persona;
	Lista<Paciente>::posicion posGravedad;
	
	for(Lista<Paciente>::posicion pos = lista.primera(); pos != lista.fin(); pos = lista.siguiente(pos)){
		persona = lista.elemento(pos);
		if(gravedad < persona.gravedad){
			gravedad = persona.gravedad;
			posGravedad = pos;
		}
	}
	
	return posGravedad;
}

Lista<Paciente>::posicion Hospital::masGrave(const Lista<Paciente>& lista){
	int gravedad = 10;
	Paciente persona;
	Lista<Paciente>::posicion posGravedad;
	
	for(Lista<Paciente>::posicion pos = lista.primera(); pos != lista.fin(); pos = lista.siguiente(pos)){
		persona = lista.elemento(pos);
		if(gravedad > persona.gravedad){
			gravedad = persona.gravedad;
			posGravedad = pos;
		}
	}
	
	return posGravedad;
}
