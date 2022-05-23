bool cyclebfs(int u, vector<int> adj[], vector<bool> &visited){
        visited[u]=true;
        queue<pair<int, int>>q;
        q.push({u, -1});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(int v: adj[x]){
                    if(visited[v]==false){
                        visited[v] = true;
                        q.push({v, x});
                    }else{
                        if(v!=y){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(visited[i]==false){
                if(cyclebfs(i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }