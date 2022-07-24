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

//  4) Deletion of the given position node
// position = 1 (head)
void deleteNodeOfPosition(Node **head, int position)
{
    Node *ptr = (*head);
    if ((*head) == NULL)
    {
        cout << "Head is Null" << endl;
        return;
    }
    if (position == 0)
    {
        cout << "Postion 0 doesn't exist" << endl;
        return;
    }
    if (position == 1)
    {
        (*head) = (*head)->next;
        free(ptr);
        return;
    }
    for (int i = 1; i < position - 1; i++)
    {
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            cout << "Given position is doesn't exist" << endl;
            return;
        }
    }
    Node *temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
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
    push(&head, 10);
    push(&head, 13);
    push(&head, 17);
    push(&head, 20);
    deleteNodeOfPosition(&head, 5);
    printList(head);
    return 0;
}
