#include "mere.h"
#include <iostream>


Mere::Mere()
{

}

int Mere::fonctionMemeSignature(int x, int y)
{
    std::cout<<"Je suis la fonction mère"<<std::endl;
    return x + y;
}
