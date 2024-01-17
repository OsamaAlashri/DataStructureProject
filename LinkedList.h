#pragma once

template <typename T>
class LinkedNode {
public:
    T data;
    LinkedNode* next;

    LinkedNode(T value);
};

template <typename T>
class LinkedList {
private:
    LinkedNode<T>* head;

public:
    LinkedList();

    void append(T value);

    void display();

    LinkedNode<T>* getHead() const;
    void setHead(LinkedNode<T>* newHead);

    void removeHead();

    int size();

    bool isEmpty() const;
};