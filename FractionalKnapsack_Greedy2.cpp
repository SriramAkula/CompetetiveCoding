#include <bits/stdc++.h>
using namespace std;

struct Knapsack{
    int weight;
    int value;
    double profit;
};

bool comp(Knapsack a, Knapsack b) {
    return a.profit > b.profit;
}

int main() {
    int weights[3] = {10, 20, 30};
    int values[3] = {50, 70, 90};
    int W = 50;

    // Array of Knapsack structs
    Knapsack knapsacks[3];

    for (int i = 0; i < 3; i++) {
        knapsacks[i].weight = weights[i];
        knapsacks[i].value = values[i];
        // Calculate profit ratio for each item
        knapsacks[i].profit = (double) knapsacks[i].value / knapsacks[i].weight;
    }

    // Sort items by profit-to-weight ratio
    sort(knapsacks, knapsacks + 3, comp);

    double profit = 0;  // Initialize profit

    for (int i = 0; i < 3; i++) {
        if (knapsacks[i].weight <= W) {
            W -= knapsacks[i].weight;
            profit += knapsacks[i].value;
        } else {
            profit += W * knapsacks[i].profit;
            W = 0;
            break;
        }
    }

    cout << "Maximum profit: " << profit << endl;

    return 0;
}
