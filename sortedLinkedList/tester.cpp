#include "tester.h"
#include "setSimple.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>

// Prosta funkcja pomocnicza
static double now_ms() {
    return std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

static setSimple buildRandom(int n, int range) {
    setSimple s;
    for (int i = 0; i < n; ++i) s.insert(std::rand() % range);
    return s;
}

void runCorrectnessTests() {
    std::cout << "===== URUCHAMIANIE TESTOW POPRAWNOSCI =====\n";
    setSimple A; A.insert(1); A.insert(3);
    if(A.contains(3)) std::cout << "[OK] insert/contains\n";
    else std::cout << "[FAIL] insert/contains\n";
    // ... tutaj reszta Twoich testow ...
}

void runBenchmark(int repeatCount, const char* filename) {
    std::ofstream file(filename);
    file << "operation,n,time_ms\n"; // Nagłówek CSV

    std::vector<int> sizes = {100, 500, 1000, 5000, 10000};

    std::cout << "===== ZACZYNAM POMIARY (" << repeatCount << " powtorzen) =====\n";

    // Przykładowy pomiar (możesz dodać pętlę dla innych operacji)
    for (int n : sizes) {
        double total = 0;
        for (int r = 0; r < repeatCount; ++r) {
            setSimple s;
            double t0 = now_ms();
            for (int i = 0; i < n; ++i) s.insert(std::rand() % (2 * n));
            total += (now_ms() - t0);
        }
        file << "insert," << n << "," << (total / repeatCount) << "\n";
        std::cout << "Operacja insert, n=" << n << " zakonczona.\n";
    }

    file.close();
    std::cout << "Wyniki zapisano do: " << filename << "\n";
}