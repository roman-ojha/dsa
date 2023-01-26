#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
    vector<int> heap;

public:
    MaxHeap(vector<int> heap)
    {
        this->heap = heap;
    }

    void display()
    {
        for (int i = 0; i < (int)this->heap.size(); i++)
        {
            cout << this->heap[i] << " ";
        }
        cout << endl;
    }

    void deletion()
    {
    }
};

int main()
{
    MaxHeap mh({70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5});
    mh.display();
    mh.insert(51);
    mh.display();
    return 0;
}