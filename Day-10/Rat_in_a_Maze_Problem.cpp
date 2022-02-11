//T/C:O(4^(n*m)), S/C:O(m*n);

//M-1
bool isSafe(vector<vector<int>> &m, int i,int j, int n, vector<vector<int>> &vis){
        if(i>=0 && i<n && j>=0 && j<n && m[i][j]!=0 && vis[i][j]!=1){
            return true;
        }
        return false;
    }
    
    void solve(string s, vector<vector<int>> &m, int i, int j, int n, vector<string> &v, vector<vector<int>> &vis){
        if(i==n-1 && j==n-1 && m[i][j]==1){
            v.push_back(s);
            return;
        }
        if(isSafe(m, i, j, n, vis)){
            vis[i][j]=1;
            string s1 = s+'U';
            string s2 = s+'D';
            string s3 = s+'L';
            string s4 = s+'R';
            solve(s1, m, i-1, j, n, v, vis);
            solve(s2, m, i+1, j, n, v, vis);
            solve(s3, m, i, j-1, n, v, vis);
            solve(s4, m, i, j+1, n, v, vis);
            vis[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> v;
        vector<vector<int>> vis( n , vector<int> (n, 0));
        solve("", m, 0, 0, n, v, vis);
        sort(v.begin(), v.end());
        return v;
        
    }



//M-2
void solve(int r, int c, vector<vector<int>> &m, int n, string path, vector<vector<int>> &vis,
    vector<string> &ans){
        if(r==n-1 && c==n-1){
            ans.push_back(path);
            return;
        }
        
        //Down
        if(r+1<n && m[r+1][c]==1 && vis[r+1][c]==0){
            vis[r][c]=1;
            solve(r+1, c, m, n, path+'D', vis, ans);
            vis[r][c]=0;
        }
        
        //Left
        if(c-1>=0 && m[r][c-1]==1 && vis[r][c-1]==0){
            vis[r][c]=1;
            solve(r, c-1, m, n, path+'L', vis, ans);
            vis[r][c]=0;
        }
        
        //Up
        if(r-1>=0 && m[r-1][c]==1 && vis[r-1][c]==0){
            vis[r][c]=1;
            solve(r-1, c, m, n, path+'U', vis, ans);
            vis[r][c]=0;
        }
        
        //Right
        if(c+1<n && m[r][c+1]==1 && vis[r][c+1]==0){
            vis[r][c]=1;
            solve(r, c+1, m, n, path+'R', vis, ans);
            vis[r][c]=0;
        }
    }
    

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<string> ans;
        if(m[0][0]==1){
            solve(0, 0, m, n, "", vis, ans);
        }
        return ans;
    }





//M-3
void solve(int r, int c, vector<vector<int>> &m, int n, string path, vector<vector<int>> &vis,
    vector<string> &ans, int dr[], int dc[]){
        if(r==n-1 && c==n-1){
            ans.push_back(path);
            return;
        }
        string dir="DLRU";
        for(int i=0; i<4; i++){
            int nextr = r+dr[i];
            int nextc = c+dc[i];
            if(nextr>=0 && nextr<n && nextc>=0 && nextc<n && m[nextr][nextc]==1 && vis[nextr][nextc]==0){
                vis[r][c]=1;
                solve(nextr, nextc, m, n, path+dir[i], vis, ans, dr, dc);
                vis[r][c]=0;
            }
           
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<string> ans;
        int dr[]={1,0,0,-1};
        int dc[]={0,-1,1,0};
        if(m[0][0]==1){
            solve(0, 0, m, n, "", vis, ans, dr, dc);
        }
        return ans;
    }