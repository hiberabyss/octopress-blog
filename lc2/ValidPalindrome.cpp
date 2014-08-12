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
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while( i<j ) {
            while( i<j && !isalnum(s[i]) ) i++;
            while( i<j && !isalnum(s[j]) ) j--;
            if ( i == j ) break;
            if ( tolower(s[i]) != tolower(s[j]) ) return false;
            i++;
            j--;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string str = "A man, a plan, a canal: Panama";
        cout << boolalpha << sol.isPalindrome(str) <<endl;
    }
    return 0;
}

