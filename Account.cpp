#include "Account.h"

void Account::DepositSum(int sum, int i)
{
    AmountCustomer[i] += sum; 
}

void Account::SubstractSum(int sum, int i)
{
    AmountCustomer[i] -= sum;
}

bool Account::CanWithdrawSum(int sum, int i)
{
    if(AmountCustomer[i] - sum >= 0 )
        return true;
    return false;
}