#include <iostream>
#include "essai.h"


using namespace std;

int main()
{
    Essai deux;

    for (int i=0; i<10; i++)
    {
        std::cout<<"Nombre : "<<deux.test()<<std::endl;
        //printf("nb = %d\n", deux.test());
    };
}
