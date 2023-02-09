#include <iostream>
#include <vector>
using namespace std;

int no_of_subset = 0;
void sum_of_subset(vector<int> *w, int sum, int index, int target_sum)
{
    if (sum == target_sum)
    {
        no_of_subset++;
        if (index < (int)w->size())
        {
            sum_of_subset(w, sum - w->at(index - 1), index, target_sum);
        }
    }
    else
    {
        for (int i = index; i < (int)w->size(); i++)
        {
            sum_of_subset(w, sum + w->at(i), i + 1, target_sum);
        }
    }
}

int main()
{
    vector<int> w{2, 7, 8, 15};
    int target_sum = 17;
    no_of_subset = 0;
    sum_of_subset(&w, 0, 0, target_sum);
    cout << "Total no. of sum of subset are: " << no_of_subset << endl;
    return 0;
}