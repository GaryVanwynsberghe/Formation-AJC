#include <stdio.h>
#include <stdlib.h>

int j1 = 1;
int j2 = 2;
int j3;
static int k1;
static int k2;
static int k3;

char tab2[] = "Coucou";

int max (int x, int y)
    {
        if (x>y)
            return x;
        else
            return y;
    }

int main()
{
    /*int i = 1;
    while (i != 0)
        {
            printf("coucou\n");
            char *nom;
            nom = (char*) malloc(32000);
            free (nom);
        }*/

    int i1 = 2;
    int i2;
    int i3;

    printf("adresse locale i1 %p\nadresse locale i2 %p\nadresse locale i3 %p\n\n", &i1, &i2, &i3);
    int *pi1;
    pi1=(int*)malloc(10);
    printf("adresse locale *pi1 %p\n", &pi1);
    int *pi2;
    pi2=(int*)malloc(10);
    printf("adresse locale *pi2 %p\n", pi2);
    int *pi3;
    pi3=(int*)malloc(10);
    printf("adresse locale *pi3 %p\n\n", pi3);


    printf("adresse globale j1 %p\nadresse globale j2 %p\nadresse globale j3 %p\n\n", &j1, &j2, &j3);
    /*int *pj1;
    pj1=(int*)malloc(10);
    printf("adresse locale *pj1 %p\n", &pj1);
    int *pj2;
    pj2=(int*)malloc(10);
    printf("adresse locale *pj2 %p\n", pj2);
    int *pj3;
    pj3=(int*)malloc(10);
    printf("adresse locale *pj3 %p\n\n", pj3);*/


    printf("adresse staique k1 %p\nadresse statique k2 %p\nadresse statique k3 %p\n\n", &k1, &k2, &k3);

    char tab[] = "Bonjour";
    printf("adresse locale tab %p\n\n", &tab[0]);

    printf("adresse locale tab2 %p\n\n", &tab2[0]);

    const int l1;

    printf("adresse constante l1 %p\n\n", &l1);

    printf("adresse fonction max %p\n\n", max);

}
