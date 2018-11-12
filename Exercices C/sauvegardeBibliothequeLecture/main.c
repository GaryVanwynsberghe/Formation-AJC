#include <stdio.h>

typedef struct
{
    char auteur[30];
    char titre[50];
    short an;
}Livre;


int main()
{
    FILE *fichier;
    char buffer[50] = {0};
    fichier = fopen ("bibliotheque.txt", "r");

    if (fichier)
        printf("Fichier ouvert \n");
    else
        printf("Fichier non ouvert\n");

    fread(buffer, 50, 3, fichier);
    printf("%s\n", buffer);

    return (0);
}
