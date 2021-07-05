#pragma once
#include "cMonstruo.h"
class cElite : public cMonstruo
{
private:
    int inteligencia;
    int fuerza;
    int porbaGolpe;
public:
    cElite();
    ~cElite() {};
    void Atacar(cPersona* P);
};

cElite::cElite() : cMonstruo()
{
    this->inteligencia = rand() % 101;
    this->fuerza = rand() % 101;
    this->porbaGolpe = rand() % 101;
}

inline void cElite::Atacar(cPersona* P)
{
    int Daño_a_hacer = ataque + +100 * (1 - exp(-(inteligencia + fuerza) / 100));
    RecibirDaño(P,Daño_a_hacer, this);
}
