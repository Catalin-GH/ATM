#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>

#include "Display.h"

using std::cout;
using std::endl;
using std::string;
using std::setw;


string Display::IntToString(int x)
{
    std::stringstream s;
    s << x;
    return s.str();
}

///********************************///

void Display::Login(string& id, int& pin, Keyboard& k)
{
    cout << endl << setw(40) << "BUN VENIT!" << endl;
    cout << endl << setw(50) << "* * * * * * * * * * * * * * *" << endl;
    cout << setw(36) << "ID: ";
    k.setID(id);
    cout << setw(36) << "PIN: ";
    k.setPIN(pin);
    cout << setw(50) << "* * * * * * * * * * * * * * *" << endl;
}

void Display::Login_Info()
{
    cout << "Reveniti mai tarziua!" << endl << "O zi buna!";
}

void Display::Login_ErrorID(string IDLogMsg)
{
    cout << "Numarul de cont " << IDLogMsg << " nu exista!";
}

void Display::Login_ErrorPIN()
{
    cout << "PIN-ul este incorect!";
}

void Display::Login_Attempts(int incercari)
{
    cout << " " << incercari << " incercari ramase.";
}

///********************************///

void Display::Menu(string name, int amount)
{
    string op1 ("Apasati 1 pentru a retrage."),
           op2 ("Apasati 2 pentru a depune."),
           op3 ("Apasati 3 pentru a schimba PIN-ul."),
           op4 ("Apasati 4 pentru a iesi.");
           
    
    struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    cout << endl << endl;
    cout << setw(10) << setw(69) << "*----------------------------------------------------------*" << endl
         << setw(10) << "|" << setw(59) << "|" << endl
         << setw(10) << "|" << setw(32) << "** ATM **" << setw(27) << "|" << endl
         << setw(10) << "|" << setw(59) << "|" << endl
         << setw(10) << "|" << setw(11) << "Data: ";
         (local->tm_mday < 10) ? cout << "0" << local->tm_mday : cout << local->tm_mday; cout << ".";
         (local->tm_mon + 1 < 10) ? cout << "0" << local->tm_mon + 1 : cout << local->tm_mon + 1; cout << ".";
         cout << local->tm_year + 1900 << " " << setw(37) << "|" << endl
         << setw(10) << "|" << setw(11) << "Ora: ";
         (local->tm_hour < 10) ?  cout << "0" << local->tm_hour : cout << local->tm_hour;cout << ":";
         (local->tm_min < 10) ? cout << "0" << local->tm_min : cout << local->tm_min;cout << setw(43) << "|" << endl
         << setw(10) << "|" << setw(59) << "|" << endl
         << setw(10) << "|" << setw(11) << "Nume: " << setw(name.length() + 1) << name << setw(60 - name.length() - 13) << "|" << endl
         << setw(10) << "|" << setw(11) << "Suma: " << setw(IntToString(amount).length() + 1) << amount << setw(4) << "lei" << setw(60 - IntToString(amount).length() - 17) << "|" << endl
         << setw(10) << "|" << setw(59) << "|" << endl
         << setw(10) << setw(69) << "*----------------------------------------------------------*" << endl;
    cout << setw(10) << "|" << setw(59) << "|" <<endl
         << setw(10) << "|" << setw(op1.length() + 1) << op1 << setw(60 - op1.length() - 2) << "|" << endl
         << setw(10) << "|" << setw(op2.length() + 1) << op2 << setw(60 - op2.length() - 2) << "|" << endl
         << setw(10) << "|" << setw(op3.length() + 1) << op3 << setw(60 - op3.length() - 2) << "|" << endl
         << setw(10) << "|" << setw(op4.length() + 1) << op4 << setw(60 - op4.length() - 2) << "|" << endl
         << setw(10) << "|" << setw(59) << "|" << endl
         << setw(10) << setw(69) << "*----------------------------------------------------------*" << endl;
    cout << endl;
}

void Display::Option(Keyboard& k)
{
    cout << "Optiunea: ";
    k.setOptiune();
}

void Display::Option_Wrong(Keyboard& k)
{
    if(k.getOptiune() < 1 || k.getOptiune() > 3)
    {
        k.setOptiune_1(0);
        Option_Error();
        getch();
        system("cls");
    }
}

void Display::Option_Error()
{
    cout << "Optiunea nu exista. Incercati din nou." << endl;
}

void Display::Option_1()
{
    cout << "Ce suma doriti sa retrageti?" << endl;
    cout << "Suma: ";
}

void Display::Option_2(int x)
{
    cout << "Suma de " << x << " lei a fost retrasa in:" << endl;
}

void Display::Option_3(int x, int y)
{
    cout << "Suma ceruta: " << x << endl;
    cout << "Poate fi retrasa doar suma de " << y << " lei." << endl;
    cout << "Doriti sa continuati?" << endl;
    cout << "   apasati 1 pentru un raspuns afirmativ." << endl;
    cout << "   apasati 0 pentru un raspuns negativ." << endl;
    cout << "Optiunea: ";
}

///********************************///

