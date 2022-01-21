// T/C = O(logn)

//Using recursion
double util(double x, long long n){
        if(n==0){
            return 1;
        }
        if(n%2==0){
            double temp = util(x, n/2);
            return temp*temp;
        }else{
            return x*util(x, n-1);
        }
    }
    double myPow(double x, long long n) {
        if(n<0){
            n *=-1;
            return (1/util(x, n));
        }else{
            return util(x, n);
        }
    }

//Using loop
double myPow(double x, int n) {
        long int m = n;
        if(n<0) m = m*-1;
        double ans = 1.0;
        while(m>0){
            if(m%2==0){
                x = x*x;
                m = m/2;
            }else{
                ans = ans*x;
                m = m-1;
            }
        }
        if(n<0){
            return 1/ans;
        }else{
            return ans;
        }
    }    