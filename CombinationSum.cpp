//
// Created by Jake M O'Neill on 22/05/2022.
//

#include <vector>

class Solution {

private:
    void findConstituents(
            const int& sum,
            const int& current,
            const int& target,
            const std::vector<int>& previousVec,
            std::vector<std::vector<int> >& result,
            std::vector<int>& candidates
            ){
        if(sum == target) {result.push_back(previousVec); return;}
        if (sum > target || current >= candidates.size()) return;
        std::vector<int> previousVecCopy = previousVec;
        previousVecCopy.push_back(candidates[current]);
        findConstituents(sum + candidates[current], current, target, previousVecCopy, result, candidates);
        findConstituents(sum, current + 1, target, previousVec, result, candidates);
    }




public:
    std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int> > result{};
        findConstituents(0, 0, target, std::vector<int>{}, result, candidates);
        return result;
    }
};

int main(){

    Solution solution{};
    std::vector<int> result{1, 2, 3, 5, 6};
    solution.combinationSum(result, 6);

}

