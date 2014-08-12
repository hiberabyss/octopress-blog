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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*,RandomListNode*> map;
        RandomListNode dummy(-1);
        auto curP = &dummy;
        while( head ) {
            curP->next = new RandomListNode(head->label);
            curP = curP->next;
            curP->random = head->random;
            map[head] = curP;
            head = head->next;
        }
        curP->next = NULL;
        curP = dummy.next;
        while( curP ) {
            curP->random = map[curP->random];
            curP = curP->next;
        }

        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

