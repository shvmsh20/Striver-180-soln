//T/C: O(n), S/C: O(1)
ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0){
            return head;
        }
        int len=0;
        ListNode *curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
            len++;
        }
        len++;
        k = k%len;
        curr->next = head;
        curr = head;
        for(int i=0; i<len-k-1; i++){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;
        return head;
    }