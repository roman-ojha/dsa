/*
    *) Job Sequencing:
        -> EX:
            J: j1 j2 j3 j4 j5 j6
            D: 5  3  3  2  4  2
            P: 15 10 12 20 8  5
        -> Sort with profit wise
            J: j4 j1 j3 j2 j5 j6
            D: 2  5  3  3  4  2
            P: 20 15 12 10 8  5

        -> With Deadline Sequence:
            0  1  2  3  4  5
            |  |  |  |  |  |

        => For J4:
            -> because j4 have maximum profit we will try to place into the sequence
            -> because j4 have deadline 2 it means that we can complete this job upto deadline 2
            -> so we have to place the j4 as far as possible upto the given deadline
            -> for now we can place it into sequence 2
            -> but if sequence 2 had already filled then we must have to place before 2 which is 1 sequence
            -> but now we can place into 2
                0   1   2    3   4   5
                |   | j4 |   |   |   |

            => Profit : 20

        => For j1:
            -> j1 have second highest profit so we will try to place it into sequence
            -> j1 have deadline 5
            -> we can place j1 in any empty job sequence but we will place j1 as far as possible
            -> place j1 upto 5 sequence
                0   1    2   3   4    5
                |   | j4 |   |   | j1 |
            => Profit: 20 + 15 = 35

        => For j3:
            -> j3 have deadline 3
            -> place j3 into 3 sequence
                0   1    2    3   4    5
                |   | j4 | j3 |   | j1 |
            => Profit: 35 + 12 = 47

        => For j2:
            -> j2 have deadline 3
            -> place j2 as far as upto 3rd sequence
            -> but 2nd & 3rd sequence is already fill
            -> so we can only place j2 in 1st sequence
                0    1    2    3   4    5
                | j2 | j4 | j3 |   | j1 |
            => Profit: 47 + 10 = 57

        => For j5:
            -> j5 have deadline 4
            -> place j4 as far as upto 4th sequence
            -> because there is only one place left upto 4th sequence which is 4th sequence
            -> placing j5 into 4th sequence
                0    1    2    3    4    5
                | j2 | j4 | j3 | j5 | j1 |
            => Profit: 57 + 8 = 65

        => Therefor:
            -> Job sequence with maximum profit is:
                -> J2, J4, J3, J5, J1
            => with maximum profit of: 65
*/

#include <iostream>
#include <algorithm>
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

void print_jobs(Job jobs[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "Job: " << jobs[i].id << endl;
        cout << "Profit: " << jobs[i].profit << " Deadline: " << jobs[i].deadline << endl;
    }
}

// Time complexity: O(n^2)
// Space complexity: O(n)
void job_sequencing(Job jobs[], int n, int max_deadline)
{
    // for we will sort the Job according to profit
    sort(jobs, jobs + n, greater<Job>());
    print_jobs(jobs, n);

    // to store the job sequence result
    int *sequence_result = new int[max_deadline];

    // to determine the free & filled slot
    bool *slot = new bool[max_deadline];

    // set all slot of them as false
    // O(n)
    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }

    // we will iterate through all the sorted job from higher profit to lower
    // O(n^2)
    for (int i = 0; i < n; i++)
    {
        // start to check from the max deadline that specific job(job[i]) upto the 0
        // where we find the slot we will insert that job into it
        // O(n)
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            // if for that particular sequence slot is empty in that case we will insert
            if (slot[j] == false)
            {
                sequence_result[j] = jobs[i].id; // Add this job to result
                slot[j] = true;                  // Make this slot occupied
                break;
            }
        }
    }

    // Print job sequence
    // O(n)
    for (int i = 0; i < max_deadline; i++)
    {
        cout << "J" << sequence_result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    Job arr[] = {
        // {id, profit, deadline}
        {1, 60, 2},
        {2, 100, 1},
        {3, 20, 3},
        {4, 40, 2},
        {5, 20, 1}};

    job_sequencing(arr, n, 3);

    return 0;
}