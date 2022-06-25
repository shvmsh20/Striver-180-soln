//When left-over nodes should be reversed
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1){
            return head;
        }
        ListNode *dummy = new ListNode(0), *pre, *curr=head, *nex;
        dummy->next = head;
        pre = dummy;
        int count=0;
        while(curr!=nullptr){
            curr = curr->next;
            count++;
        }
        while(count>=k){
            curr = pre->next;
            nex = curr->next;
            for(int i=0; i<k-1; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            count-=k;
            pre = curr;
           
        }
        return dummy->next;
    }

//When left-over nodes should not be reversed    
struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==nullptr){
            return nullptr;
        }
        node* curr, *t, *prev;
        prev = nullptr;
        curr = t = head;
        int counter=1;
        while(curr!=nullptr && counter<=k){
            node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            counter++;
        }
        t->next = reverse(curr, k);
        return prev;
    }