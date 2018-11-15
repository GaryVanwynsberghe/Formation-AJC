#include <iostream>

using namespace std;

void classe (int *p1, int *p2)
{
    if (*p2<*p1)
    {
        int temporaire=*p2;
        *p2=*p1;
        *p1 = temporaire;
    }
}


int main()
{

    int p1 = 5;
    int *pt1 = &p1;

    int p2 = 3;
    int *pt2 = &p2;

    /*int *pt1;
    *pt1=5;
    int *pt2 ;
    *pt2=3;*/

    printf("p1 : %d et p2 : %d\n", p1,p2);

    classe(pt1,pt2);
    cout<<p1<<endl<<p2<<endl;
    printf("p1 : %d et p2 : %d\n", p1,p2);

}
