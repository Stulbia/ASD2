// setSimple.h
#ifndef SETSIMPLE_H
#define SETSIMPLE_H

class setSimple {
private:
    struct Node {
        int val;
        Node* next;
        explicit Node(int v) : val(v), next(nullptr) {}
        Node(int v, Node* n) : val(v), next(n) {}
    };

    Node* head;

    void insertNode(int x);  // helper do wstawiania w posortowanej liście

public:
    explicit setSimple();
    ~setSimple();
    setSimple(const setSimple& other);             // copy constructor
    setSimple& operator=(const setSimple& other);  // copy assignment

    void insert(int x);
    void remove(int x);
    bool contains(int x) const;

    setSimple operator+(const setSimple& other) const;
    setSimple operator*(const setSimple& other) const;
    setSimple operator-(const setSimple& other) const;
    bool operator==(const setSimple& other) const;
};

#endif