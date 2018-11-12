#include <stdio.h>
#include <stdlib.h>

int main()

{
    int i=0;
    printf("La valeur de i est %d\n",i);
    {
        int i=2;
        printf("La valeur de i est %d\n",i);
    }
    {
        int i;
        printf("La valeur de \"i\" est %d\n",i);
    }
    {
        int i=6;
        printf("La valeur de i est %d\n",i);
    }
    {
        int i=8;
        printf("La valeur de i est %d\n",i);
    }
    printf("La valeur de i est %d\n",i);

    return 0;
}
