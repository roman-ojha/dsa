#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr)
{
    if (ptr == NULL)
    {
        // while creation because application exceed the memory size then while creating the heap memroy or node it would return NULL
        return 1;
    }
    return 0;
}

void traversal(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Linked list is empty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
    }
}

struct Node *insertAtBegnning(struct Node *ptr, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    if (isEmpty(ptr))
    {
        n->next = NULL;
        n->prev = NULL;
        ptr = n;
    }
    else if (isFull(ptr))
    {
        printf("Memroy is full please clear the memory to run the application");
    }
    else
    {
        n->next = ptr;
        n->prev = NULL;
        ptr = n;
    }
    return ptr;
}

struct Node *insertAtEnd(struct Node *ptr, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    struct Node *temp = ptr;
    if (isEmpty(ptr))
    {
        n->next = NULL;
        n->prev = NULL;
        ptr = n;
    }
    else if (isFull(ptr))
    {
        printf("Memroy is full please clear the memory to run the application");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        n->next = NULL;
    }
    return ptr;
}

struct Node *insertAtIndex(struct Node *ptr, int data, int index)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    struct Node *temp = ptr;
    if (isFull(ptr))
    {
        printf("full memory");
        return ptr;
    }
    else if (isEmpty(ptr))
    {
        cout << "Index doesn't exist" << endl;
    }
    else if (index == 0)
    {
        ptr = insertAtBegnning(ptr, data);
        return ptr;
    }
    else
    {
        int i = 1;
        while (i < index)
        {
            if (temp->next == NULL)
            {
                printf("index doesn't exist");
                return ptr;
            }
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            ptr = insertAtEnd(ptr, data);
            return ptr;
        }
        else
        {
            // struct Node *temp2 = temp;
            n->next = temp->next;
            temp->next->prev = n;
            n->prev = temp;
            temp->next = n;
        }
    }
    return ptr;
}

int main()
{
    struct Node *head;
    head = NULL;
    head = insertAtBegnning(head, 10);
    head = insertAtBegnning(head, 13);
    head = insertAtBegnning(head, 19);
    head = insertAtEnd(head, 31);
    head = insertAtIndex(head, 94, 2);
    head = insertAtIndex(head, 56, 0);
    head = insertAtIndex(head, 39, 6);
    traversal(head);
    return 0;
}