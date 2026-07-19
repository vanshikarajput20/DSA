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
    ListNode* getNthnode(ListNode* head, int k){
        k-=1;
        while(k>0){
            head = head->next;
            k--;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* temp = head;
        ListNode* tail = head;
        int len = 1;

        while(tail->next != nullptr){
            tail = tail->next;
            len++;
        }
        if(k % len == 0) return head;
        k = k % len;
        ListNode* node = getNthnode(temp, len - k);

        tail->next = head;
        head = node->next;
        node->next = nullptr;
        return head;
    }
};