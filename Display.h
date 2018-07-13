#ifndef INTERFATA_H_INCLUDED
#define INTERFATA_H_INCLUDED

#include "Keyboard.h"
#include "CashDispenser.h"

class Display
{
public:
    std::string IntToString(int);
    
    void Login(std::string&, int&, Keyboard&);
    void Login_Info();
    void Login_ErrorID(std::string);
    void Login_ErrorPIN();
    void Login_Attempts(int);
    
    void Menu(std::string, int);
    void Option(Keyboard&);
    void Option_Wrong(Keyboard&);
    void Option_Error();
    void Option_1();
    void Option_2(int);
    void Option_3(int, int);
    
    void Bills_Display(int);
    void Bills_Number(int, int);
    
    void showTable();
    
    void Info_Value();
    void Transaction_Success(int);
    void Transaction_Fail();
    void Withdraw_Info();
    void Withdraw_Info_1();
    
    void ChangePIN(int&, int&, Keyboard&);
    void ChangePIN_Error();
    void ChangePIN_Error_1();
    void ChangePIN_Error_2();
    void ChangePIN_Success();
  
    void Exit_Msg();
    
    void FileLog_Info();
    void FileLog_Option();
    void FileLog_Fail();
    void FileLog_Success();
    
    void Adm_Table(CashDispenser);
    void Adm_Option();
private:
    std::string name;
};

#endif
