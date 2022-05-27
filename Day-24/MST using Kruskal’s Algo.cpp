struct Node{
	    int u, v, wt;
	    Node(int x, int y, int z){
	        u = x;
	        v = y;
	        wt = z;
	    }
	};
	
	static bool cmp(Node *n1, Node*n2){
	    return n1->wt<n2->wt;
	}
	
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
	    size[a]+= size[b];
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<Node*> ed;
        for(int i=0; i<V; i++){
            for(auto x: adj[i]){
                Node *node = new Node(i, x[0], x[1]);
                ed.push_back(node);
            }
        }
        sort(ed.begin(), ed.end(), cmp);
        int cost=0;
        vector<int> parent(V);
        vector<int> size(V);
        for(int i=0; i<V; i++){
            parent[i] = i;
            size[i] = 1;
        }
        for(auto it: ed){
            int u = it->u;
            int v = it->v;
            int wt = it->wt;
            int a = find(u, parent);
            int b = find(v, parent);
            if(a!=b){
                cost+= wt;
                Union(a, b, parent, size);
            }
        }
        return cost;
    }