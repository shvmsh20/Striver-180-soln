//When left-over nodes should not be reversed
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

    //OR
int len(ListNode* curr){
        int count=0;
        while(curr){
            curr=curr->next;
            count++;
        }
        return count;
    }
    ListNode* util(ListNode* head, int k, int size){
        if(head==nullptr || k==1 || k>size){
            return head;
        }
        ListNode* curr, *t, *prev;
        prev = nullptr;
        curr = t = head;
        int counter=1;
        while(curr!=nullptr && counter<=k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            counter++;
        }
        t->next = util(curr, k, size-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = len(head);
        return util(head, k, size);
    }



//When left-over nodes should be reversed    
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