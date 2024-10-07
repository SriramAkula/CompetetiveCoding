#include <iostream>
#include <unordered_set>
#include <cctype> // for tolower function
using namespace std;

// Function declaration
void missingPangramCharacters(const string& str){
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(char ch:str){
        int ind=ch-'a';
        arr[ind]=1;
    }
    for(int i=0;i<26;i++){
        if(arr[i]==0){
            cout<<(char)(i+'a');
        }
    }
}

int main() {
    string input;

    // Take input string
    cout << "Enter the string: ";
    getline(cin, input);

    // Call the function to find missing characters for pangram
    
    // Output the result
    cout << "Characters required to make the string a pangram: " << endl;
    missingPangramCharacters(input);

    return 0;
}
