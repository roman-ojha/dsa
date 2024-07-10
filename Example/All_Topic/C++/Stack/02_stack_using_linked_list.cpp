#include <iostream>
using namespace std;

class Node
{
public:
    int element;
    Node *next;
    Node *previous;

    Node(int element)
    {
        this->element = element;
        this->next = NULL;
        this->previous = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

    bool isEmpty()
    {
        if (this->head == NULL)
            return true;
        return false;
    }

public:
    LinkedList()
    {
        head = NULL;
    }

    Node *insertionAtEnd(int element)
    {
        Node *node = new Node(element);

        if (this->isEmpty())
        {
            this->head = node;
            return node;
        }
        Node *ptr = this->head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        node->previous = ptr;
        ptr->next = node;
        return node;
    }

    void travel()
    {
        Node *ptr = this->head;
        if (!this->isEmpty())
        {

            while (ptr->next != NULL)
            {
                cout << ptr->element << " -> ";
                ptr = ptr->next;
            }
            cout << ptr->element << endl;
        }
    }

    Node *getHead()
    {
        return this->head;
    }
};

class Stack
{
private:
    LinkedList *l;
    Node *top;

    bool isEmpty()
    {
        if (this->top == NULL)
            return true;
        return false;
    }

public:
    Stack()
    {
        this->l = new LinkedList();
        this->top = NULL;
    }

    void push(int element)
    {
        this->top = this->l->insertionAtEnd(element);
    }

    int pop()
    {
        Node *node = this->top;
        this->top = this->top->previous;
        int element = node->element;
        delete node;
        return element;
    }

    void travel()
    {
        // Node *ptr = this->l->getHead();
        Node *ptr = this->top;
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        while (ptr != NULL)
        {
            cout << "| " << ptr->element << " |" << endl;
            ptr = ptr->previous;
        }
    }
};

int main()
{
    Stack *s = new Stack();
    s->push(10);
    s->push(20);
    s->push(12);
    s->travel();
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    s->travel();
    return 0;
}