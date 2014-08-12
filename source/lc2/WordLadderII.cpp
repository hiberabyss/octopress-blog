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
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> cq,nq;
        unordered_map<string,vector<string>> par;
        unordered_set<string> visit;

        cq.insert(start);

        while( !cq.empty() && !cq.count(end) ) {
            for (auto &s : cq) visit.insert(s);
            for (auto cur : cq) {
                auto pre = cur;
                for (auto &ch : cur) {
                    auto tc = ch;
                    for (char c= 'a'; c <= 'z'; ++c ) {
                        ch = c;
                        if ( (!visit.count(cur) && dict.count(cur)) || cur == end ) {
                            nq.insert(cur);
                            par[cur].push_back(pre);
                        }
                    }
                    ch = tc;
                }
            }
            swap(cq,nq);
            nq.clear();
        } 

        vector<vector<string>> res;
        vector<string> path;
        function<void(string&,string&)> getPath = [&](string &S, string &E) {
            if ( S == E ) {
                res.push_back(vector<string>(path.rbegin(), path.rend()));
                return;
            }

            for (auto s : par[S]) {
                path.push_back(s);
                getPath(s,E);
                path.pop_back();
            }
        }; 

        path.push_back(end);
        getPath(end, start);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string start = "hit";
        string end = "cog";
        unordered_set<string> dict = { "hot","dot","dog","lot","log" };
        auto res = sol.findLadders(start, end, dict);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
        cout <<endl;
    }

    {
        string start = "red";
        string end = "tax";
        unordered_set<string> dict = { "ted","tex","red","tax","tad","den","rex","pee" };
        auto res = sol.findLadders(start, end, dict);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
        cout <<endl;
    }

    return 0;
}

