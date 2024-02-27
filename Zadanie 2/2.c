#include <stdio.h>

float Func(float b){
    float* pnt = &b;
    
    *pnt = *pnt * 2;
    
    return *pnt;
}

int main()
{
    float a = 20;
    
    float wynik = Func(a);
    printf("%0.2f", wynik);

    return 0;
}
