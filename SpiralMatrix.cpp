//
// Created by Jake M O'Neill on 30/05/2022.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
    vector<int> spiralOrder(vector<vector<int>>& matrix, vector<int>& result) {
        if(matrix.size() == 0) return result;
        result.insert(result.end(), matrix[0].begin(), matrix[0].end());
        matrix.erase(matrix.begin());
        vector<vector<int>> replacement{};
        for(int x = matrix[0].size() -1; x >= 0; x--) {
            vector<int> tmp{};
            replacement.push_back(tmp);
            for (unsigned long y = 0; y < matrix.size(); y++) {
                replacement[matrix[0].size() -1 - x ].push_back(matrix[y][x]);
            }
        }
        return spiralOrder(replacement, result);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> result{};
        return spiralOrder(matrix, result);
    }
};

int main(){
    Solution sol{};
    vector<vector<int>> example{{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    vector<int> result = sol.spiralOrder(example);
    cout << "{ ";
    for(auto item: result){
        cout << item << ", ";
    }
    cout << " }" << endl;
}
