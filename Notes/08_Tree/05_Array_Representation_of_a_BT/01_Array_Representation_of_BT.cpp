/*
    *) Array representation (Sequential Representation)
        -> https://www.geeksforgeeks.org/binary-tree-array-implementation/
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

class BinaryTree
{
private:
    int size;
    char arr[20];

public:
    BinaryTree(char root)
    {
        std::memset(this->arr, '-', sizeof(this->arr));
        this->arr[0] = root;
        this->size = 20;
    }

    void set_left_child(int parentNode, char element)
    {
        int index = (parentNode * 2) + 1;
        if (index <= this->size)
            this->arr[index] = element;
        else
            cout << "Array index out of bound" << endl;
    }

    void set_right_child(int parentNode, char element)
    {
        int index = (parentNode * 2) + 2;
        if (index <= this->size)
            this->arr[index] = element;
        else
            cout << "Array index out of bound" << endl;
    }

    void print()
    {
        cout << endl;
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BinaryTree b('A');
    b.print();
    b.set_right_child(0, 'B');
    b.print();
    b.set_right_child(2, 'C');
    b.print();
    b.set_left_child(2, 'D');
    b.print();
    b.set_left_child(5, 'E');
    b.print();
    b.set_left_child(6, 'F');
    b.print();
    b.set_right_child(5, 'G');
    b.print();
    return 0;
}