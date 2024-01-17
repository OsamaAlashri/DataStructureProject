#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedNode<T>::LinkedNode(T value) : data(value), next(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
void LinkedList<T>::append(T value) {
    LinkedNode<T>* newNode = new LinkedNode<T>(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        LinkedNode<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <typename T>
void LinkedList<T>::display() {
    LinkedNode<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
LinkedNode<T>* LinkedList<T>::getHead() const {
    return head;
}

template <typename T>
void LinkedList<T>::setHead(LinkedNode<T>* newHead) {
    head = newHead;
}


template <typename T>
int LinkedList<T>::size() {
    int count = 0; // Initialize count to 0
    LinkedNode<T>* current = head;
    while (current != nullptr) {
        current = current->next;
        count++;
    }
    return count; // Return the count
}

template <typename T>
void LinkedList<T>::removeHead() {

    if (head == nullptr) {
        return nullptr;
    }

    else {
        LinkedNode<T>* nodeToRemove = head;

        head = head->next;

        delete nodeToRemove;
    }

    template <typename T>
    bool LinkedList<T>::isEmpty() const {
        return head == nullptr;
    }




}