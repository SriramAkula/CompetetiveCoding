#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);  // Function declaration

int main() {
    vector<int> nums = {2, 7, 11, 15};  // Example input
    int target = 13;                     // Example target

    vector<int> result = twoSum(nums, target);  // Call the function

    // Output the result
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}

// Define the twoSum function below
vector<int> twoSum(vector<int>& nums, int target) {
    // Complete the function here
    vector<int> res;
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        int comp=target-nums[i];
        if(mp.find(comp)!=mp.end()){
            res.push_back(mp[comp]);
            res.push_back(i);
            return res;
        }else{
            mp[nums[i]]=i;
        }
    }
    return res;
}
