#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        return 1;
    }
    free(ptr);
    return 0;
}

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
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

struct Node *deletionAtBeginning(struct Node *head)
{

    if (isEmpty(head))
    {
        cout << "\nLinked List is empty" << endl;
    }
    else if (head->next == NULL && head->prev == NULL)
    {
        cout << "Deleting " << head->data << endl;
        free(head);
        return NULL;
    }
    else
    {
        struct Node *ptr = head;
        head->next->prev = NULL;
        head = ptr->next;
        free(ptr);
    }
    return head;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    if (isEmpty(head))
    {
        cout << "\nLinked List is Empty" << endl;
    }
    else if (ptr->next == NULL && ptr->prev == NULL)
    {
        free(ptr);
        return NULL;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
    return head;
}

struct Node *deletionAtParticularPosition(struct Node *head, int position)
{
    struct Node *ptr = head;
    if (isEmpty(ptr))
    {
        cout << "\nLinked List is Empty" << endl;
    }
    else if (position == 1)
    {
        if (head->next == NULL)
        {
            head = deletionAtBeginning(ptr);
            return NULL;
        }
        else
        {
            head = deletionAtBeginning(ptr);
            return head;
        }
    }
    else
    {
        int count = 1;
        while (ptr->next != NULL && position != count)
        {
            ptr = ptr->next;
            count++;
        }
        if (ptr->next == NULL && position == count)
        {
            // deletion at the end
            ptr->prev->next = NULL;
            free(ptr);
        }
        else if (ptr->next == NULL && position != count)
        {
            cout << "\ngiven position doesn't exist in the linked list" << endl;
        }
        else
        {
            struct Node *temp = ptr;
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
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
    head = insertationAtParticularPosition(head, 23, 5);
    cout << "Insertion" << endl;
    traversal(head);
    head = deletionAtBeginning(head);
    head = deletionAtEnd(head);
    head = deletionAtParticularPosition(head, 1);
    cout << "\nDeletion" << endl;
    traversal(head);
    return 0;
}