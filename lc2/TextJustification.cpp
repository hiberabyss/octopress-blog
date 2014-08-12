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

using namespace std;

// ToReview

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int M = words.size();
        vector<string> res;
        for (int i = 0; i < M; ) {
            int j = i;
            int llen = 0;
            while( j<M ) {
                llen += words[j].size();
                if ( llen + j-i > L ) break;
                j++;
            }

            string line;
            if ( j==M || i == j-1 ) {
                for (int k = i; k < j; ++k ) line += words[k] + " ";
                line.pop_back();
                line += string(L-line.size(), ' ');
            } else {
                llen -= words[j].size();
                int rem = L - llen;
                int ss = 0;
                for (int k = j-1; k >= i; --k ) {
                    if ( k>i ) {
                        ss += rem/(k-i);
                        rem %= (k-i);
                        line = string(ss, ' ') + words[k] + line;
                    } else {
                        line = words[k] + line;
                    }
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
        int L = 16;
        auto res = sol.fullJustify(words, L);
        for (auto s : res) cout << '"' << s << '"' <<endl;
        cout <<endl;
    }
    {
        vector<string> words{"Listen","to","many,","speak","to","a","few."};
        int L = 6;
        auto res = sol.fullJustify(words, L);
        for (auto s : res) cout << '"' << s << '"' <<endl;
        cout <<endl;
    }
    return 0;
}
