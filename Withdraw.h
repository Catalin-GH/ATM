#ifndef WITHDRAW_H_INCLUDED
#define WITHDRAW_H_INCLUDED

#include "Transaction.h"

class Withdraw : public Transaction
{
public:
    bool ExecuteTransaction(Account& a, int i)
    {
        if(verify == true)
            a.SubstractSum(sum, i);
        return true;
    }
    void setVerify(bool x) { verify = x;}
    void setSum(int amount) { sum = amount;}
private:
    int verify;
    int sum;
};

#endif // WITHDRAW_H_INCLUDED
