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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1(-1);
        ListNode dummy2(-1);
        ListNode *tail1 = &dummy1;
        ListNode *tail2 = &dummy2;
        while( head ) {
            if ( head->val < x ) {
                tail1->next = head;
                tail1 = tail1->next;
            } else {
                tail2->next = head;
                tail2 = tail2->next;
            }
            head = head->next;
        }

        tail1->next = dummy2.next;
        tail2->next = NULL;
        return dummy1.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,4,3,2,5,2};
        auto head = initList(num);
        head = sol.partition(head, 3);
        printList(head);
    }
    return 0;
}

