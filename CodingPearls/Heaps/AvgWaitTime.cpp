#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii; 

int minAverageWaitingTime(vector<pii>& customers) {
    int n = customers.size();
    
    sort(customers.begin(), customers.end());

    priority_queue<pii, vector<pii>, greater<pii>> minHeap;

    long long currentTime = 0;
    long long totalWaitTime = 0;
    int index = 0;

    while (index < n || !minHeap.empty()) {
        while (index < n && customers[index].first <= currentTime) {
            minHeap.push({customers[index].second, customers[index].first});
            index++;
        }

        if (!minHeap.empty()) {
            auto [cookTime, arrivalTime] = minHeap.top();
            minHeap.pop();
            currentTime += cookTime;
            totalWaitTime += (currentTime - arrivalTime);
        } else {
            currentTime = customers[index].first;
        }
    }

    return totalWaitTime / n;
}

int main() {
    int n;
    cin >> n;
    vector<pii> customers(n);

    for (int i = 0; i < n; ++i) {
        cin >> customers[i].first >> customers[i].second;
    }

    cout << minAverageWaitingTime(customers) << endl;

    return 0;
}
