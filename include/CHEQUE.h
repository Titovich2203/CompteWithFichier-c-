#ifndef CHEQUE_H
#define CHEQUE_H

#include <COMPTE.h>

namespace modeles
{
    class CHEQUE : public COMPTE
    {
        public:
            CHEQUE();
            virtual ~CHEQUE();

            double Getinteret() { return interet; }
            void Setinteret(double val) { interet = val; }

            virtual string toString();
            virtual int isCheque(){ return 1; }
            virtual int retirer(double mnt);
            virtual int verser(double mnt);
            virtual int virement(double mnt, COMPTE* cp);
        protected:

        private:
            double interet;
    };
};

#endif // CHEQUE_H
