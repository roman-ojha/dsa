#include <stdio.h>
#include <stdlib.h>

int random(int a)
{
    int i;
    int num = (rand() % (a + 1));
    return num;
}
int function(int n)
{
    int i;

    if (n <= 0)
    {
        return 0;
    }
    else
    {
        i = random(n - 1);
        printf("this\n");
        // in this section we are generating a random value and implimneting that random value to the function
        // it means that because of that random value the no. of printing this need to be different but,
        // this will not happen this will print in same number every time
        return function(i) + function(n - 1 - i);
    }
}

int main()
{
    function(6);
    return 0;
}