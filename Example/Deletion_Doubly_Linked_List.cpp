#include <stdio.h>
#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    struct node *head, *tail, *ptr;
    head = NULL;
    tail = NULL;
    int choice = 0;
    int data;
    while (choice != 8)
    {
        printf("Enter you choice\n1.Insert at begginning\n2.Insert at end\n3.Insert at particular node\n4.Delete at begginnin\n5.Delete at end\n6.Delete at particular node\n7.Display\n8.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ptr = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &data);
            ptr->data = data;
            if (head == NULL && tail == NULL)
            {
                ptr->next = NULL;
                ptr->prev = NULL;
                head = ptr;
                tail = head;
            }
            else if (head == tail)
            {
                head->prev = ptr;
                head = ptr;
                head->next = tail;
                head->prev = NULL;
                tail->prev = head;
                tail->next = NULL;
            }
            else
            {
                ptr->next = head;
                ptr->prev = NULL;
                head->prev = ptr;
                head = ptr;
            }
            break;
        case 2:
            ptr = (struct node *)malloc(sizeof(struct node));
            printf("Enter data:");
            scanf("%d", &data);
            ptr->data = data;
            if (head == NULL && tail == NULL)
            {
                ptr->next = NULL;
                ptr->prev = NULL;
                head = ptr;
                tail = head;
            }
            else if (head == tail)
            {
                ptr->next = NULL;
                ptr->prev = tail;
                tail = ptr;
                head->next = tail;
                tail->prev = head;
            }
            else
            {
                ptr->next = NULL;
                ptr->prev = tail;
                tail->next = ptr;
                tail = ptr;
            }
            break;
        case 3:
            int position = 0;
            ptr = (struct node *)malloc(sizeof(struct node));
            printf("Enter data:");
            scanf("%d", &data);
            printf("Enter the position:");
            scanf("%d", &position);
            ptr->data = data;
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            if (head == NULL)
            {
                printf("Empty linked list");
            }
            else
            {
                ptr = head;
                while (ptr != NULL)
                {
                    printf("%d->", ptr->data);
                    ptr = ptr->next;
                }
                printf("\n");
            }
            break;
        case 8:
            goto label;
            break;
        default:
            printf("Invalid number try Again!!!!");
            break;
        }
    }
label:
    printf("end of programm");
    return 0;
}