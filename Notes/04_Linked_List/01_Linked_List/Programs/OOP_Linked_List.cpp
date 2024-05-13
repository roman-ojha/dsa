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
  Node *head;

public:
  LinkedList(int data) { this->head = new Node(data); }

  void insertAtEnd(int data) {
    Node *newNode = new Node(data);
    newNode->next = NULL;
    Node *ptr = this->head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = newNode;
  }

  void insertAtBeginning(int data) {
    Node *newNode = new Node(data);
    Node *ptr = this->head;
    newNode->next = ptr;
    this->head = newNode;
  }

  void insertInBetween(int data, int position) {
    Node *newNode = new Node(data);
    Node *ptr = this->head;
    for (int i = 1; i < position - 1; i++) {
      if (ptr != NULL)
        ptr = ptr->next;
      else
        std::cout << "Given position doesn't exist in linkedlist" << std::endl;
    }
    Node *tempPtr = ptr->next;
    ptr->next = newNode;
    newNode->next = tempPtr;
  }

  void traversel() {
    Node *ptr = this->head;
    while (ptr != NULL) {
      std::cout << ptr->data << " -> ";
      ptr = ptr->next;
    }
    std::cout << "NULL" << std::endl;
  }
};

int main() {
  LinkedList *l = new LinkedList(10);
  l->traversel();
  l->insertAtEnd(13);
  l->traversel();
  l->insertAtBeginning(21);
  l->insertAtBeginning(32);
  l->insertAtEnd(15);
  l->insertInBetween(51, 3);
  l->insertInBetween(33, 3);
  l->insertAtBeginning(03);
  l->traversel();
  return 0;
}
