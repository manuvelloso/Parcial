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
	friend void RecibirDa�o(cPersona* P, int Da�oBase, cMonstruo* M);
	//friend void cMonstruo::RecibirDa�oMonstruo(int da�o);
public:
	cPersona(string nombre);
	void Atacar(cMonstruo* M);
	bool operator==(bool alive) { return vivo == alive; }
	friend ostream& operator<<(ostream& out, cPersona* P);
	void setVida(int da�o) { vidaActual -= da�o; }
	void VerificarVida() {
		if (!vivo)
			throw new exception("GAMEOVER");
	}
	bool getVivo() { return vivo; }
	friend int& operator-(cPersona& P, int da�o);
};

int& operator-(cPersona& P, int da�o);


