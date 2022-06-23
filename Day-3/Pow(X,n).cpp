// T/C = O(logn)

//Using recursion

double solve(double x, int n){
        if(n==0){
            return 1;
        }else if(n==1){
            return x;
        }else if(n%2==0){
            double t = solve(x, n/2);
            return t*t;
        }else{
            return x*solve(x, n-1);
        }
    }
    double myPow(double x, int n) {
        if(n<0){
            //handling special case when n = INT_MIN, so it cannot be converted into 
            //positive integer
            if(n==INT_MIN){
                return 1/(solve(x, INT_MAX)*x);
            }
            else{
                n = abs(n);
                return 1/solve(x, n);
            }
        }else{
            return solve(x, n);
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