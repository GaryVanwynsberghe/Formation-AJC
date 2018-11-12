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



    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%s\t %s\t %d\n", livres[i].auteur, livres[i].titre, livres[i].an);

    }

    FILE *fichier;

    fichier = fopen("bibliotheque.txt","w+");

    if (fichier == 0)
    {
        printf("Attention pas de fichier créé");
    }


    //fwrite( livres, sizeof(livres), 1, fichier);
    fprintf(fichier, "%s\t %s\t %d\n",livres[].auteur, livres[].titre, livres[].an);

    fclose(fichier);




}
