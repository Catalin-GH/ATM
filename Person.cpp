#include "Person.h"

using std::string;

string Person::getName(int i)
{
    string name = FirstName[i] + " " + SecondName[i];
    return name;
}