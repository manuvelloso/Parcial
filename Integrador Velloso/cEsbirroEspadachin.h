#pragma once
#include "cMonstruo.h"

class cEsbirroEspadachin :
    public cMonstruo
{
private:
    int fuerza;
public:
    cEsbirroEspadachin();
    ~cEsbirroEspadachin() {};
    void Atacar(cPersona* P);
};

cEsbirroEspadachin::cEsbirroEspadachin() : cMonstruo()
{
    this->fuerza = rand() % 101;
}

inline void cEsbirroEspadachin::Atacar(cPersona* P)
{
    int Daño_a_hacer = ataque + fuerza / 10;
    RecibirDaño(P,Daño_a_hacer, this);
}