void Display::Bills_Display(int i)
{
    switch(i)
    {
        case 0:{cout << "Numarul de bancnote pe care doriti sa le introduceti: " << endl
                     << "500 lei: ";}break;
        case 1:{cout << "200 lei: ";}break;
        case 2:{cout << "100 lei: ";}break;
        case 3:{cout << "50 lei: ";}break;
        case 4:{cout << "10 lei: ";}break;
        default: {cout << "Eroare Display::Afisare_Bancnote";}
    }
}

void Display::Bills_Number(int j, int val)
{
    cout << j; 
    if(j < 2)
        cout << " bancnota";
    else
        cout << " bancnote";
    cout << " de " << val << " lei. " << endl;
}

///********************************///

void Display::Info_Value()
{
    cout << "Valoarea este incorecta!";
}

void Display::Transaction_Success(int amount)
{
    cout << "Suma de " << amount << " lei a fost adaugata in cont!";
}

void Display::Transaction_Fail()
{
    cout << "Tranzactia nu a avut loc!";
}

void Display::Withdraw_Info()
{
    cout << "Fondurile din bancomat sunt insuficiente pentru a efectua tranzactia!";
}

void Display::Withdraw_Info_1()
{
    cout << "In cont nu exista aceasta suma!";
}

///********************************///

void Display::ChangePIN(int& x, int& y, Keyboard& k)
{
    cout << endl << "Introduceti noul cod PIN: ";
    k.ChangePIN(x);
    cout << "Reintroduceti noul cod PIN: ";
    k.ChangePIN(y);
}

void Display::ChangePIN_Success()
{
    cout << endl << "Codul PIN a fost schimbat!";
}

void Display::ChangePIN_Error()
{
    cout << endl << "PIN-urile nu coincid!";
}

void Display::ChangePIN_Error_1()
{
    cout << endl << "Codul PIN nu a fost schimbat!";
}

void Display::ChangePIN_Error_2()
{
    cout << endl << "Codul PIN trebuie sa fie de 4 cifre!";
}

///********************************///

void Display::Exit_Msg()
{
    cout << endl << "VA MULTUMIM CA ATI ALES SERVICIILE ATM!" << endl;
}

///********************************///

void Display::Adm_Table(CashDispenser cd)
{
    cd.finAmount();
    cout << endl<< setw(34) << "SUMA DIN BANCOMAT" << endl << endl;
    cout << setw(50) << "*-------*-----------*-------------*--------------*" << endl;
    cout << setw(1) << "|" << setw(8) << "|" << setw(12) << "|" << setw(14) << "|" << setw(15) << "|" << endl;
    cout <<  setw(1) << "|" << setw(5) << "Nr." << setw(3) << "|" << setw(9) << "Valoare" << setw(3) << "|" << setw(10)
         << "Bancnote" << setw(4) << "|" << setw(10) << "Total" << setw(5) << "|" << endl;
    cout << setw(1) << "|" << setw(8) << "|" << setw(12) << "|" << setw(14) << "|" << setw(15) << "|" << endl;
    cout << setw(50) << "*-------*-----------*-------------*--------------*" << endl;
    for(int i = 0; i < 6; i++)
    {
        if(i < 5)
        {
            cout << setw(1) << "|" << setw(8) << "|" << setw(12) << "|" << setw(14) << "|" << setw(15) << "|" << endl;
            cout << setw(1) << "|" << setw(4) << i + 1 << setw(4) << "|" <<  setw(7) << cd.Bills_Number(i) << setw(5) << "|"
                 << setw(9) << cd.getCash(i) << setw(5) << "|" << setw(12) << cd.getCash(i) * cd.Bills_Number(i) << setw(3) << "|" << endl;
        }
        if(i == 5)
        {
            cout << setw(1) << "|" << setw(8) << "|" << setw(12) << "|" << setw(14) << "|" << setw(15) << "|" << endl;
            cout << setw(50) << "*-------*-----------*-------------*--------------*" << endl;
            cout << setw(9) << "|" << setw(41) << "|" << endl;
            cout << setw(9) << "|" << setw(27) << "Suma totala din bancomat:" << setw(11) << cd.getAmount() << setw(3) << "|"  << endl;
            cout << setw(9) << "|" << setw(41) << "|" << endl;
            cout << setw(50) <<"*----------------------------------------*" << endl << endl;
        }
    }
}

void Display::Adm_Option()
{
    cout << "Apasati 1 pentru a retrage bancnote." << endl 
         << "Apasati 2 pentru a depune bancnote." << endl 
         << "Apasati 3 pentru a salva datele." << endl 
         << "Apasati 4 pentru a rescrie fisierul FileLog." << endl
         << "Apasati 5 pentru a iesi. "<< endl << "Optiunea: ";
}

///********************************///

void Display::FileLog_Info()
{
    cout << endl << "      ATENTIE!" << endl << "RESCRIEREA FISIERULUI FILELOG DUCE LA PIERDEREA CONTINUTULUI!" << endl;
}

void Display::FileLog_Option()
{
    cout << endl << "Doriti sa continuati? (DA/NU)" << endl << "Optiunea: ";
}

void Display::FileLog_Success()
{
    cout << endl << "Fisierul FileLog a fost rescris!";
}

void Display:: FileLog_Fail()
{
    cout << endl << "Fisierul FileLog nu a fost rescris!";
}