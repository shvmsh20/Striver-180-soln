//Sol1
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> s;
        ListNode *curr = headA;
        while(curr!=nullptr){
            s.insert(curr);
            curr=curr->next;
        }
        curr = headB;
        while(curr!=nullptr){
            if(s.find(curr)!=s.end()){
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

//Sol2
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0, len2=0, diff;
        ListNode *curr = headA;
        while(curr!=nullptr){
            curr = curr->next;
            len1++;
        }
        curr = headB;;
        while(curr!=nullptr){
            curr = curr->next;
            len2++;
        }
        diff = max(len1, len2) - min(len1, len2);
        ListNode *start1 = headA, *start2 = headB;
        if(len1<len2){
            while(diff--){
                start2 = start2->next;
            }
        }else{
            while(diff--){
                start1 = start1->next;
            }
        }
        while(start1!=nullptr && start2!=nullptr){
            if(start1==start2){
                return start1;
            }
            start1 = start1->next;
            start2 = start2->next;
        }
        return nullptr;
        
    }

//Sol3
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=b){
            a = (a==nullptr)?headB:a->next;
            b = (b==nullptr)?headA:b->next;
        }
        return a;
    }
