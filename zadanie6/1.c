#include <stdio.h>

// Definicja unii
union Dane {
    int calkowita;
    float zmiennoprzecinkowa;
    char znak;
};

int main() {
    // Inicjalizacja unii
    union Dane dane;

    // Przechowywanie i wyświetlanie wartości typu int
    dane.calkowita = 10;
    printf("Wartość typu int: %d\n", dane.calkowita);

    // Przechowywanie i wyświetlanie wartości typu float
    dane.zmiennoprzecinkowa = 3.14;
    printf("Wartość typu float: %f\n", dane.zmiennoprzecinkowa);

    // Przechowywanie i wyświetlanie wartości typu char
    dane.znak = 'A';
    printf("Wartość typu char: %c\n", dane.znak);

    return 0;
}
