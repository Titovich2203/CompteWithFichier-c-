#ifndef DATE_H
#define DATE_H


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
            void affiche();
        protected:

        private:
            int jj;
            int mm;
            int aa;
    };
};

#endif // DATE_H
