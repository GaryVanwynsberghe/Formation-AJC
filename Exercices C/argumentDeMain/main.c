#include <stdio.h>

void main(int argc, char *argv[])
{
    printf("%d\n", argc);
    printf("Le nom du programme est %s\n", argv[0]);
    int i;
    for (i=1; i<argc ;i++)
    {
        printf("%s\n", argv[i]);
    }

}
