#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

class Item{
public:
    int weight;
    int value;
    float profit;
    Item():weight(0),value(0){}
    Item(int w,int v):weight(w),value(v){}
    bool operator<(const Item &i) const
    {
        return profit < i.profit;
    }

    bool operator>(const Item &i) const
    {
        return profit > i.profit;
    }
};

int fractionalKnapsack(Item items[], int W,int n,int *steps){

    for(int i=0;i<n;i++){
        items[i].profit = (float)(items[i].value/items[i].weight);
        (*steps)++;
    }
    sort(items,items+n,std::greater<Item>());
    float maxProfit = 0;
    for(int i=0;i<n;i++){
        if(W>=items[i].weight){
            maxProfit += items[i].value;
            W -= items[i].weight;
            (*steps) += 2;
        }else if(W>0){
            maxProfit += ((float)W / (float)items[i].weight) * items[i].value;
            (*steps)++;
            break;
        }
    }
    return maxProfit;
}

int main(){
    // Fractional Kanpsack
    Item items[] = {{5, 30}, {10, 20}, {20, 100}, {30, 90}, {40, 160}};
    int steps = 5;
    float profit = fractionalKnapsack(items,60,5,&steps);
    cout<<"Optimal profit earned: "<<profit<<endl;
    cout<<"Steps: "<<steps<<endl;
    cout<<"Name: Roman Ojha"<<endl;
    cout<<"Roll: 25"<<endl;
    cout<<"Time: "<<time<<endl;
    return 0;
}

