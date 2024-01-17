#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class Priority
{
private:
    Node<T>* front;

public:
    Priority() : front(nullptr) {}

    void enqueue(T newItem, int priority)
    {
        Node<T>* newNode = new Node<T>(newItem, priority);

        if (front == nullptr || priority > front->getPriority())
        {
            newNode->setNext(front);
            front = newNode;
        }
        else
        {
            Node<T>* current = front;

            while (current->getNext() != nullptr && priority <= (current->getNext())->getPriority())
            {
                current = current->getNext();
            }

            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }
    }

    bool Empty() { return (size == 0); }

    int Size() { return size; }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node<T>* temp = front;
        front = front->getNext();
        delete temp;
    }

    void display()
    {
        Node<T>* current = front;

        while (current != nullptr)
        {
            cout << "\nThe current item is: " << current->getItem() << "\tIts priorty is: " << current->getPriority();
            current = current->getNext();
        }

        cout << endl;
    }
};
