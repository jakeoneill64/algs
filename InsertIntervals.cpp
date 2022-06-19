//
// Created by Jake M O'Neill on 19/06/2022.
//

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        if(intervals.size() < 1){
            intervals.push_back(newInterval);
            return intervals;
        }

        int mid = intervals.size() / 2;
        int insertIndex = partition(intervals, newInterval, 0, intervals.size() -1, mid);

        if(insertIndex > 0 && intervals[insertIndex -1][1] >= newInterval[0]){
            intervals[insertIndex - 1][1] = std::max(intervals[insertIndex - 1][1], newInterval[1]);
            merge(intervals, insertIndex -1);
            return intervals;
        }

        intervals.insert(intervals.begin() + insertIndex, newInterval);
        merge(intervals, insertIndex);

        return intervals;
    }

private:

    const int& partition(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval, const int& low, const int& high, int& mid){
        if (low > high) return mid + 1;
        mid = (low+high)/2;
        if(intervals[mid][0] == newInterval[0]) return mid;
        if(intervals[mid][0] > newInterval[0]) return partition(intervals, newInterval, low, mid-1, mid);
        return partition(intervals, newInterval, mid+1, high, mid);
    }

    void merge(std::vector<std::vector<int>>& intervals, const int& insertIndex){
        if(insertIndex >= intervals.size() -1) return;
        if(intervals[insertIndex][1] >= intervals[insertIndex+1][0]){
            intervals[insertIndex][1] = std::max(intervals[insertIndex+1][1], intervals[insertIndex][1]);
            intervals.erase(intervals.begin() + insertIndex + 1);
            merge(intervals, insertIndex);
        }
    }

};

int main(){

    //[[1,2],[3,5],[6,7],[8,10],[12,16]]
    //[4,8]

    std::vector<std::vector<int>> intervals{{1, 3}};
    std::vector<int> newInterval{0, 5};
    Solution sol{};
    sol.insert(intervals, newInterval);
    return 0;
}
