#include <stdio.h>

typedef struct
    {
        char auteur[30];
        char titre[50];
        short an;
    }Livre;

int main()
{


    Livre livres[5] = {{"Stephen KING", "La ligne verte", 1996},{"Dan BROWN", "Da vinci code", 2006},
                        {"Molière", "Le malade imaginaire", 1673},{"Victor HUGO", "Les misérables", 1862},
                        {"Charles BAUDELAIRE", "Les fleurs du mal", 1857}};

    Livre *px=&livres[0];
    //printf("%s\n", px->titre);
    //px++;
    //printf("%s\n", px->titre);


    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%s\t %s\t %d\n", livres[i].auteur, livres[i].titre, livres[i].an);

    }

    for (i = 0; i < 5; i++)
    {
        printf("%s\n", px->titre);
        px++;
    }

}
