// T/C: O(n), S/C: O(n)
Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> mp;
        Node *curr = head;
        while(curr!=nullptr){
            Node *temp = new Node(curr->val);
            mp[curr] = temp;
            curr = curr->next;
        }
        
        curr = head;
        while(curr!=nullptr){
            mp[curr]->next = curr->next?mp[curr->next]:nullptr;
            mp[curr]->random = curr->random?mp[curr->random]:nullptr;
            curr=curr->next; 
        }
        return mp[head];
    }

// T/C: O(n), S/C: O(1)
Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return head;
        }
        Node *curr = head;
        
        while(curr!=nullptr){
            Node *temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        
        curr = head;
        while(curr!=nullptr){
            curr->next->random = curr->random?curr->random->next:nullptr;
            curr = curr->next->next;
        }
        
        Node *iter = head, *front, *dummy, *copy;
        dummy = new Node(0);
        copy = dummy;
        while(iter!=nullptr){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        return dummy->next;
    }