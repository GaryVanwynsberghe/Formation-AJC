#include "constructeurcopie.h"
#include <iostream>

ConstructeurCopie::ConstructeurCopie()
{

}

void ConstructeurCopie::methodePrint()
{
    std::cout << *p << std::endl;


}

ConstructeurCopie::ConstructeurCopie(const ConstructeurCopie &source)
{
       i = source.i;
       p = &i;
}
