//
// Created by Jake M O'Neill on 29/06/2022.
//
#include <vector>
#include <unordered_set>
#include <iostream>

//13594824


using namespace std;

class BruteForceDfs {

private:
    int dfs(const vector<vector<int>>& grid, unordered_set<int> visited, const int& current, const int& columns){
        if(grid[current / columns][current % columns])
            return 0;

        if(current == columns*static_cast<int>(grid.size()) - 1)
            return !grid[grid.size() - 1][columns - 1];

        visited.insert(visited.begin(), current);

        int numberPaths{0};

        //do not explore if next is blocked, out of grid, or already visited.
        if(((current + 1) % columns != 0) &&
           !grid[current / columns][current % columns +1] &&
           visited.find(current+1) == visited.end()
           ){
            numberPaths += dfs(grid, visited, current +1, columns);
        }
        if((current / columns) + 1 < grid.size() &&
           !grid[(current / columns) + 1][current % columns] &&
           visited.find(current+columns) == visited.end()
           ){
            numberPaths += dfs(grid, visited, current +columns, columns);
        }
        return numberPaths;

    }


public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       unordered_set<int> visited;
       return dfs(obstacleGrid, visited, 0, static_cast<int>(obstacleGrid[0].size()));
    }
};


int main(){
    vector<vector<int>> test{{0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0},{1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1},{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},{0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0},{1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},{0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},{0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1},{0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},{1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0},{0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0},{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0},{0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1},{0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0},{1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0},{1,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1},{1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0}};
    BruteForceDfs dfs{};
    int result = dfs.uniquePathsWithObstacles(test);
    cout << result << endl;
}
