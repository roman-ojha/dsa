#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    // to store the total size of an array
    int used_size;
    // to store the used size of an array
    int *ptr;
    // 'ptr' will point the first element of the array
    // here you can't define the function inside the structure so because of that we have to define the function outside for the ADT;
};

// now we can make a array using malloc()
// you can do this in c++ by using constructor
void createArray(struct myArray *a, int tSize, int uSize)
{
    // when we are making 'myArray' as pointer then we can access the value and control through address so we don't have to return the value

    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

// this will set the value
void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

// this will show the vlaue
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running show now\n");
    show(&marks);

    return 0;
}