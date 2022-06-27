//
// Created by Jake M O'Neill on 25/06/2022.
//

#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result{};
        sort(nums.begin(), nums.end());
        subset(nums, 0, vector<int>{}, result);
        return result;
    }

private:

    void subset(vector<int> sorted, const int& index, const vector<int>& current, vector<vector<int>>& result){
        if(index >= sorted.size()){
            result.push_back(current);
            return;
        }
        vector<int> currentCopy{current};
        currentCopy.push_back(sorted[index]);
        subset(sorted, index + 1, currentCopy, result);
        int newIndex = sorted.size();
        for(int x = index; x < sorted.size(); x++){
            if(sorted[x] > sorted[index]){
                newIndex = x;
                break;
            }
        }
        subset(sorted, newIndex, current, result);
    }

};


int main(){
    Solution sol{};
    vector<int> test{1, 2, 2};
    sol.subsetsWithDup(test);
    return 0;
}

