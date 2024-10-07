#include <iostream>
using namespace std;

// Function declaration
bool isAnagram(string s1, string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(int i=0;i<s1.length();i++){
        int ind=s1[i]-'a';
        int ind2=s2[i]-'a';
        arr[ind]++;
        arr[ind2]--;
    }
    for(int i:arr){
        if(i!=0){
            return false;
        }
    }
    return true;
}

int main() {
    string s1, s2;

    // Input two strings
    cout << "Enter the first string: ";
    getline(cin, s1);
    cout << "Enter the second string: ";
    getline(cin, s2);

    // Check if they are anagrams
    if (isAnagram(s1, s2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
