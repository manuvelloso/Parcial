#include "cMazmorra.h"

cMazmorra::cMazmorra(cPersona* P, int TAM)
{
	this->TAM = TAM;
	this->CA = 0;
	Lista = new cMonstruo * [TAM];
	for (int i = 0; i < TAM; i++)
		Lista[i] = NULL;
}

cMazmorra::~cMazmorra()
{
	if (Lista != NULL)
	{
		for (int i = 0; i < CA; i++)
			if (Lista[i] != NULL)
				delete Lista[i];
		delete[] Lista;
	}
}

void cMazmorra::Agregar(cMonstruo* P)
{
	if (CA == TAM)
	{
		throw new exception("no hay lugar");
		return;
	}
	if (P == NULL)
	{
		throw new exception("Es null");
		return;
	}
	Lista[CA] = P;
	CA++;
}

void cMazmorra::Eliminar(int pos)
{
	cMonstruo* aux = Lista[pos];
	for (int i = pos; i < CA - 1; i++)
	{
		Lista[i] = Lista[i + 1];
	}
	CA--;
	Lista[CA] == NULL;
	delete aux;
}

void cMazmorra::Pelear()
{
	for(int i = 0; i<CA; i++)
	{

		Persona->Atacar(Lista[i]);
		Lista[i]->Atacar(Persona);

		try { Persona->VerificarVida(); }
		catch (exception* ex)
		{
			delete ex;
			Persona = new cPersona(*Persona); //la revivo
		}
		if (!Lista[i]->getVivo())
		{
			Lista[i]->setVivo(false);
		}
	}
}
