#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include "CashDispenser.h"

class Logger
{
public:
    void output_front_table();
    void output_outofcash(CashDispenser);                     //afiseaza daca lipseste un anumit tip de bancnota + lipsa fonduri
    void output_data(CashDispenser, std::string, int, int);
    std::string IntToString(int);
};

#endif // LOGGER_H_INCLUDED
