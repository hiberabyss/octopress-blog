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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if ( !node ) return NULL;
        typedef UndirectedGraphNode GNode;
        unordered_set<GNode*> visit;
        unordered_map<int,GNode*> map;

        queue<GNode*> que;
        que.push(node);

        while( !que.empty() ) {
            auto old = que.front();
            que.pop();
            if ( visit.count(old) ) continue;
            int lb = old->label;
            if ( !map.count(lb) ) map[lb] = new GNode(lb);
            auto &neib = map[lb]->neighbors;
            for (auto n : old->neighbors) {
                if ( !map.count(n->label) ) map[n->label]= new GNode(n->label);
                neib.push_back(map[n->label]);
                que.push(n);
            }
            visit.insert(old);
        }

        return map[node->label];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
