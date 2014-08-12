#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        return addBinary2(a, b);
    }

    string addBinary2(string a, string b) {
        int i = a.size() -1;
        int j = b.size() -1;
        int sum = 0;
        string res;
        while( i>=0 || j>=0 ) {
            sum += (i>=0) ? a[i--] - '0' : 0;
            sum += (j>=0) ? b[j--] - '0' : 0;
            res += '0' + (sum&1);
            sum /= 2;
        }
        if ( sum ) res += '1';
        reverse( res.begin(), res.end() );
        return res;
    }

    string addBinary1(string a, string b) {
        string res;
        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );
        int i = 0;
        int carry = 0;
        while( a[i] && b[i] ) {
            int sum = carry + a[i] - '0' + b[i] -'0';
            carry = sum/2;
            res.push_back('0' + (sum&1));
            i++;
        }

        const string &rem = a[i] ? a.substr(i) : b.substr(i);
        i=0;
        while( rem[i] && carry ) {
            int sum = rem[i] - '0' + carry;
            carry = sum/2;
            res += '0' + (sum&1);
            i++;
        }

        if ( carry ) res += '1';
        else res += rem.substr(i);

        reverse( res.begin(), res.end() );
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string a = "111";
        string b = "1";
        cout << sol.addBinary(a, b) <<endl;
    }
    return 0;
}

