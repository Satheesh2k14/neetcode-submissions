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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //remove nth element.. only if one exists then return null
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size += 1;
            curr = curr -> next;
        }

        //if (size == 1 && n == 1) return NULL;

        //size 5, n = 2.. then 5-2+1 -> remove 4th element  
        int preIndex = size - n - 1;
        if (preIndex == -1) {
            return head -> next;
        } else {
            curr = head;
            while (preIndex > 0) {
                curr = curr -> next;
                preIndex -= 1;
            }
            if (curr -> next) {
                curr -> next = curr -> next -> next;
            } else {
                curr -> next = NULL;
            }
        }

        return head;

    }
};
