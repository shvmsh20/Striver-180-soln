void dfs(int u, vector<vector<int>> &adj, stack<int> &st, vector<bool> &vis){
    vis[u] = true;
    for(int v: adj[u]){
        if(vis[v]==false){
            dfs(v, adj, st, vis);
        }
    }
    st.push(u);
}
void util(int u, vector<vector<int>> &adj, vector<int> &res, vector<bool> &vis){
    vis[u] = true;
    res.push_back(u);
    for(int v: adj[u]){
        if(vis[v]==false){
            util(v, adj, res, vis);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    for(auto x: edges){
        int u = x[0];
        int v = x[1];
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++){
        if(vis[i]==false){
            dfs(i, adj, st, vis);
        }
    }
    vector<vector<int>> revadj(n);
    for(auto x: edges){
        int u = x[0];
        int v = x[1];
        revadj[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        vis[i] = false;
    }
    vector<vector<int>> ans;
    while(!st.empty()){
        int i = st.top();
        st.pop();
        if(vis[i]==false){
            vector<int> res;
            util(i, revadj, res, vis);
            ans.push_back(res);
        }
    }
    return ans;
    
}