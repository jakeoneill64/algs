#include <vector>
#include <algorithm>
#include <iostream>

class TupleComparator {

public:
    inline bool operator()(std::vector<int> vec1, std::vector<int> vec2){
        return vec1[0] < vec2[0];
    }
};

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), TupleComparator{});
        reduce(intervals, 0);
        return intervals;
    }
private:
    void reduce(std::vector<std::vector<int>>& intervals, const int& index){
        if(index >= intervals.size() -1) return;
        if(intervals[index][1] >= intervals[index+1][0]){
            intervals[index][1] = std::max(intervals[index][1], intervals[index+1][1]);
            intervals.erase(intervals.begin() + index + 1);
            reduce(intervals, index);
            return;
        }
        reduce(intervals, index+1);
    }
};

// [73,77],[90,94],[20,21],[84,87],[48,49],[80,80],[85,85],[53,55]


int main(){
    std::vector<std::vector<int>> test{{1, 3}, {3, 5}, {6, 9}, {73, 77}, {90, 94}, {48, 49}, {1, 100}};
    Solution sol{};
    sol.merge(test);
    std::cout << "{";
    for(const auto& result: test){
        std::cout << "{";
        for(auto number: result){
            std::cout << number << ", ";
        }
        std::cout << "}";
    }
    std::cout << "}";
}