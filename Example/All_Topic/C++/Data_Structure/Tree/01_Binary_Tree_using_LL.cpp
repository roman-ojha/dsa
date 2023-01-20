#include <iostream>
using namespace std;

template <class Data>
class Node
{
public:
    Node<Data> *left;
    Data data;
    Node<Data> *right;
    Node(Node<Data> *left, Data data, Node<Data> *right) : left(left), data(data), right(right) {}
    Node(Data data) : data(data), left(nullptr), right(nullptr) {}
};

template <class Data>
class BT
{
public:
    Node<Data> *root;
};

int main()
{
    return 0;
}