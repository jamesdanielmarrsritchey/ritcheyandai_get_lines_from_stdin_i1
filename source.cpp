#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    int minLine = -1;
    int maxLine = -1;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--min_line") {
            minLine = std::stoi(argv[++i]);
        } else if (arg == "--max_line") {
            maxLine = std::stoi(argv[++i]);
        }
    }

    if (minLine > maxLine) {
        std::cerr << "Error: Minimum line number is greater than maximum line number.\n";
        exit(1);
    }

    std::string line;
    int lineCount = 0;

    while (std::getline(std::cin, line)) {
        lineCount++;
        if (lineCount < minLine) continue;
        if (lineCount > maxLine) break;
        std::cout << line << '\n';
    }

    if (lineCount < minLine) {
        return false;
        exit(1);
    }

    return true;
}