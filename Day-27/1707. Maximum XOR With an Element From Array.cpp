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
    
    static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
        return a.first<b.first;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int idx=0, sz = nums.size();
        Trie trie;
        int n = queries.size();
        vector<int> res(n);
        vector<pair<int, pair<int, int>>> v;
        for(int i=0; i<n; i++){
            v.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(v.begin(), v.end(), cmp);
        for(auto p : v){
            int index = p.second.second;
            int x = p.second.first;
            int m = p.first;
            while(idx<sz && nums[idx]<=m){
                trie.buildTrie(nums[idx]);
                idx++;
            }
            int t;
            if(idx==0){
                t=-1;
            }else{
                t = trie.getMax(x);
            }
            
            res[index] = t;
            
        }
        return res;
    }