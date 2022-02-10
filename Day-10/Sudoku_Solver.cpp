//Better
bool isSafe(int row, int col, char x, int n, vector<vector<char>>& board){
        for(int i=0; i<n; i++){
            if(board[row][i]==x || board[i][col]==x) return false;
        }
        int sqt = sqrt(n);
        int startR = row-row%sqt;
        int startC = col-col%sqt;
        for(int i=0; i<sqt; i++){
            for(int j=0; j<sqt; j++){
                if(board[i+startR][j+startC]==x) return false;
            }
        }
        return true;
    }
    bool util(vector<vector<char>>& board, int n){
        int i, j, f;
        for(i=0; i<n; i++){
            f=0;
            for(j=0; j<n; j++){
                if(board[i][j]=='.'){
                    f=1;
                    break;
                }
            }
            if(f==1){
                break;
            }
            
        }
        if(i==n && j==n){
            return true;;
        }
        
        for(char x='1'; x<='9'; x++){
            if(isSafe(i, j, x, n, board)){
                board[i][j] = x;
                if(util(board, n)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        util(board, n);
    }

//Optimal
bool isSafe(int row, int col, char x, int n, vector<vector<char>>& board){
        int s = sqrt(n);
        for(int i=0; i<n; i++){
            if(board[row][i]==x) return false;
            if(board[i][col]==x) return false;
            if(board[(s*(row/s))+(i/s)][(s*(col/s))+(i%s)]==x) return false;
        }
        return true;
    }
    bool util(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='.'){
                    for(char x='1'; x<='9'; x++){
                        if(isSafe(i, j, x, n, board)){
                            board[i][j] = x;
                            if(util(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }   
        }
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board){
        util(board);
    }