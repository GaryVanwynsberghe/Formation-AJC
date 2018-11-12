#include <stdio.h>

int main()
{
    enum jours {lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche};
    enum jours j;

    int i;
    for (i = lundi; i <= dimanche ; i++)
    {
        printf("%d\n", i);
    }


}
