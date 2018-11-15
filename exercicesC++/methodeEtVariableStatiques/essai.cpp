#include "essai.h"
#include <istream>


Essai::Essai()
{

}

int Essai::test()
{
    static int nb = 0;
    return nb++;
}





