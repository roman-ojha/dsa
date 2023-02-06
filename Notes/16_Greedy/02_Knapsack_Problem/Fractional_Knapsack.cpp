#include <iostream>
#include <algorithm>
using namespace std;

class Item
{
public:
    int weight;
    int value;
    float profit;

    Item(int weight, int value)
    {
        this->weight = weight;
        this->value = value;
    }

    bool operator<(const Item &i) const
    {
        // compare according to profit
        return profit < i.profit;
    }

    bool operator>(const Item &i) const
    {
        return profit > i.profit;
    }
};

void print_items(Item items[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "Item: " << i << endl;
        cout << "Weight: " << items[i].weight << " Value: " << items[i].value << " Profit: " << items[i].profit << endl;
    }
}

// Time complexity = O(NLogN)
float fractional_knapsack(Item items[], int W, int n)
{
    // O(n)
    for (int i = 0; i < n; i++)
    {
        // get the profit
        // value / weight
        items[i].profit = (float)(items[i].value / items[i].weight);
    }

    // sort according to profit
    // O(NLogN)
    sort(items, items + n, std::greater<Item>());

    float totalProfit = 0;
    // O(n)
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= W)
        {
            // can insert into knapsack
            W = W - items[i].weight;
            totalProfit += items[i].value;
        }
        else
        {
            // still have W(capacity) but not upto items[i].weight
            // insert fraction of the weight into knapsack
            totalProfit += ((float)W / (float)items[i].weight) * items[i].value;
            // after adding inserting upto capacity it will be zero
            W = 0;
            // and it will be final time so we can break from the loop
            break;
        }
    }
    return totalProfit;
}

int main()
{
    Item items[] = {{5, 30}, {10, 20}, {20, 100}, {30, 90}, {40, 160}};
    // Capacity
    int W = 60;
    int n = 5;
    cout << "Optimal profit earned: " << fractional_knapsack(items, W, n) << endl;
    return 0;
}