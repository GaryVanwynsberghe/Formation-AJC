#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Initialiser sans malloc

    /*char *p;
    *p = 'a';
    printf("%c\n", *p);*/


    //Allouer avec malloc et initialiser

    char *p;
    p = (char*)malloc(10);
    *p = 'a';
    printf("%c\n", *p);



    free(p);
    //free(p);

}

