#ifndef HEURE_H
#define HEURE_H


class Heure
{
public:
    Heure(int h =0, int m = 0, int s = 0);

    Heure operator+(Heure newHeure);


    void Affiche();


private:
    int heure;
    int minute;
    int seconde;






};

#endif // HEURE_H
