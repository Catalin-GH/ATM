#ifndef VALIDATEAMOUNT_H_INCLUDED
#define VALIDATEAMOUNT_H_INCLUDED

class ValidateAmount : public Transaction
{
public:
    bool ExecuteTransaction(Account& a, int i)
    {
        bool verify = a.CanWithdrawSum(sum, i);
        return verify;
    }
    void setSum(int amount) { sum = amount;}
private: 
    int sum;
};

#endif // VALIDATEAMOUNT_H_INCLUDED
