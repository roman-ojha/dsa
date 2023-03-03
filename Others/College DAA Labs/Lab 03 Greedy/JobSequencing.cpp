#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

class Job
{
public:
    int id;
    int profit;
    int deadline;
    Job(int id, int profit, int deadline) : id(id), profit(profit), deadline(deadline) {}
    bool operator>(const Job &j) const
    {
        return profit > j.profit;
    }
};


void job_sequencing(Job jobs[], int n, int max_deadline)
{
    sort(jobs, jobs + n, greater<Job>());

    int *sequence_result = new int[max_deadline];

    bool *slot = new bool[max_deadline];

    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                sequence_result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < max_deadline; i++)
    {
        cout << "J" << sequence_result[i] << " ";
    }
    cout << endl;
}


int main(){

    // Job sequencing
    int n = 5;
    Job jobs[] = {
        // {id, profit, deadline}
        {1, 60, 2},
        {2, 100, 1},
        {3, 20, 3},
        {4, 40, 2},
        {5, 20, 1}
    };
    job_sequencing(jobs, n, 3);
    cout<<"Name: Roman Ojha"<<endl;
    cout<<"Roll: 25"<<endl;
    cout<<"Time: "<<time<<endl;
    return 0;
}
