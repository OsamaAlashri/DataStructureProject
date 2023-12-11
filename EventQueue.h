#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "Event.h"

class EventQueue {
private:
    struct Node {
        Event* data;
        Node* next;
        Node(Event* eventData) : data(eventData), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    EventQueue();
    void enqueue(Event* newEvent);
    Event* dequeue();
    bool isEmpty() const;
};

#endif
