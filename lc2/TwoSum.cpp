#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

// ToReview

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoSum2(numbers, target);
    }

    vector<int> twoSum1(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int,int> map;
        for (size_t i = 0; i < numbers.size(); ++i ) {
            int tmp = target - numbers[i];
            if ( map.count(tmp) ) {
                res.push_back(map[tmp]+1);
                res.push_back(i+1);
            } else {
                map[numbers[i]] = i;
            }
        }
        return res;
    }

    vector<int> twoSum2(vector<int> &numbers, int target) {
        int N = numbers.size();
        vector<int> iv(N, 0);
        iota( iv.begin(), iv.end(), 0 );
        sort( iv.begin(), iv.end(), [&](int i, int j) { return numbers[i] < numbers[j]; } );
        
        vector<int> res;
        int i = 0;
        int j = N-1;
        while( i<j ) {
            int x = iv[i];
            int y = iv[j];
            int sum = numbers[x] + numbers[y];
            if ( sum > target ) j--;
            else if ( sum < target ) i++;
            else {
                res.push_back(min(x,y)+1);
                res.push_back(max(x,y)+1);
                break;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{2, 7, 11, 15};
        auto res = sol.twoSum(num, 9);
        for (auto i : res) {
            cout << i <<endl;
        }
    }
    {
        vector<int> num{3, 2, 4};
        auto res = sol.twoSum(num, 6);
        for (auto i : res) {
            cout << i <<endl;
        }
    }
    return 0;
}
