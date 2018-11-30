#include <stdio.h>

int triple(int nombre)

{
    int resultat = 0;
    resultat = 3 * nombre;
    return resultat;
}



int main()
{
    printf("Résultat : %d\n", triple(5));


    int j = 20;
    int k;


    for(int i = 0; i <= 10; i++)
    {
        printf("Numéro : %d\n", i);
    }



    int division (int a, int b, int x, int y)
    {
        return (a+b)/(x-y);
    }

    printf("Résultat de la division : %d\n", division(5,6,8,8));


    return 0;
}
