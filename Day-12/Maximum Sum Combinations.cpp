class node{
    public:
    int val, idx, jdx;
};
struct cmp{
    bool operator()(node a, node b){
        return a.val<b.val;
    }
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({A[n-1]+B[n-1], n-1, n-1});
    set<pair<int, int>> s;
    while(ans.size()<C){
        node t = pq.top();
        pq.pop();
        int value = t.val;
        int i=t.idx, j=t.jdx;
        ans.push_back(value);
        if(i>0 && s.find({i-1, j})==s.end()){
            pq.push({A[i-1]+B[j], i-1, j});
            s.insert({i-1, j});
        }
        if(j>0 && s.find({i, j-1})==s.end()){
            pq.push({A[i]+B[j-1], i, j-1});
            s.insert({i, j-1});
        }
    }
    return ans;
    
}
