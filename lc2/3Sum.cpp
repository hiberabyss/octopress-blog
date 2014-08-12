#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int N = num.size();
        vector<vector<int>> res;

        sort( num.begin(), num.end() );
        auto getTwoSum = [&] (int ind, int target) {
            int i = ind;
            int j = N-1;
            while( i<j ) {
                int sum = num[i] + num[j];
                if ( sum + target > 0 ) {
                    do{j--;} while( i<j && num[j] == num[j+1] );
                } else if ( sum + target < 0 ) {
                    do{i++;} while( i<j && num[i] == num[i-1] ); 
                } else {
                    res.push_back(vector<int>({target,num[i],num[j]}));
                    do{j--;} while( i<j && num[j] == num[j+1] );
                    do{i++;} while( i<j && num[i] == num[i-1] ); 
                }
            }
        };

        for (int i = 0; i+2 < N; ++i ) {
            if ( i && num[i] == num[i-1] ) continue;
            getTwoSum(i+1, num[i]);
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{-1, 0, 1, 2, -1, -4,};
        auto res = sol.threeSum(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

