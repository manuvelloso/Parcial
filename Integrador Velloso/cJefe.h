#pragma once
#include "cMonstruo.h"
class cJefe :
    public cMonstruo
{
private:
    int inteligencia;
    int probaCritico;
    int fuerza;
public:
    cJefe();
    ~cJefe() {};
    void Atacar(cPersona* P);
};

cJefe::cJefe() : cMonstruo()
{
    this->inteligencia = rand() % 101;
    this->fuerza = rand() % 101;
    this->probaCritico = rand() % 26; //de 0 a 25
}

inline void cJefe::Atacar(cPersona* P)
{
    int Da�o_a_hacer = ataque + fuerza / 5 + inteligencia / 5;

    RecibirDa�o(P,Da�o_a_hacer, this);

    probaCritico++;
}