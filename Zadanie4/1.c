#include <stdio.h>

int factorial(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else if (x > 1)
    {
        /* Recursive step */
        return x* factorial(x-1) ;
    }

    /* Catch scenario when x is zero */
    return 0;
}

int main() {
    printf("%d", factorial(4));
    return 0;
}
