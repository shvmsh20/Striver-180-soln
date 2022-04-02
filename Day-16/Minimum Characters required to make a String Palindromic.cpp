int Solution::solve(string A) {
    string s = A;
    s.push_back('$');
    reverse(A.begin(), A.end());
    s.insert(s.end(), A.begin(), A.end());
    int lps[s.size()];
    lps[0]=0;
    int i=1, j=0;
    while(i<s.size()){
        if(s[i]==s[j]){
            j++;
            lps[i]=j;
            i++;
        }else {
            if(j==0){
                lps[i]=0;
                i++;
            }else{
                j = lps[j-1];
            }
        }
    }
    return A.size()-lps[s.size()-1];
}