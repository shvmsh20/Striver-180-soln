int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    int xr=0, res=0;
    for(int i=0; i<A.size(); i++){
        xr = xr^A[i];
        if(xr==B){
            res++;
        }
        int y=xr^B;
        if(mp.count(y)){
            res+=mp[y];
        }
        mp[xr]++;
    }
    return res;
}
