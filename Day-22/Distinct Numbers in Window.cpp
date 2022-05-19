vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> res;
    int n = A.size();
    if(B>n) return res;
    unordered_map<int, int> mp;
    for(int i=0; i<B; i++){
        mp[A[i]]++;
    }
    res.push_back(mp.size());
    for(int i=B; i<n; i++){
        mp[A[i-B]]--;
        if(mp[A[i-B]]==0){
            mp.erase(A[i-B]);
        }
        mp[A[i]]++;
        res.push_back(mp.size());
    }
    return res;
}