#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
    vector<int> heap;
    // Max heap
    // int size = 20;
    // int *arr2 = new int[size]{70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5};

public:
    MaxHeap(vector<int> heap)
    {
        this->heap = heap;
    }

    void insert(int val)
    {
        this->heap.push_back(val);
        int i = this->heap.size() - 1;
        while (i > 0)
        {
            // we don't need to calculate for index 0 because it will not have any parent
            int parent = i / 2;
            if (this->heap[i] > this->heap[parent])
            {
                // swap child with parent
                int temp = this->heap[i];
                this->heap[i] = this->heap[parent];
                this->heap[parent] = temp;
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < (int)this->heap.size(); i++)
        {
            cout << this->heap[i] << " ";
        }
        cout << endl;
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