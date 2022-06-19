//
// Created by Jake M O'Neill on 25/05/2022.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1) {
            return x;
        }
        if(n == 0){
            return 1;
        }
        bool negative = n < 0;
        if (n % 2 != 0){
            return negative? 1 / (x * myPow(x * x, (abs(n) -1) / 2)): x * myPow(x * x, (n - 1) / 2);
        }else{
            return negative ? 1 / myPow(x * x, abs(n) / 2) : myPow(x * x, n / 2);
        }
    }

};

int main(){
    Solution sol{};
    std::cout << sol.myPow(8, 2);
}

