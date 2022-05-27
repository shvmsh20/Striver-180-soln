vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<V; i++){
            pq.push(make_pair(INT_MAX, i));
        }
        pq.push(make_pair(0, S));
        dist[S]=0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int u = p.second;
            for(auto x: adj[u]){
                int v = x[0];
                int w = x[1];
                if(dist[v]>(w+dist[u])){
                    pq.push(make_pair(w+dist[u], v));
                    dist[v] = w+dist[u];
                }
            }
        }
        return dist;
    }