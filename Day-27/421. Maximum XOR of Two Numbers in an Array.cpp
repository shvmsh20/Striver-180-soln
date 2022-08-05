struct Node{
        Node* links[2];
        Node(){
            links[0] = nullptr;
            links[1] = nullptr;
        }
        bool containsKey(int bit){
            return links[bit]!=nullptr;
        }
        Node* getKey(int bit){
            return links[bit];
        }
        void put(int bit, Node* node){
            links[bit] = node;
        }
    };
    
    class Trie{
        private:
            Node* root = new Node();
        public:
            void buildTrie(int num){
                Node* curr = root;
                for(int i=31; i>=0; i--){
                    int index = (num>>i) & 1;
                    if(!curr->containsKey(index)){
                        curr->put(index, new Node());
                    }
                    curr = curr->getKey(index);
                }
            }
            int getMax(int num){
                int res=0;
                Node* curr = root;
                for(int i=31; i>=0; i--){
                    int index = (num>>i) & 1;
                    if(curr->containsKey(1-index)){
                        res = res | (1<<i);
                        curr = curr->getKey(1-index);
                    }else{
                        curr = curr->getKey(index);
                    }
                }
                return res;
            }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int x: nums){
            trie.buildTrie(x);
        }
        int res = INT_MIN;
        for(int x: nums){
            int t = trie.getMax(x);
            res = max(res, t);
        }
        return res;
    }