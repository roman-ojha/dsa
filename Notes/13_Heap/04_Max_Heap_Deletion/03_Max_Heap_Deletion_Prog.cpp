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

    void heapify(int i)
    {
        // i is the index of max heap tree which we are evaluating
        int lchild = (i * 2) + 1;       // left child
        int rchild = ((i * 2) + 1) + 1; // right child

        int n = this->heap.size();

        // max value child index
        int mchild;

        if ((lchild > n - 1) && (rchild > n - 1))
        {
            // we reached to the leaf node
            return;
        }
        else if ((rchild > n - 1) && (lchild <= n - 1))
        {
            // rchild doesn't exist
            // only rchild exist
            mchild = lchild;
        }
        else
        {
            // if both exist
            mchild = this->heap[lchild] > this->heap[rchild] ? lchild : rchild;
        }

        if (this->heap[i] > this->heap[mchild])
        {
            // it will already a max heap not need to swap
            return;
        }
        else
        {
            // if (this->heap[mchild] > this->heap[i])
            // swap
            int temp = this->heap[mchild];
            this->heap[mchild] = this->heap[i];
            this->heap[i] = temp;

            // call heapify for 'mchild'
            heapify(mchild);
        }
    }

    void deletion()
    {
        int del_val = this->heap[0];
        cout << "Deleting " << del_val << endl;

        this->heap[0] = this->heap.back();
        // remove last element
        this->heap.pop_back();

        // we have to start heapfiying from the 0th index
        this->heapify(0);
    }
};

int main()
{
    MaxHeap mh({70, 60, 40, 45, 50, 39, 16, 10, 9, 35, 5});
    mh.display();
    mh.deletion();
    mh.display();
    mh.deletion();
    mh.display();
    return 0;
}