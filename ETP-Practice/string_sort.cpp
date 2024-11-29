#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

void sortString(string &s) {
  
    int charCount[MAX_CHAR] = {0};
    
    for (int i = 0; i < s.length(); i++) {
      
        charCount[s[i] - 'a']++;
    }
    
    for (int i = 0; i < MAX_CHAR; i++) {
        for (int j = 0; j < charCount[i]; j++) {
            cout << (char)('a' + i);
        }
    }
}

int main() {
    string s = "geeksforgeeks";    
    sortString(s);    
    return 0;
}