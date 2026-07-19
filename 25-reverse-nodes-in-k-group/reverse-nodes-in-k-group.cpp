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

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;

        front->next = head;
        head->next = nullptr;
        return newhead;

    }

    ListNode* getKnode(ListNode* head, int k){
        k -= 1;
        while(k > 0 && head != nullptr){
            head = head->next;
            k--;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while(temp != nullptr){
            ListNode* knode = getKnode(temp, k);

            if(knode == nullptr){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nexthead = knode->next;
            knode->next = nullptr;
            reverseList(temp);

            if(temp == head){
                head = knode;
            }
            else{
                prevLast->next = knode;
            }
            prevLast = temp;
            temp = nexthead;
        }
        return head;

    }
};