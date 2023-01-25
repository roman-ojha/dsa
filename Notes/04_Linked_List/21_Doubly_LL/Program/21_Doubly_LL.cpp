/*

struct Node
{
    int data;
    Struct Node *next;
    Struct Node *prev;
};

*/
#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node() : prev(nullptr), data(0), next(nullptr) {}
    Node(int data) : prev(nullptr), data(data), next(nullptr) {}
    Node(Node *prev, int data, Node *next) : prev(prev), data(data), next(next) {}
};

// // Doubly Linked list
// class DLL
// {
// public:
// };

int main()
{

    return 0;
}
