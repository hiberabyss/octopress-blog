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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *firs = &dummy;
        ListNode *last = firs;
        int k = n-m+1;
        while( k-- ) last = last->next;
        while( --m ) {
            firs = firs->next;
            last = last->next;
        }

        ListNode *prev = firs->next;
        ListNode *next = prev->next;
        firs->next->next = last->next;
        while( prev != last ) {
            auto tmp = next->next;
            next->next = prev;
            prev = next;
            next = tmp;
        }
        firs->next = last;

        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,2,3,4,5};
        auto head = initList(num);
        head = sol.reverseBetween(head, 2, 4);
        printList(head);
    }
    return 0;
}

