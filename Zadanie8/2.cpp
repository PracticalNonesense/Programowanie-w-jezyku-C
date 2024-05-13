#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#define MAX_GAMES 100

// Struktura do przechowywania zestawu kostek w grze
struct Game {
    int red;
    int green;
    int blue;
};

// Funkcja do parsowania danych gier z linii
void parseGame(const std::string &line, Game &game) {
    std::istringstream iss(line);
    std::string token;

    while (std::getline(iss, token, ',')) {
        if (token == "red") {
            std::getline(iss, token, ',');
            game.red = std::stoi(token);
        } else if (token == "green") {
            std::getline(iss, token, ',');
            game.green = std::stoi(token);
        } else if (token == "blue") {
            std::getline(iss, token, ',');
            game.blue = std::stoi(token);
        }
    }
}

// Funkcja sprawdzająca, czy dana gra jest możliwa z danymi kostkami
bool isPossible(const Game &game, int redCount, int greenCount, int blueCount) {
    return (game.red <= redCount && game.green <= greenCount && game.blue <= blueCount);
}

int main() {
    std::vector<Game> games;
    int numGames = 0;

    // Otwieranie pliku
    std::ifstream file("input_2.txt");
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku." << std::endl;
        return 1;
    }

    // Wczytywanie danych gier z pliku
    std::string buffer;
    while (std::getline(file, buffer)) {
        Game game = {0}; // Inicjalizacja gry zerowymi wartościami
        parseGame(buffer, game);
        games.push_back(game);
        numGames++;
        if (numGames >= MAX_GAMES) { // Dodatkowe zabezpieczenie przed przepełnieniem tablicy games
            std::cerr << "Zbyt wiele gier, zwiększ MAX_GAMES." << std::endl;
            file.close();
            return 1;
        }
    }

    // Kostki w torbie
    int redCount = 12;
    int greenCount = 13;
    int blueCount = 14;

    // Sprawdzanie możliwych gier
    std::cout << "Możliwe gry:" << std::endl;
    int sum = 0;
    for (int i = 0; i < numGames; i++) {
        if (isPossible(games[i], redCount, greenCount, blueCount)) {
            std::cout << "Gra " << i + 1 << std::endl;
            sum += i + 1; // Dodanie identyfikatora gry do sumy
        }
    }

    std::cout << "Suma identyfikatorów możliwych gier: " << sum << std::endl;

    // Zamykanie pliku
    file.close();

    return 0;
}
