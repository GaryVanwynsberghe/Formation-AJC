#ifndef FILLE_H
#define FILLE_H
#include "mere.h"


class Fille : public Mere
{
public:
    Fille();
    int i;
    int j;

    int fonctionMemeSignature(int x, int y);
};

#endif // FILLE_H
