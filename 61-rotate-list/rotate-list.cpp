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
        ListNode*temp = head;
        int count = 0;
        while(temp !=nullptr){
            count++;
            temp = temp->next;
        }
        if(count == 0 || count == 1 || k==0)return head;

        ListNode*last = head;
        while(last->next !=nullptr ){
            last = last->next;
        }
        last->next = head;

        temp = head;
        int breakpoint = count - (k % count);
        if(count == breakpoint) {
    last->next = NULL;
    return head;
}

        for(int i = 0; i<breakpoint-1; i++){
            temp = temp->next;
        }
        ListNode* newStart = temp->next;
        temp->next = NULL;
        // change start to new position
        // connect last and first
        // disconnect from start - 1
        // edge case 0 rotate
        // dual rotation
        return  newStart;
    }
};