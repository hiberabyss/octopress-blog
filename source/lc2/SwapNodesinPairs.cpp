#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // return swapPairs1(head);
        return swapPairs2(head);
    }

    ListNode *swapPairs2(ListNode *head) {
        if ( !head || !head->next ) return head;
        ListNode *np = head->next;
        head->next = swapPairs2(np->next);
        np->next = head;
        return np;
    }

    ListNode *swapPairs1(ListNode *head) {
        if ( !head ) return head;
        ListNode tmpHead(0);
        tmpHead.next = head;
        ListNode *pre = &tmpHead;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while( p1 && p2 ) {
            pre->next = p2;
            pre = p1;
            p1->next = p2->next;
            p2->next = p1;
            p1 = p1->next;
            if ( p1 ) p2 = p1->next;
        }

        return tmpHead.next;
    }

    ListNode *swapLinkedList(ListNode *head) {
        ListNode *tmpHead = NULL;
        ListNode *pcur = head;

        while( pcur ) {
            ListNode *tmp = pcur->next;
            pcur->next = tmpHead;
            tmpHead = pcur;
            pcur = tmp;
        }

        return tmpHead;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,2,3,4};
        auto list = initList(num);
        printList(list);
        list = sol.swapPairs(list);
        printList(list);
    }

    {
        vector<int> num{1};
        auto list = initList(num);
        printList(list);
        list = sol.swapPairs(list);
        printList(list);
    }
    return 0;
}

