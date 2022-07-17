vector<int> zFun(string &s){
    int n = s.size();
    vector<int> z(n);
    z[0]=0;
    int l=0, r=0;
    for(int k=1; k<n; k++){
        if(k>r){
            l=k;
            r=k;
            while(r<n && s[r]==s[r-l]){
                r++;
            }
            z[k] = r-l;
            r--;
        }else{
            int k1 = k-l;
            if(k+z[k1]<=r){
                z[k] = z[k1];
            }else{
                l=k;
                while(r<n && s[r]==s[r-l]){
                    r++;
                }
                z[k]=r-l;
                r--;
            }
        }
    }
    return z;
}
int zAlgorithm(string s, string p, int n, int m)
{
	
    string tot = p;
    tot.push_back('$');
    for(int i=0; i<n; i++){
        tot.push_back(s[i]);
    }
    vector<int> z = zFun(tot);
    int count=0;
    for(int i=0; i<z.size(); i++){
        if(z[i]==m){
            count++;
        }
    }
    return count;
}