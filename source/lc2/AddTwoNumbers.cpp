#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode tmpHead(0);
        ListNode *cur =  &tmpHead;
        int sum = 0;
        while( l1 || l2 ) {
            if ( l1 ) {
                sum += l1->val;
                l1 = l1->next;
            }

            if ( l2 ) {
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            sum /= 10;
        }

        if ( sum ) cur->next = new ListNode(sum);
        return tmpHead.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num1{2, 4, 3};
        vector<int> num2{5, 6, 4};
        auto l1 = initList(num1);
        auto l2 = initList(num2);
        auto res = sol.addTwoNumbers(l1, l2);
        printList(res);
    }
    {
        vector<int> num1{1,8};
        vector<int> num2{0};
        auto l1 = initList(num1);
        auto l2 = initList(num2);
        auto res = sol.addTwoNumbers(l1, l2);
        printList(res);
    }
    return 0;
}

