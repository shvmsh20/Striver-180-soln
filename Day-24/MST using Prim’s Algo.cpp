//Brute force -> T/C: O(V^2)
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> mst(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V);
        parent[0] = -1;
        key[0] = 0;
        for(int i=0; i<V-1; i++){
            int mini = INT_MAX, node;
            for(int j=0; j<V; j++){
                if(mst[j]==false && mini>key[j]){
                    mini = key[j];
                    node = j;
                }
            }
            mst[node] = true;
            for(auto x: adj[node]){
                int v = x[0];
                int w = x[1];
                if(mst[v]==false && key[v]>w){
                    key[v] = w;
                    parent[v] = node;
                }
            }
        }
        int cost=0;
        for(int i=0; i<V; i++){
            cost+= key[i];
        }
        return cost;
    }
//Using Priority Queue -> T/C: O(NlogN)
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int cost=0;
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto y  = pq.top();
            int u = y.second;
            pq.pop();
            if(mst[u]){
                continue;
            }
            cost+=y.first;
            mst[u] = true;
            for(auto x: adj[u]){
                int v = x[0];
                int w = x[1];
                if(mst[v]==false && key[v]>w){
                    key[v] = w;
                    pq.push({w, v});
                }
            }
            
        }
        return cost;
    }
