#include "fille.h"
#include "mere.h"
#include <iostream>


Fille::Fille()
{

}

int Fille::fonctionMemeSignature(int x, int y)
{
    std::cout<<"Je suis la fonction fille"<<std::endl;
    return x * y;
}
