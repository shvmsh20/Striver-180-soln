//Basic Implementation
struct Node{
        vector<Node*> child;
        int freq;
        Node(){
            freq=0;
            child.resize(26);
            for(int i=0; i<26; i++){
                child[i] = nullptr;
            }
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new Node();
            }
            curr = curr->child[index];
            curr->freq++;
        }
        
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                return false;
            }else{
                curr = curr->child[index];
            }
        }
        int currFreq = curr->freq;
        int childFreq=0;
        for(int i=0; i<26; i++){
            if(curr->child[i]!=nullptr){
                childFreq += curr->child[i]->freq;
            }
        }
        return currFreq!=childFreq;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char x: prefix){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                return false;
            }else{
                curr = curr->child[index];
            }
        }
        return true;
    }

//Striver's Implementation
struct Node{
        vector<Node*> child;
        bool flag;
        Node(){
            flag = false;
            child.resize(26);
            for(int i=0; i<26; i++){
                child[i] = nullptr;
            }
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new Node();
            }
            curr = curr->child[index];
        }
        curr->flag = true;
        
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                return false;
            }else{
                curr = curr->child[index];
            }
        }
        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char x: prefix){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                return false;
            }else{
                curr = curr->child[index];
            }
        }
        return true;
    }    