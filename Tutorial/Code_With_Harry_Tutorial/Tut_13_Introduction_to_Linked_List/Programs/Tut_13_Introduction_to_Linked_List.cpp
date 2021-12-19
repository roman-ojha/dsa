#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node1
{
    int data;
    struct Node *next; // Self referencing structure
};
// this is the way we can make linked list in which
// one is the data and another is the pointer which point the same node of the different data in different address
// here the time complexity of linked list is O(n)

// This is the way to take a input data of any size
//------------------------------------------------------------------------
struct Node
{
    int data;
    struct Node *next;
};

// we can make linked list by doing this as well
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
    return 0;
}