#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
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

// 1) Deletion from Beginning
void deleteFromBeginning(Node **head)
{
    if ((*head) == NULL)
    {
        cout << "Head is Null" << endl;
        return;
    }
    Node *temp = (*head);
    (*head) = (*head)->next;
    delete temp;
}

// 2) Deletion from End
void deleteFromEnd(Node **head)
{
    Node *ptr = (*head);
    if ((*head) == NULL)
    {
        cout << "Head is Null" << endl;
        return;
    }
    else if ((*head)->next == NULL)
    {
        delete (*head)->next;
        (*head) = NULL;
        return;
    }
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = NULL;
    delete temp;
}

// 3) Deletion After given Node
void deleteAfter(Node **prev_node)
{
    if ((*prev_node) == NULL)
    {
        cout << "Given node is NULL" << endl;
        return;
    }
    else if ((*prev_node)->next == NULL)
    {
        delete (*prev_node);
        (*prev_node) = NULL;
        return;
    }
    Node *temp = (*prev_node)->next;
    (*prev_node)->next = (*prev_node)->next->next;
    delete temp;
}

int main()
{
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromEnd(&head);
    deleteAfter(&head->next);
    printList(head);
    return 0;
}
