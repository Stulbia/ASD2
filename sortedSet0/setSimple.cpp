#include "setSimple.h"

// Fix: initialize vector with `size` false-values
setSimple::setSimple(int size) : N(size), elements(size, false) {}

void setSimple::insert(int x) {
    if (x >= 0 && x < N) elements[x] = true;
}

void setSimple::remove(int x) {
    if (x >= 0 && x < N) elements[x] = false;
}

bool setSimple::contains(int x) const {
    return (x >= 0 && x < N) ? elements[x] : false;
}

setSimple setSimple::operator+(const setSimple& other) const {
    setSimple result(N);
    for (int i = 0; i < N; ++i)
        result.elements[i] = elements[i] || other.elements[i];
    return result;
}


setSimple setSimple::operator*(const setSimple& other) const {
    setSimple result(N);
    for (int i = 0; i < N; ++i)
        result.elements[i] = elements[i] && other.elements[i];
    return result;
}

setSimple setSimple::operator-(const setSimple& other) const {
    setSimple result(N);
    for (int i = 0; i < N; ++i)
        result.elements[i] = elements[i] && !other.elements[i];
    return result;
}

bool setSimple::operator==(const setSimple& other) const {
    if (N != other.N) return false;
    return elements == other.elements;
}