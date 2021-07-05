#include "cPersona.h"
#include "cElite.h"
#include "cEsbirroEspadachin.h"
#include "cEsbirroMago.h"
#include "cJefe.h"

cPersona::cPersona(string nombre)
{
	this->nombre = nombre;
	this->fuerza = rand() % 101;
	this->inteligencia = rand() % 101;
	this->armadura = rand() % 101;
	this->poderAtaque = rand() % 101;
	this->vidaMax = rand() % 101;
	this->vidaActual = vidaMax;
	this->vivo = true;
}

//void cPersona::RecibirDa�o(int Da�oBase, cMonstruo* M)
//{
//	int da�o = 0;
//	if (dynamic_cast<cEsbirroMago*>(M) != NULL) //si el mostruo es mago
//	{
//		da�o = Da�oBase - inteligencia / 2;
//	}
//	else if (dynamic_cast<cJefe*>(M) != NULL) //si el mostruo es un jefe
//	{
//		da�o = Da�oBase - armadura / 4 - inteligencia / 4;
//	}
//	else if (dynamic_cast<cEsbirroEspadachin*>(M) != NULL || dynamic_cast<cElite*>(M) != NULL) //si el monstruo es un espadachin o un elite
//	{
//		da�o = Da�oBase - armadura;
//	}
//	else
//		da�o = 0;
//	if (da�o < 0)
//		da�o = 0; //soy inmune
//	setVida(da�o);
//}

void cPersona::Atacar(cMonstruo* M)
{
	int da�o = poderAtaque + fuerza + inteligencia;
	M->RecibirDa�oMonstruo(da�o);
}

void RecibirDa�o(cPersona* P, int Da�oBase, cMonstruo* M)
{
	int da�o = 0;
	if (dynamic_cast<cEsbirroMago*>(M) != NULL) //si el mostruo es mago
	{
		da�o = Da�oBase - P->inteligencia / 2;
	}
	else if (dynamic_cast<cJefe*>(M) != NULL) //si el mostruo es un jefe
	{
		da�o = Da�oBase - P->armadura / 4 - P->inteligencia / 4;
	}
	else if (dynamic_cast<cEsbirroEspadachin*>(M) != NULL || dynamic_cast<cElite*>(M) != NULL) //si el monstruo es un espadachin o un elite
	{
		da�o = Da�oBase - P->armadura;
	}
	else
		da�o = 0;
	if (da�o < 0)
		da�o = 0; //soy inmune
	P->setVida(da�o);
}

ostream& operator<<(ostream& out, cPersona* P)
{
	out << "Nombre: " << P->nombre << endl;
	out << "\tFuerza: " << P->fuerza << endl;
	out << "\tInteligencia: " << P->inteligencia << endl;
	out << "\tArmadura: " << P->armadura << endl;
	out << "\tPoder de ataque: " << P->poderAtaque << endl;
	out << "\tVida actual: " << P->vidaActual << endl;

	return out;
}

int& operator-(cPersona& P, int da�o)
{
	P.setVida(da�o);
	return P.vidaActual;
}
