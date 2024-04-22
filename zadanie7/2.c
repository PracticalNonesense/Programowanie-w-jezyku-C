#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GAMES 1000
#define MAX_ROUNDS 100

struct Game {
    int id;
    int red_count;
    int green_count;
    int blue_count;
};

bool isPossible(struct Game game, int red, int green, int blue) {
    if (game.red_count > red || game.green_count > green || game.blue_count > blue)
        return false;
    return true;
}

int main() {
    struct Game games[MAX_GAMES]; // tablica gier
    int games_count = 0; // licznik gier
    int red_available = 12, green_available = 13, blue_available = 14;

    // Otwarcie pliku
    FILE *file = fopen("input_2.txt", "r");
    if (file == NULL) {
        perror("Nie udało się otworzyć pliku");
        return 1;
    }

    char line[500];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " ");
        sscanf(token, "Gra %d:", &games[games_count].id);
        games[games_count].red_count = games[games_count].green_count = games[games_count].blue_count = 0;

        while ((token = strtok(NULL, " ")) != NULL) {
            int count;
            char color[10];
            sscanf(token, "%d %s,", &count, color);
            if (strcmp(color, "czerwone") == 0)
                games[games_count].red_count += count;
            else if (strcmp(color, "zielone") == 0)
                games[games_count].green_count += count;
            else if (strcmp(color, "niebieskie") == 0)
                games[games_count].blue_count += count;
        }
        games_count++;
    }

    // Zamknięcie pliku
    fclose(file);

    int possible_games[MAX_GAMES];
    int possible_count = 0;
    for (int i = 0; i < games_count; i++) {
        if (isPossible(games[i], red_available, green_available, blue_available)) {
            possible_games[possible_count++] = games[i].id;
        }
    }

    int sum = 0;
    printf("Możliwe gry: ");
    for (int i = 0; i < possible_count; i++) {
        printf("%d ", possible_games[i]);
        sum += possible_games[i];
    }
    printf("\nSuma identyfikatorów możliwych gier: %d\n", sum);

    return 0;
}
