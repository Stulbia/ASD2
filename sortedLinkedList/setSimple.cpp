// setSimple.cpp
#include "setSimple.h"

setSimple::setSimple() : head(nullptr) {}

setSimple::~setSimple() {
    Node* cur = head;
    while (cur) {
        Node* tmp = cur->next;
        delete cur;
        cur = tmp;
    }
}

setSimple::setSimple(const setSimple& other) : head(nullptr) {
    Node* cur = other.head;
    while (cur) {
        insertNode(cur->val);
        cur = cur->next;
    }
}

setSimple& setSimple::operator=(const setSimple& other) {
    if (this == &other) return *this;
    this->~setSimple();
    head = nullptr;
    Node* cur = other.head;
    while (cur) {
        insertNode(cur->val);
        cur = cur->next;
    }
    return *this;
}

void setSimple::insertNode(int x) {
    // wstaw x w odpowiednie miejsce zachowując posortowanie
    if (!head || head->val > x) {
        head = new Node(x, head);  // na początku
        return;
    }
    Node* cur = head;
    while (cur->next && cur->next->val < x)
        cur = cur->next;
    if (cur->next && cur->next->val == x) return; // duplikat
    cur->next = new Node(x, cur->next);
}

void setSimple::insert(int x) { insertNode(x); }

void setSimple::remove(int x) {
    if (!head) return;
    if (head->val == x) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Node* cur = head;
    while (cur->next && cur->next->val != x)
        cur = cur->next;
    if (cur->next) {
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
}

bool setSimple::contains(int x) const {
    Node* cur = head;
    while (cur && cur->val <= x) {
        if (cur->val == x) return true;
        cur = cur->next;
    }
    return false;
}

// merge obu list biorąc elementy z A LUB B
setSimple setSimple::operator+(const setSimple& other) const {
    setSimple result;
    Node* a = head;
    Node* b = other.head;
    while (a && b) {
        if (a->val < b->val)      { result.insertNode(a->val); a = a->next; }
        else if (a->val > b->val) { result.insertNode(b->val); b = b->next; }
        else                      { result.insertNode(a->val); a = a->next; b = b->next; }
    }
    while (a) { result.insertNode(a->val); a = a->next; }
    while (b) { result.insertNode(b->val); b = b->next; }
    return result;
}

// tylko elementy wspólne dla A I B
setSimple setSimple::operator*(const setSimple& other) const {
    setSimple result;
    Node* a = head;
    Node* b = other.head;
    while (a && b) {
        if (a->val < b->val)      a = a->next;
        else if (a->val > b->val) b = b->next;
        else { result.insertNode(a->val); a = a->next; b = b->next; }
    }
    return result;
}

// elementy z A które NIE są w B
setSimple setSimple::operator-(const setSimple& other) const {
    setSimple result;
    Node* a = head;
    Node* b = other.head;
    while (a && b) {
        if (a->val < b->val)      { result.insertNode(a->val); a = a->next; }
        else if (a->val > b->val) b = b->next;
        else                      { a = a->next; b = b->next; }
    }
    while (a) { result.insertNode(a->val); a = a->next; }
    return result;
}

bool setSimple::operator==(const setSimple& other) const {
    Node* a = head;
    Node* b = other.head;
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return !a && !b; // obie listy muszą skończyć się równocześnie
}