//
// Created by Jake M O'Neill on 29/06/2022.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {

private:
    int dfs(const vector<vector<int>>& grid, unordered_set<int> visited, const int& current){
        if(current == grid[0].size()*grid.size() - 1)
            return 1;

        visited.insert(visited.begin(), current);

        int numberPaths{0};

        //do not explore if next is blocked, out of grid, or already visited.
        if(static_cast<int>((current % grid[0].size()) -1 >= 0) &&
            !grid[static_cast<int>current / grid[0].size()][current % grid[0].size() -1] &&
            visited.find(current-1) == visited.end()
            ){
            numberPaths = dfs(grid, visited, current -1);
        }
        if(static_cast<int>(((current + 1) % grid[0].size()) != 0) &&
           !grid[current / grid[0].size()][current % grid[0].size() +1] &&
           visited.find(current+1) == visited.end()
                ){
            numberPaths += dfs(grid, visited, current +1);
        }
        if(static_cast<int>((current / grid[0].size()) -1) >= 0 &&
           !grid[(current / grid[0].size()) -1][current % grid[0].size()] &&
                visited.find(current-grid[0].size()) == visited.end()
                ){
            numberPaths += dfs(grid, visited, current -grid[0].size());
        }
        if(static_cast<int>((current / grid[0].size()) + 1) < grid.size() &&
           !grid[(current / grid[0].size()) + 1][current % grid[0].size()] &&
           visited.find(current+grid[0].size()) == visited.end()
                ){
            numberPaths += dfs(grid, visited, current +grid[0].size());
        }
        return numberPaths;

    }


public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       unordered_set<int> visited;
       return dfs(obstacleGrid, visited, 0);
    }
};


int main(){
    vector<vector<int>> test{{0,0,0}, {0,1,0}, {0,0,0}};
    Solution sol{};
    int result = sol.uniquePathsWithObstacles(test);
    return 0;
}
