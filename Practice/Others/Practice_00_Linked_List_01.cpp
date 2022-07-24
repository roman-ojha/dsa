#include <iostream>
#include <stdlib.h>
using namespace std;

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

void Traversal(struct Node *head)
{
    cout << "The given Elemtnt are:" << endl;
    struct Node *ptr = head;
    int i = 0;
    while (ptr != NULL)
    {
        cout << "Element " << i + 1 << ": " << ptr->data << endl;
        ptr = ptr->next;
        i++;
    }
}

// Case 1: insertion in the beginining

struct Node *beginingInsert(struct Node *head, int number)
{
    struct Node *SingleNode = (struct Node *)malloc(sizeof(struct Node));
    SingleNode->data = number;
    SingleNode->next = head;
    return SingleNode;
}

// Case 2: insertion at the end
struct Node *endInsert(struct Node *head, int number)
{
    struct Node *ptr = head;
    struct Node *singleNode = (struct Node *)malloc(sizeof(struct Node));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    singleNode->data = number;
    ptr->next = singleNode;
    singleNode->next = NULL;
    return head;
}

// Case 3: insertion at the given index
struct Node *inIndexInsert(struct Node *head, int number, int index)
{
    struct Node *singleNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    for (int i = 0; i < index - 2; i++)
    {
        ptr = ptr->next;
    }
    singleNode->data = number;
    singleNode->next = ptr->next;
    ptr->next = singleNode;
    return head;
}

// Deletion
// Case 1: at the bigining
struct Node *biginingDelete(struct Node *head)
{
    struct Node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}

// Case 2: at the end
struct Node *endDelete(struct Node *head)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

// Case 3: delete at the index
struct Node *atIndexDelete(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    cout << "Enter the number of Element you want to Enter:";
    int size;
    cin >> size;
    struct Node *head;
    head = setLinkedList(size);
    Traversal(head);
    cout << "Insertion:" << endl
         << "Pick a index number where you want to insert the number:";
    int insertIndex;
    cin >> insertIndex;
    cout << "Enter the Number That you want to insert in Linked List:";
    int insertNumber;
    cin >> insertNumber;
    head = inIndexInsert(head, insertNumber, insertIndex);
    size++;
    Traversal(head);
    cout << "number after Inserting at the bigining:" << endl;
    head = beginingInsert(head, insertNumber);
    size++;
    Traversal(head);
    cout << "number after inserting at the end:" << endl;
    head = endInsert(head, insertNumber);
    size++;
    Traversal(head);

    // deleting
    cout << "number after delete of the bigining Element:" << endl;
    head = biginingDelete(head);
    Traversal(head);
    size--;
    cout << "number after delete of the end Element:" << endl;
    endDelete(head);
    Traversal(head);
    size--;
    cout << "Deletion:" << endl
         << "Pick a index number where you want to Delete the number:";
    int deleteIndex;
    cin >> deleteIndex;
    head = atIndexDelete(head, deleteIndex);
    size--;
    Traversal(head);
    return 0;
}