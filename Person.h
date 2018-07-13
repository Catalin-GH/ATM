#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>
#include <vector>

class Person
{
public:
    void setFirstName(std::string n ) { FirstName.push_back(n);}
    void setSecondName(std::string n) { SecondName.push_back(n);}
    
    std::string getFirstName(int i) { return FirstName[i];}
    std::string getSecondName(int i) { return SecondName[i];} 
    std::string getName(int i);
private:
    std::vector<std::string> FirstName, 
                             SecondName;
};

#endif // PERSON_H_INCLUDED