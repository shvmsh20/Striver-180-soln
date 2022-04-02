void fillLps(string p, vector<int> &lps){
    lps[0]=0;
    int len=0, i=1;
    while(i<p.size()){
        if(p[i]==p[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len==0){
                lps[i]=0;
                i++;
            }else{
                len = lps[len-1];
            }
        }
    }
}
bool findPattern(string p, string s)
{
    int n = s.length(), m = p.length();
    vector<int> lps(m);
    fillLps(p, lps);
    int i=0, j=0;
    vector<int> res;
    while(i<n){
        if(s[i]==p[j]){
            i++;
            j++;
        }
        if(j==m){
            res.push_back(i-j);
            j=lps[j-1];
        }else if(i<n && s[i]!=p[j]){
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    return !res.empty();
}