#ifndef SERVICES_H
#define SERVICES_H
#include<COMPTE.h>
#include<TRANSACTION.h>
#include<vector>

using namespace modeles;


namespace services
{
    class SERVICES
    {
        public:
            SERVICES();
            virtual ~SERVICES();

            void newCompte(vector<COMPTE*>*);
            void listCompteEpargne(vector<COMPTE*>);
            void listCompteCheque(vector<COMPTE*>);

            void newTransaction(vector<COMPTE*>*);
            void allTransaction(vector<COMPTE*>);
            void transByCompte(vector<COMPTE*>);

            vector<COMPTE*> loadComptes();
        protected:

        private:
            COMPTE* searchCompte(string num, vector<COMPTE*> comptes);
            void updateVector(vector<COMPTE*> *comptes, COMPTE * cp);
    };
};

#endif // SERVICES_H
