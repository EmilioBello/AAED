#ifndef _PACIENTE_H_
#define _PACIENTE_H_

struct Paciente{
	int gravedad;
	int codigo;
	
	Paciente(int grav = 0, int cod = 0){
		gravedad = grav;
		codigo = cod;
	}
	
	bool operator == (Paciente persona){
		return (codigo == persona.codigo);
	}
};

#endif
