#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// 1) Insert At the front of the linked list
// head return approach
// Node *push(Node *head, int new_data)
// {
//     Node *new_node = new Node();
//     new_node->data = new_data;
//     new_node->next = head;
//     return new_node;
// }
// without return approach
void push(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

// 2) Insert at given node
void insertAfter(Node *prev_node, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    if (prev_node == NULL)
    {
        cout << "Can't insert after Null Node" << endl;
        return;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// 3) Insert At the end of the linked list
void append(Node *head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    push(&head, 3);
    push(&head, 5);
    append(head, 4);
    append(head, 7);
    insertAfter(head->next->next, 13);
    printList(head);
    return 0;
}
