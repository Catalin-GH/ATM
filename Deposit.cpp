#include "Deposit.h"

bool Deposit::ExecuteTransaction(Account a, int i)
{
    a.DepositSum(sum, i);
    return true;
}