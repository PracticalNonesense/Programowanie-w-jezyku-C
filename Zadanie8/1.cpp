#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

int convertToNumber(const std::string &word) {
    static const std::unordered_map<std::string, int> wordToNumber = {
        {"one", 1}, {"o", 1},
        {"two", 2}, {"t", 2},
        {"three", 3}, {"h", 3},
        {"four", 4}, {"f", 4},
        {"five", 5}, {"v", 5},
        {"six", 6}, {"s", 6},
        {"seven", 7}, {"e", 7},
        {"eight", 8}, {"g", 8},
        {"nine", 9}, {"n", 9}
    };

    if (wordToNumber.find(word) != wordToNumber.end())
        return wordToNumber.at(word);
    else if (std::isdigit(word[0]))
        return word[0] - '0';
    
    return 0;
}

int calculateEnergy(const std::string &line) {
    int totalEnergy = 0;
    std::istringstream iss(line);
    std::string token;

    while (iss >> token) {
        totalEnergy += convertToNumber(token);
    }

    return totalEnergy;
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku" << std::endl;
        return 1;
    }

    int totalEnergy = 0;
    std::string line;

    while (std::getline(file, line)) {
        totalEnergy += calculateEnergy(line);
    }

    file.close();

    std::cout << "Suma wszystkich wartości energetycznych: " << totalEnergy << std::endl;

    return 0;
}
