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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* curr = head;
        ListNode* prevgrouptail = NULL;
        int groupsize = 1;

        while (curr != NULL) {
            ListNode* temp = curr;
            int len = 0;

            while (temp != NULL && len < groupsize) {
                temp = temp->next;
                len++;
            }
            if (len % 2 == 0) {
                ListNode* prev = NULL;
                ListNode* node = curr;

                for (int i = 0; i < len; i++) {
                    ListNode* next = node->next;
                    node->next = prev;
                    prev = node;
                    node = next;
                }
                if (prevgrouptail != NULL)
                    prevgrouptail->next = prev;
                else
                    head = prev;
                curr->next = node;
                prevgrouptail = curr;
                // move to next group
                curr = node;
            } else {
                prevgrouptail = curr;

                for (int i = 0; i < len - 1; i++) {
                    prevgrouptail = prevgrouptail->next;
                }
                curr = temp;
            }
            groupsize++;
        }
        return head;
    }
};