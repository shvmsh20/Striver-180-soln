//T/C: O(n), S/C: O(1)
ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return head;
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(fast==nullptr || fast->next==nullptr) return nullptr;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }