#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    string s1 = "";
    vector<int> vec; 

    for(char ch : s) {
        // Ignore curly braces
        if(ch == '{' || ch == '}') {
            continue;
        }
        // If a comma is found, convert accumulated number to integer and store it
        else if(ch == ',') {
            if(!s1.empty()) {
                vec.push_back(stoi(s1));
                s1 = "";
            }
        }
        // Accumulate characters to form numbers
        else {
            s1 += ch;
        }
    }
    // Add the last accumulated number if any
    if(!s1.empty()) {
        vec.push_back(stoi(s1));
    }

    // Output the result
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main() {
//     string s = "{1,2,3,4}";
//     string s1 = "";
//     vector<int> vec; 
    
//     for (char ch : s) {
//         if (ch == ',' || ch == '}') { 
//             if (!s1.empty()) {
//                 vec.push_back(stoi(s1));
//                 s1 = ""; 
//             }
//         } else if (isdigit(ch) || ch == '-') { 
//             s1 += ch;
//         }
//     }

//     for (int i = 0; i < vec.size(); i++) {
//         cout << vec[i] << " ";
//     }

//     return 0;
// }