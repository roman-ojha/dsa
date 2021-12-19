#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr)
{
    if (ptr == NULL)
    {
        // when the memroy full while creating the node
        return 1;
    }
    return 0;
}

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    if (isEmpty(head))
    {
        printf("Linked List is empty");
    }
    else
    {
        int i = 0;
        while (ptr != NULL)
        {
            cout << "Element " << i << ": " << ptr->data << endl;
            ptr = ptr->next;
            i++;
        }
    }
}

struct Node *insertationAtBeginning(struct Node *head, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    if (isEmpty(head))
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
    }
    else
    {
        ptr->next = head;
        ptr->prev = NULL;
        head = ptr;
    }
    return head;
}

struct Node *insertationAtEnd(struct Node *head, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;
    struct Node *temp = head;
    if (isEmpty(head))
    {
        ptr->prev = NULL;
        head = ptr;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    return head;
}

struct Node *insertationAtIndex(struct Node *head, int value, int index)
{
    // index 0 --> index 1 --> index 2 --> index 3
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    struct Node *temp = head;
    if (isEmpty(head))
    {
        cout << "Index doesn't exist" << endl;
    }
    else if (index == 0)
    {
        head = insertationAtBeginning(head, value);
    }
    else
    {
        int i = 1;
        while (i < index && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL && i < index)
        {
            cout << "Index doesn't exist" << endl;
        }
        else if (temp->next == NULL && i == index)
        {
            // at the end
            head = insertationAtEnd(head, value);
        }
        else
        {
            // in between
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next->prev = ptr;
            temp->next = ptr;
        }
    }
    return head;
}

struct Node *insertationAtParticularPosition(struct Node *head, int value, int position)
{
    // position 1 --> position 2 --> position 3 --> psition 4
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    ptr->data = value;
    if (isEmpty(head))
    {
        cout << "given Position doesn't exist" << endl;
    }
    else if (position == 1)
    {
        head = insertationAtBeginning(head, value);
    }
    else
    {
        int i = 2;
        while (i < position && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL && i < position)
        {
            cout << "Position doesn't exist" << endl;
        }
        else if (temp->next == NULL && i == position)
        {
            head = insertationAtEnd(head, value);
        }
        else
        {
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next->prev = ptr;
            temp->next = ptr;
        }
    }
    return head;
}

int main()
{
    struct Node *head;
    head = NULL;
    head = insertationAtBeginning(head, 3);
    head = insertationAtBeginning(head, 4);
    head = insertationAtEnd(head, 10);
    head = insertationAtEnd(head, 12);
    head = insertationAtIndex(head, 20, 4);
    head = insertationAtParticularPosition(head, 23, 5);
    traversal(head);
    return 0;
}