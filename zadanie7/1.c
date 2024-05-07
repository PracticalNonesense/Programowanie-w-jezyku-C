#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertToNumber(char *word) {
    if (strcmp(word, "one") == 0 || strcmp(word, "o") == 0)
        return 1;
    if (strcmp(word, "two") == 0 || strcmp(word, "t") == 0)
        return 2;
    if (strcmp(word, "three") == 0 || strcmp(word, "h") == 0)
        return 3;
    if (strcmp(word, "four") == 0 || strcmp(word, "f") == 0)
        return 4;
    if (strcmp(word, "five") == 0 || strcmp(word, "v") == 0)
        return 5;
    if (strcmp(word, "six") == 0 || strcmp(word, "s") == 0)
        return 6;
    if (strcmp(word, "seven") == 0 || strcmp(word, "e") == 0)
        return 7;
    if (strcmp(word, "eight") == 0 || strcmp(word, "g") == 0)
        return 8;
    if (strcmp(word, "nine") == 0 || strcmp(word, "n") == 0)
        return 9;
    if (isdigit(word[0]))
        return word[0] - '0';
    
    return 0;
}

int calculateEnergy(char *line) {
    int totalEnergy = 0;
    char *token = strtok(line, " ");
    
    while (token != NULL) {
        totalEnergy += convertToNumber(token);
        token = strtok(NULL, " ");
    }
    
    return totalEnergy;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Nie udało się otworzyć pliku");
        return 1;
    }

    int totalEnergy = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0; // Usuwamy znak nowej linii
        totalEnergy += calculateEnergy(line);
    }

    fclose(file);

    printf("Suma wszystkich wartości energetycznych: %d\n", totalEnergy);

    return 0;
}
