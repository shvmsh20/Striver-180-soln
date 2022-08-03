//All pair shortest path
//T/C: O(V^3)
void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                if(i==j || i==k || j==k || matrix[i][k]==-1 || matrix[k][j]==-1){
	                    continue;
	                }
	                matrix[i][j] = min(matrix[i][j]==-1?INT_MAX:matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	}