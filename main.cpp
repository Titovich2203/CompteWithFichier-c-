#include <iostream>
#include"views.h"

using namespace views;
using namespace std;

int main()
{
    int choix, choix1;

    system("color 8f");

    do
    {
        choix = menuPrincipal();
        switch(choix)
        {
            case 1:
                do
                {
                    choix1 = menuCompte();
                    switch(choix1)
                    {
                        case 1:

                            break;
                        case 2:

                            break;
                        case 3:

                            break;
                        case 5:
                            exit(EXIT_FAILURE);
                            break;
                    }
                }while(choix1 != 4);
                break;
            case 2:
                do
                {
                    choix1 = menuTransaction();
                    switch(choix1)
                    {
                        case 1:

                            break;
                        case 2:

                            break;
                        case 3:

                            break;
                        case 5:
                            exit(EXIT_FAILURE);
                            break;
                    }
                }while(choix1 != 4);
                break;
        }
    }while(choix != 3);

    return 0;
}
