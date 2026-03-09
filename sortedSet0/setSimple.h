#ifndef SETSIMPLE_H
#define SETSIMPLE_H

#include <vector>

class setSimple {
private:
    std::vector<bool> elements;
    int N; // Rozmiar uniwersum

public:
    // Konstruktor: tworzy pusty zbiór dla N elementów
    explicit setSimple(int size);

    // Operacje na elementach
    void insert(int x);     // x to indeks 0...N-1
    void remove(int x);
    bool contains(int x) const;

    // Operacje na zbiorach (zwracają nowy obiekt)
    setSimple operator+(const setSimple& other) const; // Suma (A U B)
    setSimple operator*(const setSimple& other) const; // Część wspólna (A n B)
    setSimple operator-(const setSimple& other) const; // Różnica (A - B)
    bool operator==(const setSimple& other) const;    // Identyczność (A == B)
};

#endif