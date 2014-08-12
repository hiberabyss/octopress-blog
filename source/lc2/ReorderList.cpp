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
    void reorderList(ListNode *head) {
        if ( !head ) return;
        auto slow = head;
        auto fast = head->next;
        while( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = NULL;
        ListNode dummy(-1);
        dummy.next = NULL;
        while( fast ) {
            auto tmp = fast->next;
            fast->next = dummy.next;
            dummy.next = fast;
            fast = tmp;
        }
        auto l2 = dummy.next;
        auto curP = &dummy;
        while( head && l2 ) {
            curP->next = head;
            head = head->next;
            curP = curP->next;
            curP->next = l2;
            l2 = l2->next;
            curP = curP->next;
        }

        curP->next = head ? head : l2;
        head = dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,2,3};
        auto head = initList(num);
        sol.reorderList(head);
        printList(head);
    }
    {
        vector<int> num{1,2,3,4};
        auto head = initList(num);
        sol.reorderList(head);
        printList(head);
    }
    return 0;
}

