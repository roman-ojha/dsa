#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
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
            cout << "Element " << i + 1 << ": " << ptr->data << endl;
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
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return head;
}

struct Node *insertationAtEnd(struct Node *head, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;
    struct Node *p = head;
    if (isEmpty(head))
    {
        head = ptr;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}

// this has to be revisit again
struct Node *insertationAtIndex(struct Node *head, int value, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    struct Node *p = temp->next;
    ptr->data = value;
    if (isEmpty(head))
    {
        cout << "given index " << index << " doesn't exist" << endl;
    }
    else
    {
        int i = 0;
        while (p->next != NULL)
        {
            if (i == index)
            {
                break;
            }
            p = p->next;
            temp = temp->next;
            i++;
        }
        if (i == index)
        {
            temp->next = ptr;
            ptr->next = p;
        }
        else
        {
            cout << "given index " << index << " doesn't exist" << endl;
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
    head = insertationAtBeginning(head, 5);
    head = insertationAtBeginning(head, 6);
    head = insertationAtEnd(head, 2);
    // head = insertationAtIndex(head, 10, 2);
    traversal(head);
    return 0;
}