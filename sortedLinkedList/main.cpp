#include "tester.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    // Sprawdzenie flagi -T
    bool runTests = false;
    int repeat = 1; // domyślna liczba powtórzeń

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-T") {
            runTests = true;
        } else {
            // Zakładamy, że kolejna liczba to liczba powtórzeń
            try {
                repeat = std::stoi(argv[i]);
            } catch (...) {}
        }
    }

    if (runTests) {
        runCorrectnessTests();
        runBenchmark(repeat, "results.csv");
    } else {
        std::cout << "Uzycie: ./program -T [liczba_powtorzen]\n";
    }

    return 0;
}