#include <iostream>
#include"views.h"
#include<SERVICES.h>
#include<vector>

using namespace services;
using namespace modeles;
using namespace views;
using namespace std;

int main()
{
    int choix, choix1;
    SERVICES *SR = new SERVICES();
    vector<COMPTE*> comptes = SR->loadComptes();


    system("color 3f");

    do
    {
        choix = menuPrincipal();
        switch(choix)
        {
            case 1:
                do
                {
                    choix1 = menuCompte();
                    system("cls");
                    switch(choix1)
                    {
                        case 1:
                            SR->newCompte(&comptes);
                            break;
                        case 2:
                            SR->listCompteEpargne(comptes);
                            break;
                        case 3:
                            SR->listCompteCheque(comptes);
                            break;
                        case 5:
                            exit(EXIT_FAILURE);
                            break;
                    }
                    if(choix1 != 4 && choix1 != 5)
                        system("pause");
                }while(choix1 != 4);
                break;
            case 2:
                do
                {
                    choix1 = menuTransaction();
                    system("cls");
                    switch(choix1)
                    {
                        case 1:
                            SR->newTransaction(&comptes);
                            break;
                        case 2:
                            SR->allTransaction(comptes);
                            break;
                        case 3:
                            SR->transByCompte(comptes);
                            break;
                        case 5:
                            exit(EXIT_FAILURE);
                            break;
                    }
                    if(choix1 != 4 && choix1 != 5)
                        system("pause");
                }while(choix1 != 4);
                break;
        }
    }while(choix != 3);

    return 0;
}
