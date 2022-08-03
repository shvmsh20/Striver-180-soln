//T/C: O(ElogE + E*4*alpha)
struct Node{
	    int u, v, wt;
	    Node(int x, int y, int z){
	        u = x;
	        v = y;
	        wt = z;
	    }
	};
	struct cmp{
	    bool operator()(Node a, Node b){
	        return a.wt>b.wt;
	    }
	};
	int find(int a, vector<int> &parent){
	    if(parent[a]==a){
	        return a;
	    }
	    return parent[a] = find(parent[a], parent);
	}
	void Union(int a, int b, vector<int> &parent, vector<int> &size){
	    a = find(a, parent);
	    b = find(b, parent);
	    if(size[a]<size[b]){
	        swap(a, b);
	    }
	    parent[b] = a;
	    size[a]+=size[b];
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //OR can use an array and later sort it
        priority_queue<Node, vector<Node>, cmp> pq;
        for(int u=0; u<V; u++)
        for(auto x: adj[u]){
            int v = x[0];
            int wt = x[1];
            Node node(u, v, wt);
            pq.push(node);
        }
        vector<int> parent(V);
        vector<int> size(V);
        for(int i=0; i<V; i++){
            size[i] = 1;
            parent[i] = i;
        }
        int cost=0;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int u = node.u;
            int v = node.v;
            int wt = node.wt;
            int p1 = find(u, parent);
            int p2 = find(v, parent);
            if(p1!=p2){
                cost+= wt;
                Union(u, v, parent, size);
            }
        }
        return cost;
        
    }