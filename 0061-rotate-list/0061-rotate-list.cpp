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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> arr;
        if (head == NULL || head->next == NULL) {
            return head;
        }
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        k = k % arr.size();
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());

        temp = head;
        int i = 0;
        while (i < arr.size()) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};