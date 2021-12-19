// Can't Push if Full
// can't Pop of Empty

// Operation 1 > Push
/*
    struct stack *s;
    s->size=8;
    s->top=-1;
    s->array=(int*) malloc(s->size*sizeof(int));
    Push(int value)
    {
        // we are checking is stack is full to push or insert the value in the stack
        if(isfull(s))
        {
            printf("Stack Overflow");
        }
        else
        {
            sp->top++;
            sp->array[sp->top]=value;

        }
    }
*/

// Operation 2 > Pop
/*
    struct stack *s;
    s->size=8;
    s->top=-1;
    s->array=(int*)malloc(s->size*sizeof(int));
    int Pop()
    {
        // we are checking is stack is empty to pop or extract the value from the stack
        if(isemply()
        {
            printf("Stack underflow");
        }
        else
        {
            int value;
            value=array[s->top];
            s->top--;
            return value;
        }
    }
*/