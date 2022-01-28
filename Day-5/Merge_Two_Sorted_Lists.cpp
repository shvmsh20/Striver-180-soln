//T/C: O(n+m) S/C: O(n+m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *d = new ListNode(0), *dd, *temp;
        dd = d;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
            temp = new ListNode(list1->val);
            list1=list1->next;
        }else{
            temp = new ListNode(list2->val);
            list2=list2->next;
            }
            dd->next = temp;
            dd = temp;
        }
        while(list1!=nullptr){
            temp = new ListNode(list1->val);
            list1=list1->next;
            dd->next = temp;
            dd = temp;
        }
        while(list2!=nullptr){
            temp = new ListNode(list2->val);
            list2=list2->next;
            dd->next = temp;
            dd = temp;
        }
        dd->next = nullptr;
        return d->next;
    }
//T/C: O(n+m) S/C: O(1)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }else if(l2==nullptr){
            return l1;
        }
        else{
            ListNode* head=nullptr, *tail=nullptr;
            if(l1->val<=l2->val){
                head = l1;
                tail=l1;
                l1=l1->next;
            }else{
                head = l2;
                tail=l2;
                l2=l2->next;
            }
            while(l1!=nullptr && l2!=nullptr){
                if(l1->val<=l2->val){
                    tail->next = l1;
                    tail = l1;
                    l1=l1->next;
                }else{
                     tail->next = l2;
                     tail = l2;
                     l2=l2->next;
                }
            }
            if(l1==nullptr){
                tail->next = l2;
            }else{
                tail->next= l1;
            }
            return head;
            
        }