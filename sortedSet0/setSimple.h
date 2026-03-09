#ifndef SETSIMPLE_H
#define SETSIMPLE_H

#include <vector>

class setSimple {
private:
    std::vector<bool> elements;
    int N; // uniwersum

public:
    // Konstruktor: tworzy pusty zbiór dla N elementów
    explicit setSimple(int size);

    void insert(int x);
    void remove(int x);
    bool contains(int x) const;

    // operacje na zbiorach => nowy obiekt
    setSimple operator+(const setSimple& other) const; // A U B
    setSimple operator*(const setSimple& other) const; // A n B
    setSimple operator-(const setSimple& other) const; // A - B
    bool operator==(const setSimple& other) const;    // A == B
};

#endif