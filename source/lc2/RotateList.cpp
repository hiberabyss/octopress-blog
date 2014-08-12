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
    ListNode *rotateRight(ListNode *head, int k) {
        if ( !head || !k ) return head;
        ListNode dummy(-1);
        dummy.next = head;
        auto slow = head;
        auto fast = head;
        int len = 0;
        for ( auto tmp=head; tmp; tmp=tmp->next, len++ );
        k %= len;
        if ( !k ) return head;
        while( k-- ) fast = fast->next;
        while( fast->next ) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = dummy.next;
        dummy.next = slow->next;
        slow->next = NULL;
        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         vector<int> num{1,2,3,4,5};
         auto head = initList(num);
         head = sol.rotateRight(head, 2);
         printList(head);
    }
    return 0;
}
