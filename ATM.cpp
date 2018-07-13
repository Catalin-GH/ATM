#include "ATM.h"

#include <stdlib.h>
#include <conio.h>

void ATM::StartATM()
{
    int i = 0;
    bool circle = true;
    cd.initiate_value();
    while(circle == true)
    {
        k.setOptiune_1(0);
        b.BankInfoRead();           //citeste datele bancii (nume, pin, id, suma) din fisier
        i = b.Login(d, k);
        if(i == -2)
            b.Admin_Panel();
        else
        {
            if(i > -1)
            {
                while(k.getOptiune() != 4)
                {
                    system("cls");
                    cd.finAmount();             //citeste numarul de bancnote din bancomat
                    d.Menu(b.getName(i), b.getAmountCustomer(i));
                    d.Option(k);
                    switch(k.getOptiune())
                    {
                        case 1: {
                                    WithdrawOp(i);
                                }break;
                        case 2: {
                                DepositOp(i);
                                }break;
                        case 3: {
                                ChangePINOp(i);
                                }break;
                        case 4: {
                                k.setOptiune_1(4);
                                d.Exit_Msg();
                                getch();
                                system("cls");
                                }break;
                        default: {
                                    d.Option_Wrong(k);
                                 }
                    }
                    b.BankInfoWrite();
                }
            }
            else
            {
                circle = false;
                system("cls");
                d.Login_Info();
            }
        }
    }
}

///********************************///

void ATM::WithdrawOp(int i)
{  
    int x, y = 0, difference, amount = 0;
    cd.setAmount();
    k.setWithdraw_1();
    do                                                              // citirea corecta a sumei de retragere
    {
        system("cls");
        d.Menu(b.getName(i), b.getAmountCustomer(i));
        d.Option_1();
        k.setWithdraw();
        x = k.getWithdraw();
        if(x)
        {
            y = x % 10;
        }
        if(k.getWithdraw() < 10 || y != 0)
        {
            d.Info_Value();
            getch();
        }
    }while(k.getWithdraw() < 10 || y != 0);
    
    system("cls");
    cd.dispenseCashDisp(k.getWithdraw(), difference, amount);
    if(Verify() == true && amount != 0)
    {
        if(b.ExecuteTransaction(1, amount, i) == true && amount == k.getWithdraw())    //poate fi retrasa intreaga suma CERUTA din cont si bancomat
        {
            system("cls");
            d.Menu(b.getName(i), b.getAmountCustomer(i) - amount);
            d.Option_2(amount);
            for(int j = 0; j < 5; j++)
            {
                if(cd.getWith_Depo(j))
                    d.Bills_Number(cd.getWith_Depo(j), cd.Bills_Number(j));
            }
            b.TransactionWd(amount, i);
            for(int k = 0; k < 5; k++)
                cd.setCashWithdraw(cd.getWith_Depo(k), k);
            cd.foutAmount();
            Logger_fout(amount, 1, i);
            getch();
        }
        else
        {
            if(b.ExecuteTransaction(1, amount, i) ==  true)
            {
                do
                {
                    system("cls");
                    d.Menu(b.getName(i), b.getAmountCustomer(i));
                    d.Option_3(k.getWithdraw(), amount);
                    k.setY_N();
                }while(k.getY_N() < 0 || k.getY_N() > 1);
            
                if(k.getY_N() == 1)
                {
                    system("cls");
                    d.Menu(b.getName(i), b.getAmountCustomer(i) - amount);
                    d.Option_2(amount);
                    for(int j = 0; j < 5; j++)
                    {
                        if(cd.getWith_Depo(j))
                        d.Bills_Number(cd.getWith_Depo(j), cd.Bills_Number(j));
                    }
                    for(int k = 0; k < 5; k++)
                        cd.setCashWithdraw(cd.getWith_Depo(k), k);
                    b.TransactionWd(amount, i);
                    cd.foutAmount();
                    Logger_fout(amount, 1, i);
                    getch();
                }
            
                if(k.getY_N() == 0)
                {
                    system("cls");
                    d.Menu(b.getName(i), b.getAmountCustomer(i));
                    d.Transaction_Fail();
                    getch();
                }
            
            }
            else
            {
                system("cls");
                d.Menu(b.getName(i), b.getAmountCustomer(i));
                d.Withdraw_Info_1();
                getch();
            }
        }
    }
    else
    {
        system("cls");
        d.Menu(b.getName(i), b.getAmountCustomer(i));
        d.Withdraw_Info();
        getch();
    }
    system("cls");
}

void ATM::DepositOp(int i)
{
    int suma = 0;
    for(int j = 0; j < 5; j++)          //citeste de la tastatura numarul de bancnote pe care le depune clientul
    {
        d.Bills_Display(j);
        k.setNumarBancnote();
        cd.setWith_Depo(k.getNumarBancnote(), j);
        suma += (k.getNumarBancnote() * cd.Bills_Number(j));
        cd.setCashDeposit(k.getNumarBancnote(), j);
    }
    Logger_fout(suma, 2, i);
    system("cls");
    d.Menu(b.getName(i), b.getAmountCustomer(i) + suma);
    if(b.ExecuteTransaction(2, suma, i) == true)
    {
        b.TransactionDp(suma, i);
        d.Transaction_Success(suma);
    }
    else
        d.Transaction_Fail();
    cd.foutAmount();
    getch();
    system("cls");
}

void ATM::ChangePINOp(int i)
{   
    int x, y, n = 3;
    bool ok;
    do
    {
        system("cls");
        if(n != 3)
            d.Login_Attempts(n);
        d.ChangePIN(x, y, k);
        if(x > 999 && x < 10000)
        {
            if(y > 999 && y < 10000)
            {
                if(x == y)
                {
                    ok = true;
                }
            }
            else
            {
                n --;
                ok = false;
            }
        }
        else
        {
             n --;
             ok = false;
        }
        if(x != y)
        {
            d.ChangePIN_Error();
            getch();
        }
        else
        {
            if(ok == false )
            {
                d.ChangePIN_Error_2();
                getch();
            }
        }
    }while(ok == false && n >= 1);
    if(ok == true)
    {
        b.ChangePIN(y, i);
        d.ChangePIN_Success();
    }
    else
        d.ChangePIN_Error_1();
    getch();
    system("cls");
}

///********************************///

void ATM::Logger_fout(int amount, int option, int i)
{
    if(amount > 0)
    {
        cd.setAmount();
        l.output_outofcash(cd);
        l.output_data(cd, b.getName(i), option, amount);
    }
}

///********************************///

bool ATM::Verify()
{
    for(int i = 0; i < 5; i++)
    {
        if((cd.getWith_Depo(i) != 0) && (cd.getWith_Depo(i) > cd.getCash(i)))
            return false;
    }
    return true;
}