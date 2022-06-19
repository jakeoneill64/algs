#include <vector>
#include <iostream>

using namespace std;

class Solution{

private:

    void permute(vector<int>& nums, vector<vector<int>>& result, vector<int>& current){
        if(nums.empty()){
            result.push_back(current);
        }
        for(int i = 0; i < nums.size(); i++){
            vector<int> numsCopy{nums};
            numsCopy.erase(numsCopy.begin() + i);
            vector<int> currentCopy{current};
            currentCopy.push_back(nums[i]);
            permute(numsCopy, result, currentCopy);
        }
    }

public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result{};
        vector<int> current{};
        permute(nums, result, current);
        return result;
    }

};

int main(){
    Solution sol{};
    vector<int> nums{1, 2, 3};
    vector<vector<int>> results{sol.permute(nums)};
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