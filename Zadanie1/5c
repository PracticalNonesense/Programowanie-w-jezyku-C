#include <stdio.h>

int suma_wielokrotnosci(int n) {
    // Jeśli liczba jest ujemna, zwracamy 0
    if (n < 0)
        return 0;

    int suma = 0;
    for (int i = 1; i < n; i++) {
        // Sprawdzamy czy liczba jest wielokrotnością 3 lub 5
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i;
        }
    }
    return suma;
}

int main() {
    int liczba;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);

    int wynik = suma_wielokrotnosci(liczba);
    printf("Suma wielokrotnosci 3 i 5 ponizej liczby %d wynosi: %d\n", liczba, wynik);

    return 0;
}
