#include <fstream>
#include <time.h>
#include <iomanip>
#include <sstream>

#include "Logger.h"

using std::ofstream;
using std::ios;
using std::endl;
using std::string;
using std::setw;

void Logger::output_front_table()
{
    ofstream fout("FileLog.txt");
    for(int i = 0; i < 260; i++) fout << "*"; fout << endl;
    fout << setw(1) << "*" << setw(25) << "*" << setw(15) << "*" << setw(72) << "*" << setw(17) << "*" << setw(87) 
         << "*" << setw(19) << "*" << setw(13) << "*" << setw(11) << "*" << endl;
    fout << setw(1) << "*" << setw(14) << "NUME" << setw(11) << "*"
                           << setw(13) << "DEPUS/RETRAS" << setw(2)<< "*"
                           << setw(46) << "BANCNOTELE CLIENTULUI" <<setw(26) << "*"
                           << setw(13) << "SUMA D/R" << setw(4) << "*"
                           << setw(54) << "BANCNOTELE DIN BANCOMAT" << setw(33) << "*"
                           << setw(12) << "SUMA B" << setw(7) << "*" 
                           << setw(8) << "DATA" << setw(5) << "*"
                           << setw(7) << "ORA" << setw(4) << "*" << endl;
    fout << setw(1) << "*" << setw(25) << "*" << setw(15) << "*" << setw(72) << "*" << setw(17) << "*" << setw(87) 
         << "*" << setw(19) << "*" << setw(13) << "*" << setw(11) << "*" << endl;
    for(int i = 0; i < 260; i++) fout << "*"; fout << endl;
    fout.close();
}

void Logger::output_outofcash(CashDispenser cd)
{
    ofstream fout("FileLog.txt", ios::app);
    if(cd.getAmount() == 0)
    {
        fout << setw(1) << "*" << setw(259) << "*";
        fout << endl << setw(1) << "*" << setw(34) << "Suma din bancomat este de" 
             << setw(2) << cd.getAmount() << setw(5) << "lei!" << setw(218) << "*";
        fout << endl << setw(1) << "*" << setw(259) << "*" << endl;
            for(int i = 0; i < 260; i++) fout << "*"; fout << endl;
    }
   for(int i = 0; i < 5; i++)  
        if(cd.getCash(i) == 0)
        {
            fout << setw(1) << "*" << setw(259) << "*";
            fout << endl << setw(1) << "*" << setw(30) << "Nu exista bancnote de" 
                 << setw(4) << cd.Bills_Number(i) << setw(17) << "lei in bancomat!" << setw(208) << "*";
            fout << endl << setw(1) << "*" << setw(259) << "*" << endl;
            for(int i = 0; i < 260; i++) fout << "*"; fout << endl;
        }
    fout.close();
}

void Logger::output_data(CashDispenser cd, string name, int option, int amount)
{
    struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    ofstream fout("FileLog.txt", ios::app);
    string s;
    fout << setw(1) << "*" << setw(25) << "*" << setw(15) << "*" << setw(72) << "*" << setw(17) << "*" << setw(87) 
         << "*" << setw(19) << "*" << setw(13) << "*" << setw(11) << "*" << endl;
         
    ///******   afisare nume   ******///
    fout << setw(1) << "*" << setw(21) << name << setw(4) << "*";
    
    //afisare depus/retras
    if(option == 1) fout << setw(10) << "RETRAS" << setw(5) << "*";
    if(option == 2) fout << setw(10) << "DEPUS" << setw(5) << "*";
    
    ///******   afisare bancnotele clientului   ******///
    for(int i = 0; i < 5; i++) 
    {
        s = IntToString(cd.getWith_Depo(i)) + "*" + IntToString(cd.Bills_Number(i)) + "lei";
        fout << setw(14) << s;
    }
    fout << setw(2) << "*";
    
    ///******   afisare suma client   ******/////
    s = IntToString(amount) + " lei";
    fout << setw(13) << s << setw(4) << "*";
    
    ///******   afisare bancnotele din bancomat   ******/////
    for(int i = 0; i < 5; i++) 
    {
        s = IntToString(cd.getCash(i)) + "*" + IntToString(cd.Bills_Number(i)) + "lei";
        fout << setw(17) << s;
    }
    fout << setw(2) << "*";
    
    ///******   afisare suma bancomat   ******/////
    s = IntToString(cd.getAmount()) + " lei";
    fout << setw(16) << s << setw(3) << "*";
    
    ///******   afisare data   ******/////
    (local->tm_mday < 10) ? fout << setw(2) << "0" << setw(1) << local->tm_mday : fout << setw(3) << local->tm_mday; fout << setw(1) << ".";
    (local->tm_mon + 1 < 10) ? fout << setw(1) << "0" << setw(1) << local->tm_mon + 1 : fout << setw(2) << local->tm_mon + 1; fout << setw(1) << ".";
    fout << setw(4) << local->tm_year + 1900 << setw(2) << "*";
    
    ///******   afisare ora   ******/////
    (local->tm_hour < 10) ?  fout << setw(2) << "0" << setw(1) << local->tm_hour : fout << setw(3) << local->tm_hour; fout << setw(1) << ":";
    (local->tm_min < 10) ? fout << setw(1) << "0" << setw(1) << local->tm_min : fout << setw(2) << local->tm_min; fout << setw(1) << ":";
    (local->tm_sec < 10) ? fout << setw(1) << "0" << setw(1) << local->tm_sec : fout << setw(2) << local->tm_sec;
    fout << setw(2) << "*";
    
    fout << endl << setw(1) << "*" << setw(25) << "*" << setw(15) << "*" << setw(72) << "*" << setw(17) << "*" << setw(87) 
         << "*" << setw(19) << "*" << setw(13) << "*" << setw(11) << "*" << endl;
    for(int i = 0; i < 260; i++) fout << "*"; fout << endl;
}

string Logger::IntToString(int x)
{
    std::stringstream s;
    s << x;
    return s.str();
}