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

#define P 99991
#define S 7
#define D 1<<7

// ToReview

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        return strStr2(haystack, needle);
        return strStr1(haystack, needle);
    }

    char *strStr2(char *haystack, char *needle) {
        int N = strlen(haystack);
        int M = strlen(needle);
        if ( N<M ) return NULL;
        int ni = 0;
        int hi = 0;

        for (int i = 0; i < M; ++i ) {
            ni = ( (ni<<S) + needle[i] ) % P;
            hi = ( (hi<<S) + haystack[i] ) % P;
        } 

        int h = 1;
        for (int i = 1; i < M; ++i ) h = (h<<S) % P;

        for (int i = 0; i+M <= N; ++i ) {
            if ( hi == ni ) {
                int j = 0;
                while( j<M ) {
                    if ( haystack[i+j] != needle[j] ) break;
                    j++;
                }
                if ( j == M ) return haystack+i;
            }

            hi = ( hi - (haystack[i]*h) ) % P;
            hi = (hi+P) % P;
            hi = ((hi<<S) + haystack[i+M]) % P;
        }

        return NULL;
    }

    char *strStr1(char *haystack, char *needle) {
        if ( !haystack || !needle ) return NULL;
        int M = strlen(haystack);
        int N = strlen(needle);
        for (int i = 0; i <= M-N; ++i ) {
            int j = 0;
            while( needle[j] && haystack[i+j] == needle[j] ) j++;
            if ( !needle[j] ) return haystack+i;
        }
        return NULL;
    }

    int getPrime(int n) {
        vector<int> prim;
        for (int i = 2; i <= n; ++i ) {
            bool isPrim = true;
            for (auto j : prim) {
                if ( !(i%j) ) isPrim = false;
            }
            if ( isPrim ) prim.push_back(i);
        }
        return prim.back();
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1};
        num.pop_back();
        cout << num.back() <<endl;;
        // cout << sol.getPrime(100000) <<endl;
    }

    {
        char *s1 = "hiabcerabc";
        char *s2 = "abc";
        cout << sol.strStr(s1, s2) <<endl;
    }
    return 0;
}

