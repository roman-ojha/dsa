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
        this->head = NULL;
    }
    LinkedList(T data)
    {
        this->head = new Node<T>(data, NULL);
        this->n = 1;
    }
    void insert(T data, int position)
    {
        if (this->head == NULL)
        {
            if (position == this->start())
            {
                this->head = new Node<T>(data, NULL);
                this->n = 1;
            }
            else
            {
                cout << "Position is out of bound" << endl;
                // exit()
            }
        }
        else
        {
            if (position == this->start())
            {
                // Insert In starting position
                Node<T> *node = new Node<T>(data, this->head);
                this->head = node;
                this->n = this->n + 1;
            }
            else if (position == this->end())
            {
                // Insert At the end of position
                Node<T> *node = new Node<T>(data, NULL);
                Node<T> *ptr = this->head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = node;
                this->n = this->n + 1;
            }
            else
            {
                // Insert in between
                Node<T> *ptr = this->head;
                int i = 1;
                while (i < position - 1)
                {
                    ptr = ptr->next;
                    i++;
                }
                cout << ptr->data << endl;
                Node<T> *node = new Node<T>(data, ptr->next);
                ptr->next = node;
                this->n = this->n + 1;
            }
        }
    }

    void print()
    {
        Node<T> *ptr = this->head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }

    // Iterator
    int start()
    {
        return 1;
    }

    int end()
    {
        return this->n + 1;
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
    l2.insert(2, l2.start());
    // l2.insert(12, l2.start());
    l2.insert(33, l2.end());

    // 2nd position
    l2.insert(51, l2.start() + 1);

    // 3rd position
    l2.insert(71, l2.start());

    l2.print();
    return 0;
}