#include <stdio.h>

union Dane {
    int calkowita;
    float zmiennoprzecinkowa;
    char znak;
};

int main() {
    union Dane dane;
    
    dane.calkowita = 10;
    printf("Wartość typu int: %d\n", dane.calkowita);

    dane.zmiennoprzecinkowa = 3.14;
    printf("Wartość typu float: %f\n", dane.zmiennoprzecinkowa);

    dane.znak = 'A';
    printf("Wartość typu char: %c\n", dane.znak);

    return 0;
}
