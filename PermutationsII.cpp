//
// Created by Jake M O'Neill on 30/05/2022.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {

    void permute(unordered_map<int, int>& nums, const vector<int>& current, vector<vector<int>>& result){
        if(nums.empty()){
            result.push_back(current);
            return;
        }
        for(auto entry: nums){
            unordered_map<int, int> numsCopy = nums;
            vector<int> currentCopy = current;
            currentCopy.push_back(entry.first);
            if(entry.second == 1) numsCopy.erase(entry.first);
            else numsCopy[entry.first]--; // don't think this is doing much
            permute(numsCopy, currentCopy, result);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> numCounts{};
        vector<vector<int>> result{};
        for(int number: nums){
            if(numCounts.find(number) == numCounts.end()) numCounts[number] = 1;
            else numCounts[number]++;
        }
        permute(numCounts, vector<int>{}, result);
        return result;
    }
};

int main(){
    vector<int> test{1, 1, 2};
    Solution sol{};
    vector<vector<int>> results = sol.permuteUnique(test);
    cout << "{";
    for(const auto& result: results){
        cout << "{";
        for(auto number: result){
            cout << number << ", ";
        }
        cout << "}";
    }
    cout << "}";
}
