#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        return lengthOfLastWord1(s);
    }

    int lengthOfLastWord1(const char *s) {
        int N = strlen(s);
        int i = N-1;
        while( i>=0 && s[i] == ' ' ) i--;
        int j = i;
        while( j>=0 && s[j] != ' ' ) j--;
        return i-j;
    }

    int lengthOfLastWord2(const char *s) {
        int i = 0;
        int stai = 0;
        int last = 0;
        while( s[i] ) {
            while ( s[i] && s[i] == ' ' ) i++;
            if ( !s[i] ) break;
            stai = i;
            while( s[i] && s[i] != ' ' ) i++;
            last = i-stai;
        }
        return last;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         cout << sol.lengthOfLastWord("hello, world   ") <<endl;
    }
    return 0;
}

