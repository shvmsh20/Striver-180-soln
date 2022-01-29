//Sol1
bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;
        ListNode *curr = head;
        while(curr!=nullptr){
            if(s.find(curr)!=s.end()){
                return true;
            }else{
                s.insert(curr);
                curr=curr->next;
            }
        }
        return false;
    }

//Sol
//T/C:O(n)
 bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }    