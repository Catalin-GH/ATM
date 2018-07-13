#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include "Account.h"

class Transaction
{
public:
    virtual bool ExecuteTransaction(Account&, int) = 0;
};

#endif // TRANSACTION_H_INCLUDED
