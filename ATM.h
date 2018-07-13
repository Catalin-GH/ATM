#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

#include "Bank.h"
#include "CashDispenser.h"
#include "Deposit.h"
#include "Logger.h"

class ATM
{
public:
    void StartATM();
    
    void WithdrawOp(int);
    void DepositOp(int);
    void ChangePINOp(int);
    
    void Logger_fout(int, int, int);
    
    bool Verify();
private:
    Bank b;
    CashDispenser cd;
    Display d;
    Keyboard k;
    Logger l;
};

#endif // ATM_H_INCLUDED
