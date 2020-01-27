#ifndef DATE_H
#define DATE_H
#include<iostream>

using namespace std;

namespace modeles
{
    class DATE
    {
        public:
            DATE();
            virtual ~DATE();

            int Getjj() { return jj; }
            void Setjj(int val) { jj = val; }
            int Getmm() { return mm; }
            void Setmm(int val) { mm = val; }
            int Getaa() { return aa; }
            void Setaa(int val) { aa = val; }

            void saisie();
            string affiche();
        protected:

        private:
            int jj;
            int mm;
            int aa;
    };
};

#endif // DATE_H
