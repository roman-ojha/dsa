/*
    => Advantage:
        *) deletion is easy
        *) O(1) insertation
    => Disadvangage:
        *) O(n) searching worst case
        *) require extra space without filling the existing hash table
*/

// CPP program to implement hashing with chaining

#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int BUCKET;
    list<int> *table;

public:
    Hash(int);
    void insertItem(int);
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void deleteItem(int);
    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[this->BUCKET];
    // making hash table of 'this->BUCKET'size
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            // when we found key
            break;
        }
    }
    if (i != table[index].end())
    {
        table[index].erase(i);
    }
}

// function to display hash table
void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : table[i])
        {
            cout << " --> " << x;
        }
        cout << endl;
    }
}

int main()
{
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);
    Hash h(7); // 7 is count of buckets in
    for (int i = 0; i < n; i++)
    {
        h.insertItem(a[i]);
    }
    h.deleteItem(12);
    h.displayHash();
}