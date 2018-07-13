#ifndef DEPOSIT_H_INCLUDED
#define DEPOSIT_H_INCLUDED

#include "Transaction.h"

class Deposit : public Transaction
{
public:
    bool ExecuteTransaction(Account& a, int i)
    { 
        a.DepositSum(sum, i);
        return true;
    }
    void setSum(int amount) {sum = amount;}
private:
    int sum;
};

#endif // DEPOSIT_H_INCLUDED
