#include "Bancomat.h"

Bancomat::Bancomat()
{
    SumaB = 0;
    AdaugaSumaB = 0;
    RetrageSumaB = 0;
}

void Bancomat::setSumaB(int x)
{
    SumaB = x;
}

int Bancomat::getSumaB() {return SumaB;}

void Bancomat::setAdaugaSumaB(int x)
{
    AdaugaSumaB = x;
}

int Bancomat::getAdaugaSumaB() {return AdaugaSumaB;}

void Bancomat::setRetrageSumaB(int x)
{
    RetrageSumaB = x;
}

int Bancomat::getRetrageSumaB() {return RetrageSumaB;}