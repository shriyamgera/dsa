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
    ListNode* mergeNodes(ListNode* head) {
         ListNode* current = head->next;
        ListNode* newNode = head;
        int sum = 0;

        while (current != nullptr) {
            if (current->val == 0) {
                newNode->val = sum;
                if (current->next != nullptr) {
                    newNode->next = current;
                    newNode = current;
                    sum = 0;
                } else {
                    newNode->next = nullptr;
                }
            } else {
                sum += current->val;
            }
            current = current->next;
        }

        return head;
    }
};