#include "cMonstruo.h"

//void cMonstruo::RecibirDa�oMonstruo(int da�o)
//{
//	vida -= da�o;
//}
void RecibirDa�oMonstruo(cMonstruo* M, int da�o)
{
	M->vida -= da�o;
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
