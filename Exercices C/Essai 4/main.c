#include <stdio.h>
#include <stdlib.h>

int max (int x, int y)
    {
        if (x>y)
            return x;
        else
            return y;
    }

int min (int x, int y)
    {

        if (x<y)
            return x;
        else
            return y;
    }

 int ascii (char i)
    {
        //printf("%d", i);
        return i;
    }

char Char (int j)
{
    //printf("%c", j);
    return j;
}

char *premMajuscule(char chaine[])
{
    if (chaine[0]>96 && chaine[0]<123)
        chaine[0]= chaine[0]-32;

        return chaine;


}

char *majuscule(char chaine[])
{
    int i = 0;
    while(chaine[i])
    {
        if (chaine[i] > 96 && chaine[i] < 123)
            chaine[i]= chaine[i]-32;
            i++;
    }
    /*for (i=0; i < strlen(chaine); i++)
    {
        if (chaine[i] > 96 && chaine[i] < 123)
            chaine[i]= chaine[i]-32;
    }*/

        return chaine;
}

char *minuscule(char chaine[])
{
    int i;
    for (i=0; i< strlen(chaine); i++)
    {
        if (chaine[i]>64 && chaine[i]<97)
            chaine[i]= chaine[i]+32;
    }

        return chaine;
}


int main()
{
    printf("%d\n", max (153, 89));

    printf("%d\n", min (25, 58));

    printf("%d\n", ascii ('z'));

    printf("%c\n", Char (87));

    char ch[]="fobert";
    printf("%s\n", premMajuscule (ch));

    char chai[]="kamoulox";
    printf("%s\n", majuscule (chai));

    char chain[]="NORbERT";
    printf("%s\n", minuscule (chain));
}
