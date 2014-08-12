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

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> cq,nq;
        unordered_set<string> visit;
        cq.push(start);
        visit.insert(start);

        int res = 1;
        while( !cq.empty() ) {
            while( !cq.empty() ) {
                auto cur = cq.front();
                cq.pop();
                for (auto &ch : cur) {
                    auto tmp = ch;
                    for (char i = 'a'; i <= 'z'; ++i ) {
                        ch = i;
                        if ( cur == end ) return res+1;
                        if ( !visit.count(cur) && dict.count(cur) ) {
                            nq.push(cur);
                            visit.insert(cur);
                        }
                    }
                    ch = tmp;
                }
            }
            swap(cq,nq);
            res++;
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string start = "hit";
        string end = "cog";
        unordered_set<string> dict{"hot","dot","dog","lot","log"};
        cout << sol.ladderLength(start, end, dict) <<endl;
    }
    return 0;
}

