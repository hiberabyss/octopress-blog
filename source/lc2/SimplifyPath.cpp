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
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ents;
        istringstream iss(path);
        string token;
        while( getline(iss, token, '/') ) {
            if ( token.empty() || token == "." ) continue;
            if ( token != ".." ) {
                ents.push_back(token);
            } else if ( !ents.empty() ) ents.pop_back();
        }
        string res;
        if ( ents.empty() ) return "/";
        for (auto s : ents) res += "/" + s;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         cout << sol.simplifyPath("/a/../../b/../../c/") <<endl;
    }
    return 0;
}

