#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    string convert(string s, int nRows) {
        string res;
        if ( nRows == 1 ) return s;
        int N = s.size();
        int L = 2 * (nRows-1);
        for (int i = 0; i < nRows && s[i]; ++i ) {
            for (int j = i; j < N; j += L ) {
                res += s[j];
                if ( i && i != nRows-1 ) {
                    int k = j +  L - 2*i;
                    if ( k<N ) res += s[k];
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "PAYPALISHIRING";
        cout << sol.convert(s, 3) <<endl;
    }
    return 0;
}

