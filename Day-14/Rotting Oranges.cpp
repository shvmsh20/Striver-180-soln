int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool fresh=false;
        vector<int> xs = {-1, 0, 1, 0};
        vector<int> ys = {0, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i, j));
                }else if(grid[i][j]==1){
                    fresh = true;
                }
            }
        }
       if(fresh==false){
           return 0;
       }
        cout << q.size();
        int t=0;
        while(!q.empty()){
            int size = q.size();
            t++;
            for(int j=0; j<size; j++){
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(int i=0; i<=3; i++){
                    if((x+xs[i]>=0 && x+xs[i]<n && y+ys[i]>=0 && y+ys[i]<m) &&
                      grid[x+xs[i]][y+ys[i]]==1){
                        q.push(make_pair(x+xs[i], y+ys[i]));
                        grid[x+xs[i]][y+ys[i]]=2;
                    }
                }
            }
            
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return t-1;
    }

    //OR
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        int time=0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0}; 
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int nx = dx[j]+x;
                    int ny = dy[j]+y;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            if(!q.empty()){
                time++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }