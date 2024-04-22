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

void findMinimumCounts(struct Game game, int *min_red, int *min_green, int *min_blue) {
    *min_red = game.red_count;
    *min_green = game.green_count;
    *min_blue = game.blue_count;
}

int calculatePower(int min_red, int min_green, int min_blue) {
    return min_red * min_green * min_blue;
}

int main() {
    struct Game games[MAX_GAMES]; // Tablica gier
    int games_count = 0; // Licznik gier

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

        // Parsowanie ilości kostek
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

    int total_power = 0;
    for (int i = 0; i < games_count; i++) {
        int min_red, min_green, min_blue;
        findMinimumCounts(games[i], &min_red, &min_green, &min_blue);
        total_power += calculatePower(min_red, min_green, min_blue);
    }

    printf("Suma mocy minimalnych zestawów kostek: %d\n", total_power);

    return 0;
}
