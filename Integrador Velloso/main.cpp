#include <iostream>
#include "cPersona.h"

using namespace std;
/*Generar un main en donde se hará pelear la persona contra un enemigo de cada tipo HASTA que alguno de los
2 muera, en caso de que la persona muera, genere una nueva o revivala (NO UTILIZAR CIN). Demostrar el
funcionamiento de todo */
int main()
{
	cMonstruo* m1 = new cEsbirroMago();
	cMonstruo* m2 = new cEsbirroEspadachin();
	cMonstruo* m3 = new cJefe();
	cMonstruo* m4 = new cElite();

	cPersona* yo = new cPersona("Pepe");

	do
	{
		yo->Atacar(m1);
		m1->Atacar(yo);

		try { yo->VerificarVida(); }
		catch (exception* ex)
		{
			delete ex;
			yo = new cPersona(*yo); //la revivo
		}
		if (!m1->getVivo())
		{
			m1->setVivo(false);
		}

	} while (m1->getVivo() || yo->getVivo());

	do
	{
		yo->Atacar(m2);
		m2->Atacar(yo);

		try { yo->VerificarVida(); }
		catch (exception* ex)
		{
			delete ex;
			yo = new cPersona(*yo); //la revivo
		}
		if (!m2->getVivo())
		{
			m2->setVivo(false);
		}

	} while (m2->getVivo() || yo->getVivo());

	do
	{
		yo->Atacar(m3);
		m3->Atacar(yo);

		try { yo->VerificarVida(); }
		catch (exception* ex)
		{
			delete ex;
			yo = new cPersona(*yo); //la revivo
		}
		if (!m3->getVivo())
		{
			m3->setVivo(false);
		}

	} while (m3->getVivo() || yo->getVivo());

	do
	{
		yo->Atacar(m4);
		m4->Atacar(yo);

		try { yo->VerificarVida(); }
		catch (exception* ex)
		{
			delete ex;
			yo = new cPersona(*yo); //la revivo
		}
		if (!m4->getVivo())
		{
			m4->setVivo(false);
		}

	} while (m4->getVivo() || yo->getVivo());

	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete yo;
	return 0;
}