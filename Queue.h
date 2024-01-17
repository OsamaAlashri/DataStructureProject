#pragma once
#include "LinkedList.h"

template <typename T>
class Queue {
private:
    LinkedList<T> list;

public:
    void enqueue(T value);

    T dequeue();

    bool isEmpty() const;

    void display();

    T front() { return Head->getItem(); }

    Iterator begin() const {
        return Iterator(Head);
    }
};

