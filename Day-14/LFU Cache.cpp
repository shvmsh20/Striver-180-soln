struct Node{
        int key;
        int value;
        int cnt;
        Node *prev, *next;
        Node(int _key, int _val){
            key = _key;
            value = _val;
            cnt=1;
        }
    };
    
    struct List{
        int size;
        Node *head, *tail;
        
        List(){
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size=0;
        }
        
        void addFront(Node *node){
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }
        
        void removeNode(Node *delnode){
            Node *delprev = delnode->prev;
            Node *delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };


class LFUCache {
    
    int maxSizeCache, currSize, minFreq;
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        currSize=0;
        minFreq=0;
    }
    
    void updateFreqList(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(freqListMap[node->cnt]->size==0 && node->cnt==minFreq){
            minFreq++;
        }
        List *newFreqList = new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            newFreqList = freqListMap[node->cnt+1];
        }
        newFreqList->addFront(node);
        node->cnt += 1;
        freqListMap[node->cnt] = newFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node *curr = keyNode[key];
            int res = curr->value;
            updateFreqList(curr);
            return res;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0){
            return;
        }
        if(keyNode.find(key)!=keyNode.end()){
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }else{
            if(currSize==maxSizeCache){
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            List *listFreq = new List();
            minFreq = 1;
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

