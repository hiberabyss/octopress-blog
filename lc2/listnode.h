#ifndef __LISTNODE_H__
#define __LISTNODE_H__
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *initList(const vector<int> &vec) {
    ListNode head = ListNode(0);

    if ( vec.empty() ) {
        return NULL;
    }

    ListNode *pos = &head;

    for (auto i : vec) {
        pos->next = new ListNode(i);
        pos = pos->next;
    }

    return head.next;
}

void printList(ListNode *head) 
{
    while( head ) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" <<endl;
}
#endif
