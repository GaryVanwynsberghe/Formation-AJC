#include <stdio.h>
#include <stdlib.h>

int main()
{
//Taille mémoire
    /*long unsigned i=24;
    int j=24;
    printf("Taille mémoire entier : %d\nTaille mémoire adresse : %d\nTaille mémoire long unsigned : %d\n", sizeof(j),sizeof(&j),sizeof(i));*/



//Boucle
/*int f=1;
while (f<=10)
{
    if (f %2 == 0)
        printf("Bonjour \n");
    else
        printf("Bonsoir \n");
    f++;
}*/


/*int i=0;
int j=0;
while (i<10)
{
    printf("i=%d\n",i);
    j=0;
    while (j<10)
    {
        printf("j=%d\n",j);
        if (j==5)
            break;
        j++;
    }
    i++;
}*/


/*int i=0;
do
{
    printf("i=%d\n",i);
    i=i+4;
}
while (i<50);*/


/*for (int i=0; i<100; i+=2)

    printf("%d\n",i);*/

//Codes ASCII
/*for (int i='a'; i<='z'; i++)
       printf("%c : %d\n",i,i);*/


/*for (int i='A'; i<='z'; i++)
        printf("%c : %d\n",i,i);*/


/*for (int i=50000; i<=50100; i++)
    printf("%10d\n",i);*/


/*for (int i='A'; i<='z'; i+=3)
        printf("%c : %d\t",i,i),
        printf("%c : %d\t",i+1,i+1),
        printf("%c : %d\t\n",i+2,i+2);*/


//Equivalent avec if "condensé" (?=alors et :=sinon)
/*for (int i='A'; i<='z'; i++)
        i % 3==1 ? printf("%c : %d\n",i,i) : printf("%c : %d | ",i,i);*/

//Nombre d'or

//Ici, il faut mettre le printf et le scanf dans le while mais en donnant la valeur de a=-1 ou 101
//ou faire un do while

/*srand(time(NULL));
int numberGold = rand() % 100;
int k;
int j=1;
printf("Saisir un nombre entre 0 et 100 : ");
scanf("%d",&k);

while(k!=numberGold)
{

    if (k<numberGold)
        printf("Le nombre d'or est plus grand : "),
        scanf("%d",&k);
    else //if (k>numberGold)
        printf("Le nombre d'or est plus petit : "),
        scanf("%d",&k);
j++;
}
printf("Vous avez trouvé(e) le nombre d'or en %d fois !!!",j);*/

//Tableau

int tab[30]={1};
for (int i=1; i<30; i++)
{
    tab[i] = tab[i -1]*2,
    printf("%d\n",tab[i]);

}
return(0);
}

