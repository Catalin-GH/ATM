#ifndef ACCONT_H_INCLUDED
#define ACCONT_H_INCLUDED

#include <string>
#include <vector>

class Account
{
public:
    void setID(std::string id) { ID.push_back(id);}
    void setPIN(int pin) { PIN.push_back(pin);}
    void setPIN_1(int pin, int i) { PIN[i] = pin;}
    void setAmountCustomer(int x) { AmountCustomer.push_back(x);}
    
    std::string getID(int i) {return ID[i];}
    int getPIN(int i) {return PIN[i];}
    int getAmountCustomer(int i) {return AmountCustomer[i];} 
    
    void DepositSum(int, int);
    void SubstractSum(int, int);
    bool CanWithdrawSum(int, int);
private:
    std::vector<std::string> ID;
    std::vector<int> PIN,
                     AmountCustomer;
};

#endif // ACCONT_H_INCLUDED