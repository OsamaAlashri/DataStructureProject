#include "Queue.h"
#include <iostream>

template <typename T>
void Queue<T>::enqueue(T value) {
    list.append(value);
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty." << std::endl;
        exit(EXIT_FAILURE);
    }

    LinkedNode<T>* frontNode = list.getHead();
    T frontValue = frontNode->data;
    list.setHead(frontNode->next);
    delete frontNode;

    return frontValue;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return list.getHead() == nullptr;
}

template <typename T>
void Queue<T>::display() {
    list.display();
}
