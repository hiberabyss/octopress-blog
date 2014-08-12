#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        istringstream iss(s);
        string word;
        vector<string> vw;
        while ( iss >> word ) vw.push_back(word);
        s.clear();
        for (int i = vw.size()-1; i >= 0; --i ) {
            s += vw[i]; 
            if ( i ) s += " ";
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "   the  sky is blue ";
        sol.reverseWords(s);
        cout << s << "END" <<endl;
    }
    {
        string s = "";
        sol.reverseWords(s);
        cout << s << "END" <<endl;
    }
    return 0;
}

