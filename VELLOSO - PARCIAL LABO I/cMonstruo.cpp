#include "cMonstruo.h"

//void cMonstruo::RecibirDañoMonstruo(int daño)
//{
//	vida -= daño;
//}
void RecibirDañoMonstruo(cMonstruo* M, int daño)
{
	M->vida -= daño;
}
int cMonstruo::contador = 0;
cMonstruo::cMonstruo() : nombre(contador+1)
{
	this->vida = rand() % 101;
	this->ataque = rand() % 101;
	this->vivo = true;
	contador++;
}

cMonstruo::~cMonstruo()
{
	contador--;  //se murio el monstruo
}
