#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define nbmax 4

///
/// \brief The Livre struct
///
struct Livre
{
    char auteur[300];
    char titre[200];
    short an;
    struct Livre *suivant;
};

///
/// \brief nouveau
/// \param auteur
/// \param titre
/// \param an
/// \param premier
///
void nouveau (char *auteur, char *titre, short an, struct Livre *premier)
{
    struct Livre *q;

    q = (struct Livre*)malloc (sizeof(struct Livre));

    strcpy (q->auteur, auteur);
    strcpy (q->titre, titre);
    q->an = an;
    q->suivant = 0;

    struct Livre *p=premier;
    while (p->suivant != 0)
    {
        p = p->suivant;
    }
    p->suivant = q;
}

///
/// \brief **AfficheList**
/// \param *premier*
///

/**
 * @brief __AfficheList__
 * @param _premier_
 */

/*!
 * \brief __AfficheList__
 * \param _premier_
 */

void AfficheList(struct Livre *premier)
{
    struct Livre *q;
    q = premier;
    while (q->suivant != 0)
    {
        printf("%s\n", q->titre);
        q = q->suivant;
    }
    printf("%s\n",q->titre);
}


int main()
{
    struct Livre *q;
    q = (struct Livre*)malloc (sizeof(struct Livre));
    strcpy (q->auteur, "Stephen KING");
    strcpy (q->titre, "La ligne verte");
    q->an = 1996;
    q->suivant = 0;



    nouveau ("Dan BROWN", "Da vinci code", 2006,q);
    nouveau ("Molière", "Le malade imaginaire", 1673,q);
    nouveau ("Victor HUGO", "Les misérables", 1862,q);
    nouveau ("Charles BAUDELAIRE", "Les fleurs du mal", 1857,q);

    AfficheList(q);
}
int a = nbmax;




