#pragma once
#include <string>
#include <iostream>

using namespace std;

class cMonstruo;

class cPersona
{
private:
	string nombre;
	int fuerza;
	int inteligencia;
	int vidaActual;
	int vidaMax;
	int armadura;
	int poderAtaque;
	bool vivo;
	
protected:
	friend void RecibirDaño(cPersona* P, int DañoBase, cMonstruo* M);
	//friend void cMonstruo::RecibirDañoMonstruo(int daño);
public:
	cPersona(string nombre);
	void Atacar(cMonstruo* M);
	bool operator==(bool alive) { return vivo == alive; }
	friend ostream& operator<<(ostream& out, cPersona* P);
	void setVida(int daño) { vidaActual -= daño; }
	void VerificarVida() {
		if (!vivo)
			throw new exception("GAMEOVER");
	}
	bool getVivo() { return vivo; }
	friend int& operator-(cPersona& P, int daño);
};

int& operator-(cPersona& P, int daño);


