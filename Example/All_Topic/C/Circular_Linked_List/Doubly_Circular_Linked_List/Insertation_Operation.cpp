#include <iostream>
#include <malloc.h>
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

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    if (isEmpty(head))
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        int i = 0;
        do
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
            i++;
        } while (ptr != head);
    }
}

struct Node *insertationAtBeginning(struct Node *head, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail;
    ptr->data = value;
    if (isEmpty(head))
    {
        head = ptr;
        tail = ptr;
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        ptr->next = head;
        ptr->prev = tail;
        head = ptr;
        tail->next = head;
    }
    return head;
}

struct Node *insertationAtEnd(struct Node *head, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail;
    ptr->data = value;
    if (isEmpty(head))
    {
        head = ptr;
        tail = ptr;
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        ptr->next = head;
        ptr->prev = tail;
        tail->next = ptr;
        head->prev = ptr;
        tail = ptr;
    }
    return head;
}

// this is not completed
// struct Node *insertationAtIndex(struct Node *head, int value)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = value;
//     struct Node *tail;
//     if (isEmpty(head))
//     {
//         head = ptr;
//         tail = ptr;
//         head->next = tail;
//         head->prev = tail;
//         tail->next = head;
//         tail->prev = head;
//     }
// }

int main()
{
    struct Node *head;
    head = NULL;
    head = insertationAtBeginning(head, 5);
    head = insertationAtBeginning(head, 6);
    head = insertationAtBeginning(head, 7);
    head = insertationAtEnd(head, 10);
    traversal(head);
    return 0;
}