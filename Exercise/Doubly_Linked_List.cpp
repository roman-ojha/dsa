#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *tail = NULL;
    cout << "1.insert at beginning\n2.insert at end\n3.insert at purticuler position\n4.delete at beginning\n5.delete at end\n6.delete at purticuler node\n7.display\n8.Exit" << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Insertion at beginning" << endl;
        cout << "Enter the data: " << endl;
        int value;
        cin >> value;
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = value;
        if (head == NULL)
        {
            head = ptr;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
        }
        else
        {
            ptr->next = head;
            ptr->prev = NULL;
            head->prev = ptr;
            head = ptr;
        }
        break;
    case 7:
        struct node *ptr = head;
        if (head == NULL)
        {
            cout << "Empty linked list";
        }
        else
        {
            int i = 0;
            while (ptr != NULL)
            {
                cout << ptr->data << "->";
                ptr = ptr->next;
            }
        }
        break;
    default:
        cout << "Default" << endl;
        break;
    }
    return 0;
}
