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

// Doubly Linked list
class DLL
{
    Node *head;
    int length;

public:
    DLL()
    {
        this->head = nullptr;
        this->length = 0;
    }

    DLL(int data)
    {
        this->head = new Node(data);
        this->head->next = nullptr;
        this->head->prev = nullptr;
        this->length = 1;
    }

    void print()
    {
        Node *ptr = this->head;
        cout << "NULL <-> ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << " NULL" << endl;
    }

    int size()
    {
        return this->length;
    }

    void insert(int data, int position)
    {
        // position 1 = first
        // position last = this->length

        // If position out of bound
        if (position > this->length)
        {
            cout << "Position is out of bound" << endl;
            return;
        }

        // insert at beginning
        Node *node = new Node(data);
        if (position == 1)
        {
            node->next = this->head;
            node->prev = nullptr;
            this->head->prev = node;
            this->head = node;
            this->length++;
        }
        else if (position == this->length)
        {
            // Insert at the end
            Node *ptr = this->head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            node->next = nullptr;
            node->prev = ptr;
            ptr->next = node;
            this->length++;
        }
        else
        {
            // Insert in between
            int i = 0;
            Node *ptr = this->head;
            while (i + 1 < position)
            {
                ptr = ptr->next;
                i++;
            }
            node->next = ptr->next;
            node->prev = ptr;
            ptr->next->prev = node;
            ptr->next = node;
        }
    }
};

int main()
{
    DLL dll(3);
    dll.insert(21, 1);
    dll.insert(7, dll.size());
    dll.insert(8, 2);
    dll.print();
    return 0;
}
