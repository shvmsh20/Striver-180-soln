//Better
bool isSafe(int row, int col, vector<string> &board, int n){
        int duprow = row, dupcol = col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        
        return true;
    }
    void util(int col, vector<string> &board, vector<vector<string>> &res, int n){
        //base condn
        if(col==n){
            res.push_back(board);
        }
            
        for(int i=0; i<n; i++){
            if(isSafe(i, col, board, n)){
                board[i][col] = 'Q';
                util(col+1, board, res, n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        util(0, board, res, n);
        return res;
    }

//Optimal using hash
void util(int col, vector<string> &board, vector<vector<string>> &res, vector<int>              &leftRow, vector<int> &lowerDiag, vector<int> &upperDiag, int n){
        //base condn
        if(col==n){
            res.push_back(board);
        }
            
        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && lowerDiag[row+col]==0 && upperDiag[n-1+col-row]==0){
                leftRow[row]=1;
                lowerDiag[row+col]=1 ;
                upperDiag[n-1+col-row]=1;
                board[row][col] = 'Q';
                util(col+1, board, res, leftRow, lowerDiag, upperDiag, n);
                board[row][col] = '.';
                leftRow[row]=0;
                lowerDiag[row+col]=0;
                upperDiag[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int> leftRow(n, 0), lowerDiag(2*n-1, 0), upperDiag(2*n-1, 0);
        util(0, board, res, leftRow, lowerDiag, upperDiag, n);
        return res;
    }
 