#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GAMES 100

// Struktura do przechowywania zestawu kostek w grze
struct Game {
    int red;
    int green;
    int blue;
};

// Funkcja do parsowania danych gier z linii
void parseGame(char *line, struct Game *game) {
    char *token = strtok(line, ", ");
    while (token != NULL) {
        if (strcmp(token, "red") == 0) {
            game->red = atoi(strtok(NULL, ", "));
        } else if (strcmp(token, "green") == 0) {
            game->green = atoi(strtok(NULL, ", "));
        } else if (strcmp(token, "blue") == 0) {
            game->blue = atoi(strtok(NULL, ", "));
        }
        token = strtok(NULL, ", ");
    }
}

// Funkcja sprawdzająca, czy dana gra jest możliwa z danymi kostkami
bool isPossible(struct Game game, int redCount, int greenCount, int blueCount) {
    if (game.red <= redCount && game.green <= greenCount && game.blue <= blueCount) {
        return true;
    }
    return false;
}

int main() {
    struct Game games[MAX_GAMES];
    int numGames = 0;

    // Otwieranie pliku
    FILE *file = fopen("input_2.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    // Wczytywanie danych gier z pliku
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        struct Game game = {0}; // Inicjalizacja gry zerowymi wartościami
        parseGame(buffer, &game);
        games[numGames] = game;
        numGames++;
        if (numGames >= MAX_GAMES) { // Dodatkowe zabezpieczenie przed przepełnieniem tablicy games
            printf("Zbyt wiele gier, zwiększ MAX_GAMES.\n");
            fclose(file);
            return 1;
        }
    }

    // Kostki w torbie
    int redCount = 12;
    int greenCount = 13;
    int blueCount = 14;

    // Sprawdzanie możliwych gier
    printf("Możliwe gry:\n");
    int sum = 0;
    for (int i = 0; i < numGames; i++) {
        if (isPossible(games[i], redCount, greenCount, blueCount)) {
            printf("Gra %d\n", i + 1);
            sum += i + 1; // Dodanie identyfikatora gry do sumy
        }
    }

    printf("Suma identyfikatorów możliwych gier: %d\n", sum);

    // Zamykanie pliku
    fclose(file);

    return 0;
}
