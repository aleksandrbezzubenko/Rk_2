// Copyright 2018 Your Name <your_email>
#include "queue.hpp"
void Construct(Queue& queue)
{
    queue.Head = nullptr;
    queue.Tail = nullptr;
}
void Destruct(Queue& queue)
{
    while ((queue.Head != nullptr) && (queue.Tail != nullptr)) {
        Queue::Node* tmp = queue.Head;
        if (queue.Head == queue.Tail) {
            queue.Tail = nullptr;
        }
        queue.Head = queue.Head->Next;
        delete tmp;
    }
    queue.Head = nullptr;
    queue.Tail = nullptr;
}
void Push(Queue& queue, int value)
{
    Queue::Node* tmp = new Queue::Node();
    Queue::Node* pred;
    tmp->Data = value;
    if (!Empty(queue))
    {
        pred = queue.Head;
        while (pred->Next != nullptr) {
            pred = pred->Next;
        }
        pred->Next = tmp;
    } else {
        queue.Head = tmp;
    }
    queue.Tail = tmp;
}
int Pop(Queue& queue)
{
    if ((queue.Head == nullptr) && (queue.Tail == nullptr)) {
        return 0;
    }
    int dt = queue.Head->Data;
    if (queue.Head != nullptr)
    {
        Queue::Node* Node = queue.Head;
        if (queue.Head == queue.Tail) {
            queue.Tail = nullptr;
        }
        queue.Head = queue.Head->Next;
        delete Node;
    }
    return dt;
}
bool Empty(const Queue& queue)
{
    if ((queue.Head == nullptr) && (queue.Tail == nullptr)) {
        return true;
    } else {
        return false;
    }
}
