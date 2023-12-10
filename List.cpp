#include "List.h"
#include <iostream>

template <typename T>
void List<T>::add(T value) {
    list.append(value);
}

template <typename T>
void List<T>::remove(T value) {
    LinkedNode<T>* current = list.getHead();
    LinkedNode<T>* prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev == nullptr) {
            list.setHead(current->next);
        }
        else {
            prev->next = current->next;
        }

        delete current;
    }
}

template <typename T>
bool List<T>::isEmpty() const {
    return list.getHead() == nullptr;
}

template <typename T>
void List<T>::display() {
    list.display();
}
