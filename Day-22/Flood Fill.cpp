//T/C: O(n*m)
//S/C: O(1)
int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, -0};
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor){
        if(image[x][y]==color){
            image[x][y]=newColor;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size()){
                    dfs(image, nx, ny, color, newColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color!=newColor){
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }

//BFS
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        q.push(make_pair(sr, sc));
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, -0};
        while(!q.empty()){
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            image[x][y] = -1;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==color){
                    q.push(make_pair(nx, ny));
                }
            }  
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(image[i][j]==-1){
                    image[i][j]=newColor;
                }
            }
        }
        return image;
    }    