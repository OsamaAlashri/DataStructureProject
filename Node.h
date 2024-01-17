#ifndef _NODE
#define _NODE

template<typename T>
class Node
{
private:
    T item;
    int priority;
    Node<T>* next;

public:
    Node() : priority(0), next(nullptr) {}

    Node(T newItem, int newPriority) : item(newItem), priority(newPriority), next(nullptr) {}

    void setItem(T newItem)
    {
        item = newItem;
    }

    void setPriority(int newPriority)
    {
        priority = newPriority;
    }

    void setNext(Node<T>* nextNodePtr)
    {
        next = nextNodePtr;
    }

    T getItem() const
    {
        return item;
    }

    int getPriority() const
    {
        return priority;
    }

    Node<T>* getNext() const
    {
        return next;
    }
};

#endif