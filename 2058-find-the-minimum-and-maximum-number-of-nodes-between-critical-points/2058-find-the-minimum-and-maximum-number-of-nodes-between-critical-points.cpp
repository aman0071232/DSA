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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if(!head||!head->next || !head->next->next){
            return{-1,-1};
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;
        int prevCriticalPos = -1;
        int firstCriticalPos = -1;

        int minDist = INT_MAX;

        while (curr->next != NULL) {
            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {
                if (prevCriticalPos == -1) {
                    firstCriticalPos = i;
                    prevCriticalPos = i;
                } else {
                    minDist = min(minDist, i - prevCriticalPos);
                    prevCriticalPos = i;
                }
            }

            prev = curr;
           curr= curr->next;
            i++;
        }
        if (firstCriticalPos==-1 || firstCriticalPos==prevCriticalPos) {
            return {-1, -1};
        }
        int maxDist=prevCriticalPos-firstCriticalPos;
        return{minDist,maxDist};
    }
};