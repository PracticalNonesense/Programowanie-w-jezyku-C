#include <stdio.h>

int factorial(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else if (x > 1)
    {
        return x* factorial(x-1) ;
    }

    return 0;
}

int main() {
    printf("%d", factorial(4));
    return 0;
}
