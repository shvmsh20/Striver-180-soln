//Single source shprtest path
//O(V*E)
 vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        int inf = 1e8;
        vector<int> dist(V , inf);
        dist[S]=0;
        for(int i=0; i<V-1; i++){
            for(auto x: adj){
                int u = x[0], v = x[1], w = x[2];
                if(dist[v]>dist[u]+w){
                    dist[v] = dist[u]+w;
                }
            }
        }
        return dist;
    }