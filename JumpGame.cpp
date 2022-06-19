//
// Created by Jake M O'Neill on 01/06/2022.
//


#include <vector>

using namespace::std;

class Solution {

    bool jump(const vector<int>& nums, const int& current){
        int largest{0};
        for(int x = current + 1; x <= current + nums[current]; x++){
            if(x + nums[x] >= nums.size() - 1) return true;
            if(nums[x] == 0) continue;
            if(x + nums[x] > largest + nums[largest]) largest = x;
        }
        if(largest == 0) return false;
        return jump(nums, largest);
    }

public:
    bool canJump(const vector<int>& nums) {
        if(nums.size() < 2) return true;
        return jump(nums, 0);
    }
};

int main(){
    Solution sol{};
    bool canJump{sol.canJump(vector{2,3,1,1,4})};
    bool cantJump{sol.canJump(vector{0})};
    return 0;
}
