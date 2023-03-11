#include <iostream>
#include <algorithm>

class Item
{
public:
    int weight;
    int value;
    float profit;
    Item(int w, int v) : weight(w), value(v) {}
    bool operator<(const Item &i) const
    {
        return this->profit < i.profit;
    }
    bool operator>(const Item &i) const
    {
        return this->profit > i.profit;
    }
};

void fractional_knapsack(Item items[], int n, int W)
{
    float max_profit = 0;
    for (int i = 0; i < n; i++)
    {
        items[i].profit = ((float)items[i].value / (float)items[i].weight);
    }
    std::sort(items, items + n, std::greater<Item>());
    for (int i = 0; i < n; i++)
    {
        std::cout << items[i].weight << " " << items[i].value << " " << items[i].profit << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (W >= items[i].weight)
        {
            max_profit += items[i].value;
            W -= items[i].weight;
        }
        else
        {
            max_profit += ((float)W / (float)items[i].weight) * items[i].value;
            W = 0;
            break;
        }
    }
    std::cout << "Max profit: " << max_profit << std::endl;
}

int main()
{
    int n = 5;
    Item items[] = {{5, 30}, {10, 20}, {20, 100}, {30, 90}, {40, 160}};
    int capacity = 60;
    fractional_knapsack(items, n, capacity);
    return 0;
}