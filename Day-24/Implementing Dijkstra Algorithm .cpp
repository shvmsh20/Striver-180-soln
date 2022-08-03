//Single sourve sortest path
//Basic Version 
//T/C: O(V+E + V^2)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            int currMn = INT_MAX;
            int u=-1;
            for(int j=0; j<V; j++){
                if(vis[j]==false && dist[j]<currMn){
                    u = j;
                    currMn = dist[j]; 
                }
            }
                vis[u] = true;
                for(auto x: adj[u]){
                    int v = x[0];
                    int wt = x[1];
                    if(dist[u]+wt<dist[v]){
                        dist[v] = dist[u]+wt;
                    }
                }
            
        }
        return dist;
    }


//T/C: O(V+E + VlogV)
struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.first>b.first;
        }
    };
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
        for(int i=0; i<V; i++){
            pq.push({INT_MAX, i});
        }
        pq.push({0, S});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int u = p.second;
            if(vis[u]){
                continue;
            }
            vis[u] = true;
            for(auto x: adj[u]){
                int v = x[0];
                int wt = x[1];
                if(dist[u]+wt<dist[v]){
                    dist[v] = dist[u]+wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }