#include <bits/stdc++.h>
using namespace std;

// Custom comparator to sort by frequency in descending order
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;  // Sort by frequency
}

int main() {
    int arr[] = {2, 2, 5, 2, 3, 4, 5, 5, 5, 4};
    int n = 10;
    unordered_map<int, int> mp;

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // Transfer data from unordered_map to vector of pairs for sorting
    vector<pair<int, int>> freq_vec(mp.begin(), mp.end());

    // Sort the vector using the custom comparator
    sort(freq_vec.begin(), freq_vec.end(), cmp);

    // Print the sorted frequency
    for (auto &it : freq_vec) {
        while(it.second--){

            cout << it.first << " " ;
        }
    }

    return 0;
}
