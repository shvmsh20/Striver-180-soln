// T/C : O(n), S/C: O(n)
bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *curr = head;
        while(curr!=nullptr){
            s.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr!=nullptr){
            if(s.top()!=curr->val){
                return false;
            }
            s.pop();
            curr = curr->next;
        }
        return true;
    }

// T/C : O(n), S/C: O(1)    
ListNode *reverse(ListNode *head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode *prev=nullptr, *curr=head, *next;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr = next;
        }
        return prev;
    }
    ListNode *findMiddle(ListNode *head){
        ListNode *fast = head, *slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        ListNode *mid = findMiddle(head), *p1, *p2;
        mid->next = reverse(mid->next);
        p1 = head, p2 = mid->next;
        while(p2!=nullptr){
            if(p1->val!=p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }    