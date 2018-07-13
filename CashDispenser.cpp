#include <fstream>
#include <vector>
#include <iomanip>
#include <conio.h>

#include "CashDispenser.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::setw;


void CashDispenser::initiate_value()
{
    for(int i = 0; i < 5; i++)
        with_depo.push_back(0);
}

///********************************///

void CashDispenser::setAmount()
{
    Amount = 0;
    for(int i = 0; i < 5; i++)
        if(getCash(i) > 0)
        {
            Amount += (getCash(i) * Bills_Number(i));
        }
        else
            Amount += 0;
}
 
void CashDispenser::setCashDeposit(int numar, int i)
{
    cash[i] += numar;
}

void CashDispenser::setCashWithdraw(int numar, int i)
{
    cash[i] -= numar;
}

void CashDispenser::setWith_Depo(int numar, int i)
{
    with_depo[i] += numar;
}

///********************************///

void CashDispenser::finAmount()         //citeste numarul de bancnote din bancomat
{
    ifstream fin("BankAmount.txt");
    string z;
    int x;
    for(int i = 0; i < 5; i++)
    {
        fin >> x;
        cash.push_back(x);
        getline(fin, z);
    }
    fin.close();
    setAmount();
}

void CashDispenser::foutAmount()    //afiseaza numarul de bancnote
{
    ofstream fout("BankAmount.txt");
    for(int i = 0; i < 5; i++)
        fout << cash[i] << endl;
    fout.close();
}

///********************************///

void CashDispenser::dispenseCashDisp(int amount, int& difference, int& sum)
{
    int i, suma = 0, h[4];
    bool ok;
    if(amount >= 10)
    {
        for(i = 0; i < 5; i++)
        {   
            h[i] = cash [i];
            do
            {
                if(h[i] > 0)
                {
                    with_depo[i] = 0;
                    do
                    {
                        if(amount - Bills_Number(i) >= 0)
                        {
                            suma += Bills_Number(i);
                            amount -= Bills_Number(i);
                            with_depo[i] += 1;
                            if(h[i] == 1)
                            {
                                h[i] = 0;
                            }
                            else
                                h[i]--;
                            ok = true;
                        }
                        else
                        {
                            ok = false;
                        }
                    }while(ok == true && h[i] > 0);
                }
                else
                {
                    ok = false;
                }
            }while(ok == true);
        }
    }
    sum = suma;
    difference = amount - sum;
}

int CashDispenser::Bills_Number(int i)
{
    switch(i)
    {
        case 0: {return 500;}break;
        case 1: {return 200;}break;
        case 2: {return 100;}break;
        case 3: {return 50;}break;
        case 4: {return 10;}
    }
    return 0;
}