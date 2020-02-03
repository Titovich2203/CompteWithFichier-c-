#ifndef FICHIER_H
#define FICHIER_H
#include<string>
#include<vector>
#include<COMPTE.h>
#include<TRANSACTION.h>
#include"EPARGNE.h"
#include"CHEQUE.h"

using namespace std;

namespace modeles
{
    class FICHIER
    {
        public:
            FICHIER();
            virtual ~FICHIER();

            string GetnomFC() { return nomFC; }
            void SetnomFC(string val) { nomFC = val; }
            string GetnomFT() { return nomFT; }
            void SetnomFT(string val) { nomFT = val; }
            int addCompte(COMPTE*);
            int addTransaction(TRANSACTION*);
            vector<COMPTE*> getAllComptes();
            vector<TRANSACTION*> getAllTransactions();

        protected:

        private:
            string nomFC;
            string nomFT;
    };
};
#endif // FICHIER_H
