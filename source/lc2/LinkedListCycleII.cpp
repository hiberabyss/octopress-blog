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
#include "listnode.h"

// ToReview

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( !head || !head->next ) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while( fast && fast->next ) {
            fast = fast->next->next;
            slow = slow->next;
            if ( fast == slow ) break;
        }

        slow = head;
        while( fast && fast != slow ) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
