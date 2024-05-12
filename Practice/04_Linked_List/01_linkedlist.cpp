#include <iostream>

class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {
  Node head;

public:
  Node *insert(int data, Node *head) {}
};

int main() { return 0; }
