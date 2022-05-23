bool bfs(int i, vector<vector<int>> &adj, vector<int> &color){
        color[i] = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(color[v]==-1){
                    q.push(v);
                    color[v] = 1^color[u];

                }else if(color[v]==color[u]){
                     return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int x: graph[i]){
                adj[i].push_back(x);
            }
        }
        for(int i=0; i<n ;i++){
            if(color[i]==-1 && bfs(i, adj, color)==false){
                return false;
            }
        }
        return true;
    }