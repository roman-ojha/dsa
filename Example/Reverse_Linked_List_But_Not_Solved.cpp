#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

void traversal(struct node *ptr)
{
    struct node *temp = ptr;
    if (isEmpty(ptr))
    {
        cout << "Linkedlist is empty";
    }
    else
    {
        int i = 0;
        while (temp != NULL)
        {
            cout << "Element " << i << ": " << temp->data << endl;
            temp = temp->next;
            i++;
        }
    }
}

struct node *reverseLinkedList(struct node *ptr)
{

    struct node *temp, *pointFirst, *pointThird, *pointSecond;
    temp = ptr;
    pointFirst = ptr;
    pointThird = ptr;
    int count = 0;
    if (isEmpty(ptr))
    {
        cout << "Linked list is Empty" << endl;
    }
    else
    {
        pointSecond = pointFirst->next;
        pointThird = pointSecond->next;
        if (pointFirst->next == NULL)
        {
            pointFirst->next == NULL;
            return pointFirst;
        }
        else if (pointSecond->next == NULL)
        {
            pointFirst->next = NULL;
            pointSecond->next = pointFirst;
            return pointSecond;
        }
        else
        {
            while (pointThird != NULL)
            {
                if (count == 0)
                {
                    pointFirst->next = NULL;
                    pointSecond->next = pointFirst;
                    pointFirst = pointSecond;
                    pointSecond = pointThird;
                    pointThird = pointThird->next;
                    count++;
                }
                else
                {
                    pointSecond->next = pointFirst;
                    pointFirst = pointSecond;
                    pointSecond = pointThird;
                    pointThird = pointThird->next;
                }
            }
        }
    }
    return pointThird;
}

int main()
{
    struct node *first, *second, *third, *fourth;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    first->data = 10;
    first->next = second;
    second->data = 11;
    second->next = third;
    third->data = 12;
    third->next = fourth;
    fourth->data = 13;
    fourth->next = NULL;
    traversal(first);
    first = reverseLinkedList(first);
    traversal(first);
    free(first);
    free(second);
    free(third);
    free(fourth);
    return 0;
}