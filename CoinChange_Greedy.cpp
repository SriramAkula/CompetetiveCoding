#include <bits/stdc++.h>
using namespace std;

int main() {
    int coin[3] = {2, 5, 7};
    int Amount = 11;
    int ans = 0;
    int n = sizeof(coin) / sizeof(coin[0]);

    sort(coin, coin + n);
    
    for (int i = n - 1; i >= 0; i--) { 
        if (Amount >= coin[i]) {
            ans += (Amount / coin[i]);  
            Amount %= coin[i];          
        }
    }
    
    if (Amount > 0) {
        cout << "No Solution";
    } else {
        cout << ans << endl;
    }
    
    return 0;
}
