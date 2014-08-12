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
#include <climits>

using namespace std;

// ToReview

class Solution {
public:
    string minWindow(string S, string T) {
        int toFind[256] = {0};
        int hasFound[256] = {0};
        
        int mini = -1;
        int minl=INT_MAX;

        for (auto c : T) toFind[c]++;

        int cnt = 0;
        for (int j=0, i=0; S[j]; ++j ) {
            char ch = S[j];
            if ( !toFind[ch] ) continue;
            hasFound[ch]++;
            if ( hasFound[ch] <= toFind[ch] ) cnt++;

            if ( cnt == T.size() ) {
                while ( !toFind[S[i]] || hasFound[S[i]] > toFind[S[i]] ) {
                    if ( toFind[S[i]] ) hasFound[S[i]]--;
                    i++;
                }

                int len = j-i+1;

                if ( len<minl ) {
                    mini=i;
                    minl=len;
                } 
            }
        }

        return mini == -1 ? "" : S.substr(mini, minl);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string str = "ADOBECODEBANC";
        string T = "ABC";
        cout << sol.minWindow(str, T) <<endl;
    }
    return 0;
}

