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

//void cPersona::RecibirDaño(int DañoBase, cMonstruo* M)
//{
//	int daño = 0;
//	if (dynamic_cast<cEsbirroMago*>(M) != NULL) //si el mostruo es mago
//	{
//		daño = DañoBase - inteligencia / 2;
//	}
//	else if (dynamic_cast<cJefe*>(M) != NULL) //si el mostruo es un jefe
//	{
//		daño = DañoBase - armadura / 4 - inteligencia / 4;
//	}
//	else if (dynamic_cast<cEsbirroEspadachin*>(M) != NULL || dynamic_cast<cElite*>(M) != NULL) //si el monstruo es un espadachin o un elite
//	{
//		daño = DañoBase - armadura;
//	}
//	else
//		daño = 0;
//	if (daño < 0)
//		daño = 0; //soy inmune
//	setVida(daño);
//}

void cPersona::Atacar(cMonstruo* M)
{
	int daño = poderAtaque + fuerza + inteligencia;
	M->RecibirDañoMonstruo(daño);
}

void RecibirDaño(cPersona* P, int DañoBase, cMonstruo* M)
{
	int daño = 0;
	if (dynamic_cast<cEsbirroMago*>(M) != NULL) //si el mostruo es mago
	{
		daño = DañoBase - P->inteligencia / 2;
	}
	else if (dynamic_cast<cJefe*>(M) != NULL) //si el mostruo es un jefe
	{
		daño = DañoBase - P->armadura / 4 - P->inteligencia / 4;
	}
	else if (dynamic_cast<cEsbirroEspadachin*>(M) != NULL || dynamic_cast<cElite*>(M) != NULL) //si el monstruo es un espadachin o un elite
	{
		daño = DañoBase - P->armadura;
	}
	else
		daño = 0;
	if (daño < 0)
		daño = 0; //soy inmune
	P->setVida(daño);
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

int& operator-(cPersona& P, int daño)
{
	P.setVida(daño);
	return P.vidaActual;
}
