#pragma once
#include "LinkedList.h"

template <typename T>
class List {
private:
    LinkedList<T> list;

public:
    void add(T value);

    void remove(T value);

    bool isEmpty() const;

    void display();
};

#include "List.cpp"
