#include <iostream>
using namespace std;

class Node
{
    int data;

public:
    Node *next;
    Node(int d)
    {
        data = d;
    }
};

void push(Node **top, int data)
{
    Node *new_node = new Node(data);
    if (top == NULL)
    {
        new_node->next = NULL;
        (*top) = new_node;
        return;
    }
    new_node->next = (*top);
    (*top) = new_node;
}

int main()
{
    Node *top = NULL;
    return 0;
}