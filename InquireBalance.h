#ifndef INQUIREBALANCE_H_INCLUDED
#define INQUIREBALANCE_H_INCLUDED

#include "Transaction.h"

class InquireBalance : public Transaction
{
public:
    bool ExecuteTransaction(Account& a, int i)
    {
        sum = a.getAmountCustomer(i);
        if(sum > 0 )
            return true;
        return false;
    }
    int getSum() { return sum;}
private:
    int sum;
};

#endif // INQUIREBALANCE_H_INCLUDED
