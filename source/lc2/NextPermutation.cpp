#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int N = num.size();
        int i = N-1;
        while ( i>0 && num[i-1] >= num[i] ) i--;
        reverse( num.begin()+i, num.end() );
        if ( i>0 ) {
            int j = i;
            while ( num[j] <= num[i-1] ) j++;
            swap(num[j], num[i-1]);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{2,1,3};
        sol.nextPermutation(num);
        for (auto i : num) {
            cout << i << " ";
        }
    }
    return 0;
}
