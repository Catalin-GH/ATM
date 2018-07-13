#ifndef CASHDISPENSER_H_INCLUDED
#define CASHDISPENSER_H_INCLUDED

#include <vector>

class CashDispenser
{
public:
    void initiate_value();
    
    void setWith_Depo(int, int);
    void setCashDeposit(int, int);
    void setCashWithdraw(int, int);
    void setAmount();
    
    int getWith_Depo(int i) { return with_depo[i];}
    int getCash(int i) { return cash[i];}
    int getAmount() {return Amount;}
    
    void finAmount();                                //citeste din fisierul BankAmount bancnotele ce se gesasc in bancomat
    void foutAmount();                               //afiseaza in fisierul BankAmount bancnotele din bancomat
    
    void dispenseCashDisp(int, int&, int&);          //retrage o suma in bancomat sub forma de bancnote 
    int Bills_Number(int);
    
private:
    int Amount;                                      //suma din bancomat
    std::vector<int> cash;                           //numarul de bancnote din bancomat
    std::vector<int> with_depo;                      //numarul de bancnote retrase/adaugate
};

#endif // CASHDISPENSER_H_INCLUDED
