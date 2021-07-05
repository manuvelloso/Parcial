#pragma once
#include "cMonstruo.h"
class cEsbirroMago :
    public cMonstruo
{
private:
    int inteligencia;
protected:
    friend class cPersona;
public:
    cEsbirroMago();
    ~cEsbirroMago() {};
    void Atacar(cPersona* P);
};

cEsbirroMago::cEsbirroMago() : cMonstruo()
{
    this->inteligencia = rand() % 101;
}

inline void cEsbirroMago::Atacar(cPersona* P)
{
    int Daño_a_hacer = ataque + 50 * (1 - exp(-inteligencia / 100));
    RecibirDaño(P,Daño_a_hacer, this);
}

