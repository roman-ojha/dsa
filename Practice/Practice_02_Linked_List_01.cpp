#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversel(struct Node *ptr)
{
    printf("Entered number are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head, *second, *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 12;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 14;
    third->next = NULL;
    traversel(head);
    return 0;
}