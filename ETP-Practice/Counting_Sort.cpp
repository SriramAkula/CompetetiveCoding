#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& inputArray){
    int m=inputArray.size();
    int M=0;
    for(int i:inputArray){
        if(i>M){
            M=i;
        }
    }
    vector<int> countArray(M+1,0);
    for(int i=0;i<m;i++){
        countArray[inputArray[i]]++;
    }
    for(int i=1;i<=M;i++){
        countArray[i]+=countArray[i-1];
    }
    vector<int> outputArray(m);
    for(int i=m-1;i>=0;i--){
        outputArray[countArray[inputArray[i]]-1]=inputArray[i];
        countArray[inputArray[i]]--;
    }
    for (int i = 0; i < m; i++) {
        inputArray[i] = outputArray[i];
    }

}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    // Take input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call counting sort
    countingSort(arr);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}