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

// ToReview

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates2(head);
    }

    ListNode *deleteDuplicates2(ListNode *head) {
        ListNode dummy(-1);
        auto cur = &dummy;
        while( head ) {
            auto last = head;
            while ( head->next && head->val == head->next->val ) head = head->next;
            if ( head == last ) {
                cur->next = head;
                cur = cur->next;
            } 
            head = head->next;
        }
        cur->next = NULL;
        return dummy.next;
    }

    ListNode *deleteDuplicates1(ListNode *head) {
        ListNode dummy(-1);
        auto inP = &dummy;
        auto cur = head;
        while( cur && cur->next ) {
            if ( cur->val != cur->next->val ) {
                inP->next = cur;
                inP = inP->next;
            } else {
                while( cur->next && cur->val == cur->next->val ) {
                    cur = cur->next;
                }
            }
            cur = cur->next;
        }
        inP->next = cur ? cur : NULL;
        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,1};
        auto head = initList(num);
        head = sol.deleteDuplicates(head);
        printList(head);
    }

    {
        vector<int> num{1,2,3,3,4,4,5};
        auto head = initList(num);
        head = sol.deleteDuplicates(head);
        printList(head);
    }
    return 0;
}
