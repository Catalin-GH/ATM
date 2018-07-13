#ifndef BANCOMAT_H_INCLUDED
#define BANCOMAT_H_INCLUDED

class Bancomat
{
public:
    Bancomat();
    void setSumaB(int);
    int getSumaB();
    void setAdaugaSumaB(int);
    int getAdaugaSumaB();
    void setRetrageSumaB(int);
    int getRetrageSumaB();
    
private:
    int SumaB;
    int AdaugaSumaB;
    int RetrageSumaB;
};

#endif // BANCOMAT_H_INCLUDED