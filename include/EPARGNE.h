#ifndef EPARGNE_H
#define EPARGNE_H

#include <COMPTE.h>
#include<DATE.h>

namespace modeles
{
    class EPARGNE : public COMPTE
    {
        public:
            EPARGNE();
            virtual ~EPARGNE();

            double Gettaux() { return taux; }
            void Settaux(double val) { taux = val; }
            DATE* Getdate() { return dateFinB; }
            void Setdate(DATE* val) { dateFinB = val; }

            virtual string toString();
            virtual int retirer(double mnt);
            virtual int verser(double mnt);
            virtual int virement(double mnt, COMPTE* cp);

            virtual int isCheque(){ return 0; }
        protected:

        private:
            double taux;
            DATE *dateFinB;
    };
};


#endif // EPARGNE_H
