#ifndef SERVICES_H
#define SERVICES_H
#include<COMPTE.h>
#include<TRANSACTION.h>
#include<vector>

namespace modeles
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

        protected:

        private:
    };
};

#endif // SERVICES_H
