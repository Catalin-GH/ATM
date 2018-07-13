#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include "Person.h"
#include "Display.h"
#include "InquireBalance.h"
#include "ValidateAmount.h"
#include "Withdraw.h"
#include "Deposit.h"
#include "Logger.h"

class Bank
{
friend int NOL();
public:
    std::string getName(int i) {return p.getName(i); }
    int getAmountCustomer(int i) {return TransactionIB(i);}
    
    void ChangePIN(int pin, int i) {a.setPIN_1(pin, i);}
    
    bool ExecuteTransaction(int, int, int);
    bool TransactionVA(int, int);
    void TransactionWd(int, int);
    void TransactionDp(int, int);
    int TransactionIB(int);
    
    int Login(Display&, Keyboard&);
    
    void BankInfoRead();
    void BankInfoWrite();
    
    void Admin_Panel();
private:
    Transaction* t;
    Deposit dp;
    Withdraw wd;
    InquireBalance ib;
    ValidateAmount va;
    Display d;
    CashDispenser cd;
    Keyboard k;
    Person p;
    Account a;
    Logger l;
};

#endif