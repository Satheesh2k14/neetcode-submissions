/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //8 lists 1,2 3,4 5,6 7,8 then 1,3 5,7 then 1,5
        //5 lists 1,2 3,4 5 then 1,3 5 then 1,5

        //base case handling when lists empty
        if (lists.empty()) {
            return nullptr;
        } 

        //merge in pairs
        int increment = 1, listsLen = lists.size();
        while (increment < listsLen) {
            for(int i = 0; i < listsLen - increment; i += increment*2) {
                lists[i] = merge2Lists(lists[i], lists[i + increment]);
            }
            increment *= 2;
        }
        return lists[0];
    }

    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);      // 1. Create a fake node on the stack
        ListNode* tail = &dummy;

        while(head1 && head2) {
            if(head1 -> val <= head2 -> val) {
                tail -> next = head1;
                head1 = head1 -> next;
            } else {
                tail -> next = head2;
                head2 = head2 -> next;
            }
            tail = tail -> next; 
        }

        tail -> next = head1 ? head1 : head2;
        //process pending items if in head2
        return dummy.next;

    }
};
