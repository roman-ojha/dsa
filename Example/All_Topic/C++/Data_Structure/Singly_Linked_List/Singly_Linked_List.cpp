#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node() {}
    Node(T data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

template <class T>
class LinkedList
{
private:
    int n;
    Node<T> *head;

public:
    LinkedList()
    {
        this->n = 0;
    }
    LinkedList(T data)
    {
        this->head = new Node<T>(data, NULL);
    }
    void insert(T data, int position)
    {
    }

    // Iterator
    int start()
    {
        return 1;
    }

    int end()
    {
        return this->n;
    }

    int size()
    {
        return this->n;
    }
};

int main()
{
    LinkedList<int> l;
    // l.insert(1, l.start());
    LinkedList<int> l2(10);
    return 0;
}