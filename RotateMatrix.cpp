//
// Created by Jake M O'Neill on 19/05/2022.
//

#include <algorithm>
#include "RotateMatrix.h"
#include <vector>
#include <iostream>



void RotateMatrix::rotate(std::vector< std::vector<int>>& matrix) {
        std::reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i; j < matrix.size();j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
}

//int main(){
//    RotateMatrix solution;
//    std::vector<std::vector<int>> input{
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
//    solution.rotate(input);
//    for(int x = 0; x < input.size(); x++){
//        std::cout << '{';
//        for(int y = 0; y < input.size();y++){
//            std::cout << input[x][y];
//        }
//        std::cout << '}' << std::endl;
//    }
//
//}

