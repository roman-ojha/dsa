/*
Implementation of Queue:

struct Queue
{
    int size;
    int f; // front
    int r; // rear
    int *arr;
}

int main()
{
    struct Queue q;
    q.size=10;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    return 0;
}

*/