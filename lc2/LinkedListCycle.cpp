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

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast=head;
        while( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast ) return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

