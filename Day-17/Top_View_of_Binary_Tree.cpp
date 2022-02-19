//T/C: O(n), S/C: O(n)
vector<int> topView(Node *root)
    {
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        vector<int> v;
        q.push({root, 0});
        while(q.empty()==false){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto temp = q.front();
                q.pop();
                if(mp.find(temp.second)==mp.end()){
                    mp[temp.second] = temp.first->data;
                }
                if(temp.first->left){
                    q.push({temp.first->left, temp.second-1});
                }
                if(temp.first->right){
                    q.push({temp.first->right, temp.second+1});
                }
            }
        }
        for(auto x: mp){
            v.push_back(x.second);
        }
        return v;
    }