struct Node{
    int val, idx, adx;
};
struct cmp{
    bool operator()(Node a, Node b){
        return a.val>b.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<Node, vector<Node>, cmp> pq;
    for(int i=0; i<k; i++){
        if(kArrays[i].size()!=0){
            pq.push({kArrays[i][0], 0, i});
        }
    }
    vector<int> res;
    while(!pq.empty()){
        Node t = pq.top();
        pq.pop();
        res.push_back(t.val);
        if(t.idx+1<kArrays[t.adx].size()){
            pq.push({kArrays[t.adx][t.idx+1], t.idx+1, t.adx});
        }
    }
    return res;
    
}