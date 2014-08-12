#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    string multiply(string num1, string num2) {
        if ( num1.empty() || num2.empty() ) return ""; 
        int N1 = num1.size();
        int N2 = num2.size();
        string res(N1+N2, '0');
        for (int i = N1-1; i >= 0; --i ) {
            int carry = 0;
            for (int j = N2-1; j >= 0; --j ) {
                int sum = carry + res[i+j+1] - '0' + (num1[i]-'0') * (num2[j]-'0');
                res[i+j+1] = sum%10 + '0';
                carry = sum/10;
            }
            res[i] = carry + '0';
        }
        int i = 0;
        while( res[i+1] && res[i] == '0' ) i++;
        return res.substr(i);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string num1 = "9";
        string num2 = "9";
        cout << sol.multiply(num1, num2) <<endl;
    }
    return 0;
}
