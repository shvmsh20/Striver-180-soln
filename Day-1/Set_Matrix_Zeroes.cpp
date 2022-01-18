void setZeroes(vector<vector<int>>& matrix) {
        bool col = true;
        int r = matrix.size(), c = matrix[0].size();
        for(int i=0; i<r; i++){
            // column 0 is governed by col variable 
            if(matrix[i][0] == 0) col = false; 
            for(int j=1; j<c; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            } 
        }
        for(int i = r-1; i>=0; i--){
            for(int j = c-1; j>=1; j--){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
            // column 0 is governed by col variable 
            if(col == false){
                matrix[i][0] = 0;
            }
        }
    }