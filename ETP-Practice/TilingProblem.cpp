#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 1; 
        return 0;
    }
    if (n == 1) {
        cout << 1; 
        return 0;
    }

    long long prev2 = 1, prev1 = 1, current;

    for (int i = 2; i <= n; i++) {
        current = (prev1 + prev2)%MOD ;
        prev2 = prev1;
        prev1 = current;
    }

    cout << current;
    return 0;
}
