#include "EventQueue.h"

EventQueue::EventQueue() : front(nullptr), rear(nullptr) {}

EventQueue::~EventQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void EventQueue::enqueue(Event* newEvent) {
    Node* newNode = new Node(newEvent);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Event* EventQueue::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }

    Node* temp = front;
    Event* frontEvent = temp->data;

    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return frontEvent;
}

bool EventQueue::isEmpty() const {
    return front == nullptr;
}
