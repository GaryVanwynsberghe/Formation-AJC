#include <iostream>
#include "constructeurcopie.h"

using namespace std;

int main()
{
    ConstructeurCopie test1;
    test1.methodePrint();

    //ConstructeurCopie test2 = test1;   //Copie de test1
    ConstructeurCopie test2(test1);      //Copie de test1
    test2.methodePrint();
    test2.i=35;
    test2.methodePrint();



}
