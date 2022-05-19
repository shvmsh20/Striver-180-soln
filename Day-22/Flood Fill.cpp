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