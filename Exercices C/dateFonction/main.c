#include <stdio.h>


void returnDate (char *date, int *jour, int *mois, int *annee)
{
    *jour = (date[0] - 48)*10 + (date [1] - 48);


    *mois = (date[3] -48)*10 + (date [4] -48);


    *annee = (date[6] - 48)*1000 + (date[7] - 48)*100 + (date[8] - 48)*10 + (date[9] - 48);

}



int main()
{
    char date [] = "23/03/2014";
    int jour;
    int mois;
    int annee;

    returnDate(date,&jour,&mois,&annee);

    printf("Le jour est : %d\n", jour);
    printf("Le mois est : %d\n", mois);
    printf("L'année est : %d\n", annee);




}
