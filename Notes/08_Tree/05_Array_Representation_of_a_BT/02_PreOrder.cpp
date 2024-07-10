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

    void preOrder(int root)
    {
        if (root >= this->size || root < 0 || this->arr[root] == '-')
        {
            return;
        }
        int left = (root * 2) + 1;
        int right = (root * 2) + 2;
        cout << this->arr[root] << "";
        preOrder(left);
        preOrder(right);
    }

    void postOrder(int root)
    {

        if (root >= this->size || root < 0 || this->arr[root] == '-')
        {
            return;
        }
        int left = (root * 2) + 1;
        int right = (root * 2) + 2;
        postOrder(left);
        postOrder(right);
        cout << this->arr[root] << "";
    }

    void inOrder(int root)
    {
        if (root >= this->size || root < 0 || this->arr[root] == '-')
        {
            return;
        }
        int left = (root * 2) + 1;
        int right = (root * 2) + 2;
        inOrder(left);
        cout << this->arr[root] << "";
        inOrder(right);
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
    b.preOrder(0);
    cout << endl;
    b.postOrder(0);
    cout << endl;
    b.inOrder(0);
    cout << endl;
    return 0;
}