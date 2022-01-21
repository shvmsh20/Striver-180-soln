//Soln-1
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr^A[i];
        xr = (xr^(i+1));
    }
    int lastSetBit = (xr & ~(xr-1));
    int x = 0, y = 0;
    for(int i=0; i<n; i++){
        if(A[i] & lastSetBit){
            x = x^A[i];
        }else{
            y = y^A[i];
        }
    }
    for(int i=1; i<=n; i++){
        if(lastSetBit & i){
            x = x^i;
        }else{
            y = y^i;
        }
    }
    int i;
    vector<int> v(2);
    for(i=0; i<n; i++){
        if(A[i]==x){
            break;
        }
    }
    if(i!=n){
        v[0] = x;
        v[1] = y;
    }else{
        v[0] = y;
        v[1] = x;
    }
}

//Soln-2
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector <int> v(2);
    long long sum = 0, sq_sum=0 ;
    for(int i=0; i<n; i++){
        sum+= A[i];
        sq_sum+= (A[i]*A[i]);
    }
    long long total_sum = n*(n+1)/2;
    long long total_sq_sum = n*(n+1)*(2*n+1)/6;
    long long p = total_sum - sum;
    long long q = total_sq_sum - sq_sum;
    int mis_no = (q/p+p)/2;
    int rep_no = mis_no - p;
    v[0] = rep_no;
    v[1] = mis_no;
    return v;
}
