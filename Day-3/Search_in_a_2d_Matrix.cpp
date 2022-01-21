//GFG Soln
int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int i = 0, j = M-1;
	    while(i<N && j>=0){
	        if(mat[i][j]==X){
	            return 1;
	        }else if(mat[i][j]<X){
	            i++;
	        }else{
	            j--;
	        }
	    }
	    return 0;
	}


//Leetcode Soln
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = (n*m)-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int i = mid/m, j = mid%m;
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]<target){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return false;
    }    