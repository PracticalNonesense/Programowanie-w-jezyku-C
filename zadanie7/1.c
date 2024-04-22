#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateEnergy(char *line) {
    int length = strlen(line);
    if (length < 2)
        return 0;
    
    int firstDigit = line[0] - '0';
    int lastDigit = line[length - 1] - '0';
    
    return (firstDigit * 10) + lastDigit;
}

int main() {
    // Otwarcie pliku
    FILE *file = fopen("inout.txt", "r");
    if (file == NULL) {
        perror("Nie udało się otworzyć pliku");
        return 1;
    }

    // Suma wszystkich wartości energetycznych
    int totalEnergy = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        totalEnergy += calculateEnergy(line);
    }

    // Zamknięcie pliku
    fclose(file);

    printf("Suma wszystkich wartości energetycznych: %d\n", totalEnergy);

    return 0;
}
