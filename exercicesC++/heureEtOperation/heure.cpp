#include "heure.h"
#include<iostream>


Heure::Heure(int h, int m, int s) : heure(h), minute(m), seconde(s)
{

}

void Heure::Affiche()
{
    std::cout<< heure << "h" << minute << "m" << seconde << "s" <<std::endl;
}

Heure Heure::operator+(Heure newHeure)
{
    Heure ret;

   int s = seconde + newHeure.seconde;
   int m = 0;
   int h = 0;

   if (s > 60)
   {
       s = s%60;
       m = (seconde + newHeure.seconde)/60;
   }

   m = m + (minute + newHeure.minute);

   if (m > 60)
   {
       m = m%60;
       h = (minute + newHeure.minute)/60;
   }

   h = h + (heure + newHeure.heure);

    ret.seconde= s;
    ret.minute= m;
    ret.heure= h;
   return ret ;

}



