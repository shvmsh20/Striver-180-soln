class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *next, *prev;
        Node(int x, int v){
            key = x;
            val = v;
            prev=nullptr;
            next = nullptr;
        }
    };
    
    int size;
    unordered_map<int, Node*> mp;
    Node *head = new Node(0, 0);
    Node *tail = new Node(0, 0);
    LRUCache(int capacity) {
       
            size = capacity;
            
            head->next = tail;
            tail->prev = head;
    }
    
    void addNode(Node *newNode){
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }
    void deleteNode(Node *delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    
    }
        
    int get(int key_) {
        if(mp.find(key_)!=mp.end()){
            Node *resNode = mp[key_];
            int res = resNode->val;
            
            deleteNode(resNode);
            addNode(resNode);
           
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_)!=mp.end()){
            Node *existNode = mp[key_];
            mp.erase(key_);
            deleteNode(existNode);
        }
        if(mp.size()==size){
            Node *delNode = tail->prev;
            mp.erase(delNode->key);
            deleteNode(delNode);
        }
        Node *newNode = new Node(key_, value);
        mp[key_] = newNode;
        addNode(newNode);
        
    }
};
