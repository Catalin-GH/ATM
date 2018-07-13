#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>

#include "Bank.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::endl;

int NOL()
{
    int number_of_lines = 0;
    string line;
    ifstream fin("BankInfo.txt");           // aflarea nr. de linii BankInfo
    while(getline(fin, line))
        number_of_lines++;
    fin.close();
    return number_of_lines;
}

///********************************///

bool Bank::ExecuteTransaction(int option, int amount, int i)
{
    if(amount > 0 && option == 1)     //retragere - withdraw
        if(TransactionVA(amount, i) == true)
            return true;
    if(amount > 0 && option == 2)     //depunere - deposit
        return true;
    return false;
}

void Bank::TransactionWd(int amount, int i)             
{
    wd.setSum(amount);
    wd.setVerify(TransactionVA(amount, i));
    t = &wd;
    t->ExecuteTransaction(a, i);
}

void Bank::TransactionDp(int amount, int i)
{
    dp.setSum(amount);
    t = &dp;
    t->ExecuteTransaction(a, i);
}

int Bank::TransactionIB(int i)                  //returneaza suma clientului din cont
{
    t = &ib;
    if(t->ExecuteTransaction(a, i) == true)
        return ib.getSum();
    return 0;
}

bool Bank::TransactionVA(int amount, int i)                 //verifica daca suma ceruta poate fi retrasa din cont
{
    if(TransactionIB(i) >= amount)
        {
            va.setSum(amount);
            t = &va;
            if(t->ExecuteTransaction(a, i) == true)
                return true;
        }
    return false;
}

///********************************///

int Bank::Login(Display& d, Keyboard& k)
{
    int PINLogMsg, i, incercari = 3, number_of_lines = NOL();
    string IDLogMsg;
    bool accept, ok, ok_1, ok_2;
    
    while(accept == false && incercari > 0)
    {
        if(incercari > 0 && incercari < 3)
            d.Login_Attempts(incercari);
        accept = false;
        ok = false;
        ok_1 = false;
        ok_2 = false;
        d.Login(IDLogMsg, PINLogMsg, k);
        if(IDLogMsg == "admin" && PINLogMsg == 1111)
            return -2;
        else                        // verifica daca ID si PIN coincid cu datele bancii
        {
            for(i = 0; i < number_of_lines; i++)
                if((IDLogMsg == a.getID(i)) && (PINLogMsg == a.getPIN(i)))              // Logare cu succes
                {
                    return i;                 
                    accept = true;
                }
            if(accept == false)                                  
                for(i = 0; i < number_of_lines; i++)
                {
                    if(IDLogMsg == a.getID(i) && PINLogMsg != a.getPIN(i))
                        ok = true;
                    if(IDLogMsg != a.getID(i))
                        ok_1 = true;
                }
            if(ok == true)
            {
                d.Login_ErrorPIN();
                ok_2 = true;
                getch();
            }
            if(ok_1 == true && ok_2 == false)
            {
                d.Login_ErrorID(IDLogMsg);
                getch();
            }
        }
        incercari--;
        system("cls");
    }
    return -1;
}

///********************************///

void Bank::BankInfoRead()       //citire date fisier BankInfo.txt
{
    string line, id, fn, sn;
    ifstream fin("BankInfo.txt");
    int i = 0, pin, ac;

    while(getline(fin, line))
    {
        stringstream BankInfo(line);
        BankInfo >> id;
        a.setID(id);
        BankInfo >> pin;
        a.setPIN(pin);
        BankInfo >> fn;
        p.setFirstName(fn);
        BankInfo >> sn;
        p.setSecondName(sn);
        BankInfo >> ac;
        a.setAmountCustomer(ac);
        i++;
    }
    fin.close();
}

void Bank::BankInfoWrite()       //rescrierea fisierului BankInfo dupa fiecare operatie
{
    int number_of_lines = NOL();
 
    ofstream fout("BankInfo.txt");
    for(int j = 0; j < number_of_lines; j++)
        fout << a.getID(j) << " " << a.getPIN(j) << " " << p.getFirstName(j) << " " 
             << p.getSecondName(j) << " " << a.getAmountCustomer(j) << endl;
    fout.close();
}

///********************************///

void Bank::Admin_Panel()
{
    system("cls");
    do
    {
        cd.finAmount();
        do                                                              // citirea corecta a sumei de retragere
        {
            system("cls");
            d.Adm_Table(cd);
            d.Adm_Option();
            k.setOptiune();
            if(k.getOptiune() < 1 || k.getOptiune() > 5)
                d.Option_Error();
        }while(k.getOptiune() < 1 || k.getOptiune() > 5);
        switch(k.getOptiune())
        {
            case 1: {
                        system("cls");
                        d.Adm_Table(cd);
                        for(int i = 0; i < 5; i++)
                        {
                            d.Bills_Display(i);
                            k.setNumarBancnote();
                            cd.setCashWithdraw(k.getNumarBancnote(), i);
                        }
                    }break;
            case 2: {
                        system("cls");
                        d.Adm_Table(cd);
                        for(int i = 0; i < 5; i++)
                        {
                            d.Bills_Display(i);
                            k.setNumarBancnote();
                            cd.setCashDeposit(k.getNumarBancnote(), i);
                        }
                    }break;
            case 3: {cd.foutAmount();}break;
            case 4: {
                        char x, y;
                        bool ok;
                        do
                        {
                            ok = false;
                            system("cls");
                            d.Adm_Table(cd);
                            d.FileLog_Info();
                            d.FileLog_Option();
                            k.Adm_Option(x, y);
                            if( x == 'D' && y == 'A')
                                ok = true;
                            if(x == 'N' && y == 'U')
                                ok = true;
                        }while(ok == false);
                        if(x == 'D' && y == 'A')
                        {
                            d.FileLog_Success();
                            l.output_front_table();
                            getch();
                        }
                        if(x == 'N' && y == 'U')
                        {
                            d.FileLog_Fail();
                            getch();
                        }
                    }break;
            case 5: {}break;
        }
    }while(k.getOptiune() != 5);
    system("cls");
}