#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void travel(Node *head)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node;
    Node *a = new Node;
    Node *b = new Node;
    Node *c = new Node;
    head->data = 5;
    head->next = a;
    a->data = 3;
    a->next = b;
    b->data = 10;
    b->next = c;
    c->data = 13;
    c->next = NULL;
    travel(head);
    return 0;
}