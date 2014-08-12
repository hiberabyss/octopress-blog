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
    ListNode *deleteDuplicates(ListNode *head) {
        if ( !head ) return head;
        ListNode dummy(-1);
        dummy.next = head;
        auto cur = head;
        head = head->next;

        while( head ) {
            if ( head->val != cur->val ) cur->next = head, cur=cur->next;
            head = head->next;
        }
        cur->next = NULL;
        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,1,2,3,3};
        auto head = initList(num);
        head = sol.deleteDuplicates(head);
        printList(head);
    }
    return 0;
}
