// Copyright 2018 Your Name <your_email>
#include "queue.hpp"
Queue::Queue()
{
    Head = nullptr;
    Tail = nullptr;
}
Queue::~Queue()
{
    while ((Head != nullptr) && (Tail != nullptr)) {
        Node* tmp = Head;
        if (Head == Tail) {
            Tail = nullptr;
        }
        Head = Head->Next;
        delete tmp;
    }
    Head = nullptr;
    Tail = nullptr;
}
void Queue::Push(int value)
{
    Node* tmp = new Node();
    Node* pred;
    tmp->Data = value;
    if (!this->Empty())
    {
        pred = Head;
        while (pred->Next != nullptr) {
            pred = pred->Next;
        }
        pred->Next = tmp;
    } else {
        Head = tmp;
    }
    Tail = tmp;
}
int Queue::Pop()
{
    if ((Head == nullptr) && (Tail == nullptr)) {
        return 0;
    }
    int dt = Head->Data;
    if (Head != nullptr)
    {
        Node* Node = Head;
        if (Head == Tail) {
            Tail = nullptr;
        }
        Head = Head->Next;
        delete Node;
    }
    return dt;
}
bool Queue::Empty()
{
    if ((Head == nullptr) && (Tail == nullptr)) {
        return true;
    } else {
        return false;
    }
}
Node* Queue::front()
{
    return this->Head;
}
Node* Queue::back()
{
    return this->Tail;
}
