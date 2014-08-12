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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // return mergeKLists2(lists);
        return mergeKLists3(lists);
    }

    ListNode *mergeKLists3(vector<ListNode *> &lists) {
        auto it = lists.begin();
        while( it != lists.end() ) it = *it ? it+1 : lists.erase(it);
        auto cmp = [] ( ListNode *l1, ListNode *l2 ) { return l1->val > l2->val; };
        make_heap( lists.begin(), lists.end(), cmp );
        
        ListNode dummy(-1);
        auto curP = &dummy;
        while( !lists.empty() ) {
            pop_heap( lists.begin(), lists.end(), cmp );
            auto next = lists.back();
            curP->next = next;
            curP = curP->next;
            lists.pop_back();
            if ( next->next ) { 
                next = next->next;
                lists.push_back(next);
                push_heap( lists.begin(), lists.end(), cmp );
            }
        }
        return dummy.next;
    }

    ListNode *mergeKLists2(vector<ListNode *> &lists) {
        auto merge2Lists = [&] (ListNode *l1, ListNode *l2) {
            ListNode dummy(-1);
            dummy.next = NULL;
            auto curP = &dummy;
            while( l1 && l2 ) {
                if ( l1->val <= l2->val ) curP->next = l1, l1 = l1->next;
                else curP->next = l2, l2 = l2->next;
                curP = curP->next;
            }
            curP->next = l1 ? l1 : l2;
            return dummy.next;
        };

        function<ListNode*(int,int)> mergeKListsRec = [&] (int fir, int last) {
            if ( fir == last ) return lists[fir];
            int mid = (fir+last)/2;
            auto l1 = mergeKListsRec(fir, mid);
            auto l2 = mergeKListsRec(mid+1, last);
            return merge2Lists(l1,l2);
        };

        if ( lists.empty() ) return NULL;
        return mergeKListsRec(0, lists.size()-1);
    }

    ListNode *mergeKLists1(vector<ListNode *> &lists) {
        ListNode dummy(-1);
        dummy.next = NULL;

        auto mergeTwoList = [&] ( ListNode *l1, ListNode *l2) {
            ListNode tmp(-1);
            tmp.next = NULL;
            auto curP = &tmp;

            while( l1 && l2 ) {
                if ( l1->val <= l2->val ) curP->next = l1, l1 = l1->next;
                else curP->next = l2, l2 = l2->next;
                curP = curP->next;
            }

            curP->next = l1 ? l1 : l2;
            return tmp.next;
        };

        for (size_t i = 0; i < lists.size(); ++i ) {
            dummy.next = mergeTwoList(dummy.next, lists[i]);
        }

        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,3,5,9,8,7,1};
        make_heap( num.begin(), num.end(), greater<int>() );
        pop_heap( num.begin(), num.end() );
        for (auto i : num) cout << i << " ";
        cout <<endl;
    }

    {
        vector<ListNode*> lists{
            initList({1}),
            initList({0}),
        };
        auto res = sol.mergeKLists(lists);
        printList(res);
    } 
    return 0;
}

