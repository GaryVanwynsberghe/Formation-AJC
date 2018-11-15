#ifndef CONSTRUCTEURCOPIE_H
#define CONSTRUCTEURCOPIE_H


class ConstructeurCopie
{
public:
    ConstructeurCopie();
    int i =2;
    int *p = &i;
    void methodePrint();
    ConstructeurCopie (const ConstructeurCopie &source);   //Constructeur permettant une copie non synthétisé
};

#endif // CONSTRUCTEURCOPIE_H
