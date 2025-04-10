#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> arr;

    MinHeap() {}

    void insert(int x) {
        arr.push_back(x);
        heapifyUp(arr.size() - 1);
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[parent] > arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    int extractMin() {
        if (arr.empty()) return -1;

        int minEle = arr[0];

        if (arr.size() == 1) {
            arr.pop_back();
            return minEle;
        }

        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        heapifyDown(0);

        return minEle;
    }

    void heapifyDown(int i) {
        int size = arr.size();
        while (2 * i + 1 < size) {
            int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
            if (left < size && arr[left] < arr[smallest]) smallest = left;
            if (right < size && arr[right] < arr[smallest]) smallest = right;
            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    void printHeap() {
        if (arr.empty()) {
            cout << "Heap is empty" << endl;
            return;
        }
        for (int val : arr) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    int Q;
    cin >> Q;  // Number of queries

    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;
        
        if (query == "Insert") {
            int x;
            cin >> x;
            h.insert(x);
        } 
        else if (query == "ExtractMin") {
            int minVal = h.extractMin();
            if (minVal == -1) cout << "Heap is empty" << endl;
            else cout << minVal << endl;
        } 
        else if (query == "PrintHeap") {
            h.printHeap();
        }
    }

    return 0;
}
