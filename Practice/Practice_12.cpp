// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *createList(int num)
// {
//     struct Node *list[num];
//     list[0] = (struct Node *)malloc(sizeof(struct Node));
//     cout << "Enter the 0th Element of Linked List: ";
//     cin >> list[0]->data;
//     for (int i = 0; i < num - 1; i++)
//     {
//         list[i + 1] = (struct Node *)malloc(sizeof(struct Node));
//         cout << "Enter the " << i + 1 << "th Element of Linked List: ";
//         cin >> list[i + 1]->data;
//         list[i]->next = list[i + 1];
//     }
//     list[num]->next = NULL;
//     return list[0];
// }

// struct Node *setLinkedList(int size)
// {
//     cout << "Enter " << size << " Element:" << endl;
//     struct Node *Nodes[size];
//     Nodes[0] = (struct Node *)malloc(sizeof(struct Node));
//     for (int i = 0; i < size; i++)
//     {
//         if (i == size - 1)
//         {
//             cout << "Element " << i + 1 << ":";
//             cin >> Nodes[i]->data;
//             Nodes[i]->next = NULL;
//         }
//         else
//         {
//             cout << "Element " << i + 1 << ": ";
//             cin >> Nodes[i]->data;
//             Nodes[i + 1] = (struct Node *)malloc(sizeof(struct Node));
//             Nodes[i]->next = Nodes[i + 1];
//         }
//     }
//     return Nodes[0];
// }

// void traversal(struct Node *ptr)
// {
//     cout << "Hello" << endl;
//     while (ptr != NULL)
//     {
//         cout << ptr->data << " -> ";
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     struct Node *head;
//     // head = createList(10);
//     head = setLinkedList(15);
//     traversal(head);
//     return 0;
// }

// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// void traversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         cout << ptr->data << " -> ";
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     struct Node *list[5];
//     for (int i = 0; i < 5; i++)
//     {
//         list[i] = (struct Node *)malloc(sizeof(struct Node *));
//         cout << "Element " << i + 1 << ": ";
//         cin >> list[i]->data;
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         if (i == 4)
//         {
//             list[i]->next = NULL;
//         }
//         else
//         {
//             list[i]->next = list[i + 1];
//         }
//     }
//     traversal(list[0]);
//     return 0;
// }

// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *next;
// };
// void traversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         cout << ptr->data << " -> ";
//         ptr = ptr->next;
//     }
// }

// struct Node *insertAtBegenning(struct Node *ptr, int value)
// {
//     struct Node *node;
//     node = (struct Node *)malloc(sizeof(struct Node));
//     node->data = value;
//     node->next = ptr;
//     return node;
// }

// int main()
// {
//     struct Node *first;
//     struct Node *second;
//     struct Node *third;
//     struct Node *fourth;
//     first = (struct Node *)malloc(sizeof(struct Node));
//     second = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));
//     fourth = (struct Node *)malloc(sizeof(struct Node));
//     first->data = 10;
//     first->next = second;
//     second->data = 14;
//     second->next = third;
//     third->data = 20;
//     third->next = fourth;
//     fourth->data = 34;
//     fourth->next = NULL;
//     traversal(first);
//     struct Node *head;
//     head = insertAtBegenning(first, 17);
//     printf("\nInsertation At the beginning");
//     traversal(head);
//     return 0;
// }

#include <iostream>
#include <stdio.h>
using namespace std;

struct stack
{
    int top;
    int size;
    int *arr;
};

void push(struct stack *s, int value)
{
    if (s->top == s->size - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
    return;
}

int pop(struct stack *s)
{
    int value;
    if (s->top == -1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        value = s->arr[s->top];
        s->top--;
        return value;
    }
}

void traversal(struct stack *s)
{
    for (int i = 0; i < s->top + 1; i++)
    {
        cout << "Element " << i + 1 << ": " << s->arr[i] << endl;
    }
}

int main()
{
    struct stack *s;
    s->top = -1;
    s->size = 10;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // push(s, 10);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // push(s, 13);
    // traversal(s);
    cout << "poping: " << pop(s) << endl;
    return 0;
}