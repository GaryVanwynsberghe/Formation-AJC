#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palindrome (char tab1[], char tab2[])
{
    int i;
    for (i=0; i< strlen(tab1); i++)
        {
            tab2[i] = tab1[strlen(tab1)-1-i];
        }

}



int main()
{
    char tab1[] = "maman";
    char tab2;
    printf("%s\n", palindrome(tab1, tab2));




    /*char *p="ceci est une chaine";
    char *q = p;
    while (*q)
    {
        printf("%c\t", *q++);
        printf("adresse pointeur %p\n",q);
    }*/


    /*while (*q != 0)
    {
        printf("%c\t", *q);
        printf("%p\n",q);

        q = q + 1;
    }*/

    //Modifier la première lettre d'un tableau :
        //char tableau [] = "bonjour";
        //char *tab = "bonjour";


    /*char tableau[] = "bonjour";
    tableau [0] = 'B';
    printf("%s\n",tableau);*/

    /*char *tab = "bonjour";
    *tab = 'B';
    printf("%s\n",*tab);*/


}

