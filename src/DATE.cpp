#include "DATE.h"
#include<iostream>

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
        cout << "\t\tSAISIE DE LA DATE [jj  mm  aa] : " << endl ;
        cin >> jj;
        cin >> mm;
        cin >> jj;
        if(jj < 1 || jj > 31 || mm < 1 || mm > 12 || aa < 2020 || aa > 2100)
        {
            cout << "\n\t\tDATE INVALIDE !!! " << endl ;
        }
    }while(jj < 1 || jj > 31 || mm < 1 || mm > 12 || aa < 2020 || aa > 2100);
}

void DATE::affiche()
{
    cout << "\t\t" << jj << " \ " << mm << " \ " << aa << endl;
}
