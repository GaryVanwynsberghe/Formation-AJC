#include <stdio.h>

typedef struct _align
{
    double d; /* 8 octets */
    int i; /* 4 octets */
    char c2[3] ;/* 3 octets */
    char c; /* 1 octet */
}align; /* 16 octets */

typedef struct _noalign
{
    char c; /* 1 octet */
    double d; /* 8 octets */
    int i; /* 4 octets */
    char c2[3]; /* 3 octets */
}noalign; /* 24 octets car padding */

int main()
{




    printf("%d\n", sizeof (noalign));

    /*printf("%d\n", (sizeof char (c)));
    printf("%d\n", (sizeof (d)));
    printf("%d\n", sizeof (i));
    printf("%d\n", sizeof (c2));*/


    printf("%d\n", sizeof (align));

    /*printf("%d\n", sizeof (char));
    printf("%d\n", sizeof (double));
    printf("%d\n", sizeof (int));
    printf("%d\n", sizeof (char));*/


    //Structure chaine de caractère

   /* struct eleve
    {
        char prenom [50];
        struct eleve *suivant;
    };
    struct eleve *premier;
    premier = (struct eleve*) malloc (sizeof(struct eleve));
    strcpy (premier->prenom, "Gille");
    premier->suivant = 0;

    struct eleve *deuxieme;
    deuxieme = (struct eleve*) malloc (sizeof(struct eleve));
    strcpy (deuxieme->prenom, "Ghania");
    deuxieme->suivant = 0;
    premier->suivant = deuxieme;

    q = premier;
    while (q->suivant != 0)
    {
        q = q->suivant;
    }*/


}
