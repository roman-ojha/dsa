/*
    *) Array representation (Sequential Representation)
        -> Now, we are going to talk about the sequential representation of the trees.  In order to represent a tree using an array, the numbering of nodes can start either from 0–(n-1) or 1– n, consider the below illustration as follows:
        Illustration:
                A(0)
               /   \
              B(1)  C(2)
             /   \      \
            D(3)  E(4)   F(6)
            OR,
                A(1)
               /   \
              B(2)  C(3)
            /   \      \
            D(4)  E(5)   F(7)

            Case 1: (0 — n-1)

                if (say)father=p;
                then left_son=(2*p)+1;
                and right_son=(2*p)+2;
                Case 2: 1—n

            Case 2: 1 — n
                if (say)father=p;
                then left_son=(2*p);
                and right_son=(2*p)+1;

*/

#include <iostream>
using namespace std;

class BT
{
    int size;
};

int main()
{

    return 0;
}