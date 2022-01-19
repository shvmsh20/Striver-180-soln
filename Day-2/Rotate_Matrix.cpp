void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        //Transpose 
        for(int i=0; i<r; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reverse the rows
        for(int i=0; i<r; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }