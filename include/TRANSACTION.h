#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<DATE.h>


namespace modeles
{
    class TRANSACTION
    {
        public:
            TRANSACTION();
            virtual ~TRANSACTION();

            unsigned int Getcpt() { return cpt; }
            void Setcpt(unsigned int val) { cpt = val; }
            unsigned int Getid() { return id; }
            void Setid(unsigned int val) { id = val; }
            DATE* Getdate() { return date; }
            void Setdate(DATE* val) { date = val; }
            double Getmnt() { return mnt; }
            void Setmnt(double val) { mnt = val; }
            int Gettype() { return type; }
            void Settype(int val) { type = val; }
            string toString();

        protected:

        private:
            static unsigned int cpt;
            unsigned int id;
            DATE* date;
            double mnt;
            int type;
    };
};

#endif // TRANSACTION_H
