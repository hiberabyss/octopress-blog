#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *endp = &dummy;
        while( n-- >= 0 ) endp = endp->next;
        ListNode *pre = &dummy;
        while( endp ) {
            pre = pre->next;
            endp = endp->next;
        }

        auto tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,2,3,4,5};
        auto head = initList(num);
        head = sol.removeNthFromEnd(head, 2);
        printList(head);
    } 

    {
        vector<int> num{1};
        auto head = initList(num);
        head = sol.removeNthFromEnd(head, 1);
        printList(head);
    }
    return 0;
}

