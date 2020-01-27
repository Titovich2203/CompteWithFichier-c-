#include "DATE.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace std;
using namespace modeles;

DATE::DATE()
{
    //ctor
}

DATE::~DATE()
{
    //dtor
}

void DATE::saisie()
{
    do
    {
        cout << "\t\tSAISIE DE LA DATE [jj] : " ; cin >> jj;
        cout << "\t\tSAISIE DE LA DATE [mm] : " ; cin >> mm;
        cout << "\t\tSAISIE DE LA DATE [aa] : " ; cin >> aa;
        if(jj < 1 || jj > 31 || mm < 1 || mm > 12 || aa < 2000 || aa > 2100)
        {
            cout << "\n\t\tDATE INVALIDE !!! " << endl ;
        }
    }while(jj < 1 || jj > 31 || mm < 1 || mm > 12 || aa < 2000 || aa > 2100);
}

string DATE::affiche()
{
    stringstream a;
    a << jj << " \ " << mm << " \ " << aa << endl;
    return a.str();
}
