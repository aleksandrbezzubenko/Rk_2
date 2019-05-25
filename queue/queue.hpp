// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_QUEUE_HPP_
#define INCLUDE_QUEUE_HPP_

class Queue {
private:
  struct Node {
    Node* Next = nullptr;
    int Data = 0;
  };

  // Указатель на первый элемент очереди.
  Node* Head = nullptr;

  // Указатель на последний элемент очереди.
  Node* Tail = nullptr;
public:
  Queue();
  ~Queue();
  void Push(int value);
  int Pop();
  bool Empty();
  Node* front();
  Node* back();
};


#endif  // INCLUDE_QUEUE_HPP_
