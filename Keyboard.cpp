#include <iostream>

#include "Keyboard.h"

using std::string;
using std::cin;

Keyboard::Keyboard()
{
    Withdraw = 0;
    PIN = 0;
}

///********************************///

int Keyboard::getOptiune()
{
    return optiune;
}

///********************************///

void Keyboard::setID(string& id)
{
    cin >> id;
    ID = id;
}

void Keyboard::setPIN(int& pin)
{
    cin >> pin;
    PIN = pin;
}

void Keyboard::setWithdraw()
{
    int x;
    cin >> x;
    Withdraw = x;
}

void Keyboard::setOptiune()
{
    cin >> optiune;
}

void Keyboard::setOptiune_1(int x)
{
    optiune = x;
}

void Keyboard::setNumarBancnote()
{
    cin >> numar_bancnote;
}

void Keyboard::setY_N()
{
    cin >> value;
}

///********************************///

void Keyboard::ChangePIN(int& x)
{
    cin >> x;
}

///********************************///

void Keyboard::Adm_Option(char& x, char& y)
{
    char c[2];
    cin >> c;
    x = c[0];
    y= c[1];
}