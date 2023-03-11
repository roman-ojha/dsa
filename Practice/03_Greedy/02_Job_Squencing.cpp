#include <iostream>
#include <algorithm>

class Job
{
public:
    int id;
    int profit;
    int deadline;
    Job(int i, int p, int d) : deadline(d), id(i), profit(p) {}
    bool operator>(const Job &j) const
    {
        return this->profit > j.profit;
    }
    bool operator<(const Job &j) const
    {
        return this->profit < j.profit;
    }
};

void job_sequencing(Job jobs[], int n, int max_deadline)
{
    std::cout << std::endl;
    std::sort(jobs, jobs + n, std::greater<Job>());
    int *sequence = new int[max_deadline];
    bool *slot = new bool[max_deadline];
    for (int i = 0; i < max_deadline; i++)
    {
        slot[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                sequence[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < max_deadline; i++)
    {
        std::cout << "J" << sequence[i] << " ";
    }
}

int main()
{
    int n = 5;
    Job jobs[] = {
        {1, 60, 2},
        {2, 100, 1},
        {3, 20, 3},
        {4, 40, 2},
        {5, 20, 1}};
    job_sequencing(jobs, n, 3);
    return 0;
}