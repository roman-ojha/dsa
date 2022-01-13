#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    struct Node *temp = ptr;
    while (temp->next != ptr)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

struct Node *insertAtBegnning(struct Node *ptr, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = ptr;
    n->data = data;
    n->next = ptr;
    while (temp->next != ptr)
    {
        temp = temp->next;
    }
    temp->next = n;
    return n;
}

void insertAtEnd(struct Node *ptr, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = ptr;
    while (temp->next != ptr)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->data = data;
    n->next = ptr;
}

struct Node *insertAtIndex(struct Node *ptr, int data, int index)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = ptr;
    int i = 0;
    while (i < index - 1)
    {
        // traversing to that perticular index
        if (temp->next == ptr)
        {
            // if the given index doesn't exist
            printf("the given index doesn't exist please try again letter...");
            return ptr;
        }
        temp = temp->next;
        i++;
    }
    if (index == 0)
    {
        // if index is at beginning
        ptr = insertAtBegnning(ptr, data);
    }
    else if (temp->next == ptr)
    {
        // if index is at the end
        insertAtEnd(ptr, data);
    }
    else
    {
        // if index is at the perticular position
        n->next = temp->next;
        temp->next = n;
        n->data = data;
    }
    return ptr;
}

int main()
{
    struct Node *head;
    head->data = 10;
    head->next = head;
    // linkedListTraversal(head);
    head = insertAtBegnning(head, 15);
    head = insertAtBegnning(head, 18);
    head = insertAtBegnning(head, 39);
    head = insertAtBegnning(head, 44);
    head = insertAtBegnning(head, 51);
    insertAtEnd(head, 64);
    insertAtEnd(head, 71);
    insertAtEnd(head, 38);
    head = insertAtIndex(head, 99, 0);
    head = insertAtIndex(head, 91, 5);
    head = insertAtIndex(head, 95, 11);
    head = insertAtIndex(head, 86, 13);
    linkedListTraversal(head);
    return 0;
}