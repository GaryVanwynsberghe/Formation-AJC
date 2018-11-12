#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//En utilisant typedef, cela permet de se passer des struct dans le code
struct Livre
{
    char auteur[300];
    char titre[200];
    short an;
    struct Livre *suivant;
};

void new (char auteur, char titre, short an)
{
    struct Livre *q;

    q = (struct Livre*)malloc (sizeof(struct Livre));

    strcpy (q->auteur, auteur);
    strcpy (q->titre, titre);
    q->an = 1996;

    q->suivant = 0;

    struct Livre *p;
    while (p->suivant != 0)
    {
        p = p->suivant;
    }
    p->suivant = q;
}

int main()
{
    struct Livre *premier;
    premier = (struct Livre*)malloc (sizeof(struct Livre));
    strcpy (premier->auteur, "Stephen KING");
    strcpy (premier->titre, "La ligne verte");
    premier->an = 1996;

    premier->suivant = 0;

    struct Livre *p;
    p = (struct Livre*)malloc (sizeof(struct Livre));
    strcpy (p->auteur, "Dan BROWN");
    strcpy (p->titre, "Da vinci code");
    p->an = 2006;

    p->suivant = 0;

    premier->suivant = p;

    struct Livre *p1;
    p1 = (struct Livre*)malloc (sizeof(struct Livre));
    strcpy (p1->auteur, "Molière");
    strcpy (p1->titre, "Le malade imaginaire");
    p1->an = 1673;

    p1->suivant = 0;

    p->suivant = p1;

    struct Livre *p2;
    p2 = (struct Livre*)malloc (sizeof(struct Livre));
    strcpy (p2->auteur, "Victor HUGO");
    strcpy (p2->titre, "Les misérables");
    p2->an = 1862;

    p2->suivant = 0;

    p1->suivant = p2;

    struct Livre *p3;
    p3 = (struct Livre*)malloc (sizeof(struct Livre));
    strcpy (p3->auteur, "Charles BAUDELAIRE");
    strcpy (p3->titre, "Les fleurs du mal");
    p3->an = 1857;

    p3->suivant = 0;

    p2->suivant = p3;

    struct Livre *q;
    q = premier;
    while (q->suivant != 0)
    {
        printf("%s\n", q->titre);
        q = q->suivant;
    }
}
