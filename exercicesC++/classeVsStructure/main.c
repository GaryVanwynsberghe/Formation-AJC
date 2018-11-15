#include <stdio.h>
#include <stdlib.h>
struct toto
    {
        int i;
        /*void clear()
        {
            i=0;
        }*/
    };

int main()
{
    struct toto *p;
    p = (struct toto *) malloc(sizeof(struct toto));
    p->i = 2;

    printf("%d\n",p->i);

    //clear(toto);
}
