/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
   Node* flatten(Node* head) {
    Node* curr = head;
    while (curr) {
        if (curr->child) {
            Node* next = curr->next;

            // flatten the child list and attach right after curr
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;

            // find the tail of the flattened child list
            Node* tail = curr;
            while (tail->next) tail = tail->next;

            // connect tail to the saved next
            if (next) {
                tail->next = next;
                next->prev = tail;
            }
        }
        curr = curr->next;
    }
    return head;
}
};