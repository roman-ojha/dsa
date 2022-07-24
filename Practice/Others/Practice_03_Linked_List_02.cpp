#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *setLinkedList(int size)
{
    cout << "Enter " << size << " Element:" << endl;
    struct Node *Nodes[size];
    Nodes[0] = (struct Node *)malloc(sizeof(struct Node));
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            cout << "Element " << i + 1 << ":";
            cin >> Nodes[i]->data;
            Nodes[i]->next = NULL;
        }
        else
        {
            cout << "Element " << i + 1 << ": ";
            cin >> Nodes[i]->data;
            Nodes[i + 1] = (struct Node *)malloc(sizeof(struct Node));
            Nodes[i]->next = Nodes[i + 1];
        }
    }
    return Nodes[0];
}

void traversel(struct Node *ptr)
{
    printf("Entered number are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertionAtBegining(struct Node *head, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertionAtEnd(struct Node *head, int value)
{
    struct Node *temp = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr->data = value;
    temp->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *insertInBetween(struct Node *head, int value, int index)
{
    int i = 0;
    struct Node *temp = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    while (i < index)
    {
        temp = temp->next;
        i++;
    }
    ptr->data = value;
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

struct Node *insertAfterNode(struct Node *prevNode, struct Node *head, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

struct Node *deletionAtBiginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deletionInBetween(struct Node *head, int index)
{
    int i = 0;
    struct Node *temp1 = head;
    while (i < index - 1)
    {
        temp1 = temp1->next;
    }
    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    q = q->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// struct Node *deletionAfterNode(struct Node *head, struct Node *preNode)
// {
// }

int main()
{
    int size = 5;
    struct Node *head;
    head = setLinkedList(size);
    head = insertionAtBegining(head, 5);
    head = insertionAtEnd(head, 6);
    head = insertInBetween(head, 7, 2);
    head = insertAfterNode((head->next)->next, head, 8);
    traversel(head);
    cout << "\nDeleting:\n";
    head = deletionAtBiginning(head);
    // head = deletionInBetween(head, 3);
    head = deletionAtEnd(head);
    traversel(head);
    return 0;
}