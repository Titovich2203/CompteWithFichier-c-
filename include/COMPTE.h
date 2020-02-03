#ifndef COMPTE_H
#define COMPTE_H
#include<TRANSACTION.h>
#include<iostream>
#include<vector>

using namespace std;


namespace modeles
{
    class COMPTE
    {
        public:
            COMPTE();
            virtual ~COMPTE();

            unsigned int Getcpt() { return cpt; }
            void Setcpt(unsigned int val) { cpt = val; }
            unsigned int Getid() { return id; }
            void Setid(unsigned int val) { id = val; }
            string Getnum() { return num; }
            void Setnum(string val) { num = val; }
            double Getsolde() { return solde; }
            void Setsolde(double val) { solde = val; }
            vector<TRANSACTION*> GetTransactions() { return transactions; }
            void SetTransactions(vector<TRANSACTION*> val) { transactions = val; }

            string genereNumCompte();
            virtual string toString();
            virtual int isCheque() = 0;
            virtual int retirer(double mnt) = 0;
            virtual int verser(double mnt) = 0;
            virtual int virement(double mnt, COMPTE* cp) = 0;


        protected:
            unsigned int id;
            string num;
            double solde;
            vector<TRANSACTION*> transactions;
        private:
            static unsigned int cpt;
    };
};

#endif // COMPTE_H
