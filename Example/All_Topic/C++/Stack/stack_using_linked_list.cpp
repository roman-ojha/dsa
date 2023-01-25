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
    int getData()
    {
        return data;
    }
};

void push(Node **top, int data)
{
    Node *new_node = new Node(data);
    if ((*top) == NULL)
    {
        new_node->next = NULL;
        (*top) = new_node;
        return;
    }
    new_node->next = (*top);
    (*top) = new_node;
}

int pop(Node **top)
{
    if ((*top) == NULL)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int data = (*top)->getData();
    (*top) = (*top)->next;
    return data;
}

int main()
{
    Node *top = NULL;
    push(&top, 10);
    push(&top, 11);
    push(&top, 17);
    push(&top, 23);
    cout << "Popping: " << pop(&top) << endl;
    cout << "Popping: " << pop(&top) << endl;
    cout << "Popping: " << pop(&top) << endl;
    cout << "Popping: " << pop(&top) << endl;
    cout << "Popping: " << pop(&top) << endl;
    return 0;
}