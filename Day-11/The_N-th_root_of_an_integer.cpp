//T/C: O(n*log2(m*(10^d)))
double util(double a, int n){
    double res=1.00;
    for(int i=0; i<n; i++){
        res = res*a;
    }
    return res;
}
double findNthRootOfM(int n, long long m) {
    double l=1.00, h=(double)m;
    double chck = (double)m;
    while(h-l>=1e-7){
        double mid = (l+h)/2.00;
        double power = util(mid, n);
        if(power>chck){
            h = mid;
        }else{
            l=mid;
        }
    }
    return l;
}