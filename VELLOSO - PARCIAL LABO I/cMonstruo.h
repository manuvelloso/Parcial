#pragma once
class cPersona;
#include <iostream>

class cMonstruo
{
protected:
	int vida;
	int ataque;
	const int nombre; //es el ID del monstruo
	static int contador;
	bool vivo;

	friend void RecibirDañoMonstruo(cMonstruo* M, int daño);
	//friend void cPersona::RecibirDaño(int DañoBase, cMonstruo* M);

public:
	void RecibirDañoMonstruo(int daño);
	cMonstruo();
	virtual ~cMonstruo();
	virtual void Atacar(cPersona* P) = 0;
	bool getVivo() { return vivo; }
	void setVivo(bool alive) { vivo = alive; contador--; }
	bool operator!=(bool alive) { return vida != alive; }
	int getVida() { return vida; }
};

