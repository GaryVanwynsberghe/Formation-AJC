#include <iostream>
#include "mere.h"
#include "fille.h"


using namespace std;

int main()
{
    Mere *ptr1;  //ou Mere *ptr1 = new Mere();
    Mere *ptr2;

    Mere m;
    Fille f;

    ptr1 = &m;
    ptr2 = &f;

    ptr1->fonctionMemeSignature(15,20);
    ptr2->fonctionMemeSignature(15,20);


}
