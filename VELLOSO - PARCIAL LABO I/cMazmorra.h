#pragma once
#include "cPersona.h"
#include "cMonstruo.h"
class cMazmorra
{
	cMonstruo** Lista;
	cPersona* Persona;
	int TAM; 
	int CA;

public:
	cMazmorra(cPersona* P = NULL, int TAM = 50);
	~cMazmorra();
	void Agregar(cMonstruo* P);
	void Eliminar(int pos);
	void Pelear(); //hace que los monstruos peleen con la persona
};

