#include "miseenoeuvreconstructeur.h"
#include <iostream>


MiseEnOeuvreConstructeur::MiseEnOeuvreConstructeur() : i(5), j(10), k('a'), l(45.25)
{

}

void MiseEnOeuvreConstructeur::Affiche()
{
    std::cout << "nombre i = " <<i <<std::endl<<"  "<< j <<"  "<<k<<"  "<<l<< std::endl;
    //printf("i = %d, j = %d, k = %c, l = %f\n", i, j, k, l);
}
