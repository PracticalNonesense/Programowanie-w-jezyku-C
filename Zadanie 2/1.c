#include <stdio.h>

int main()
{
    int a = 2;
    int* pnt = &a;
    
    *pnt = *pnt + 8;
 
    printf("%i %i", *pnt, a);

    return 0;
}
