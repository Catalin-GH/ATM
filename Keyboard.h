#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

#include <string>

class Keyboard
{
public:
    std::string getID() { return ID;}
    int getPIN() { return PIN;}
    int getWithdraw() { return Withdraw;}
    int getNumarBancnote() {return numar_bancnote;}
    int getY_N() { return value;}
    int getOptiune();
    
    Keyboard();
    void setWithdraw_1() {Withdraw = 0;}
    void setID(std::string&);
    void setPIN(int&);
    void setWithdraw();
    void setOptiune();
    void setOptiune_1(int);
    void setNumarBancnote();
    void setY_N();
    
    void ChangePIN(int&);
    
    void Adm_Option(char&, char&);
private:
    int Withdraw, value;
    std::string ID;
    int PIN, optiune, numar_bancnote;
};

#endif
