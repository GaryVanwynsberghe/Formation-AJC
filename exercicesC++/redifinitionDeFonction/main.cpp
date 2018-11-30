
#include<iostream>
#include"classmere.h"
#include"classfille.h"


int main ()
{
    printf("\nEn passant par la définition mere\n");
    ClassFille b;
    b.ClassMere::age(45);

    printf("\nEn passant par la définition fille\n");
    ClassFille a;
    a.age(35);
}
