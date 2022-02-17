//T/C: O(n*log(sum-min))
bool isPossible(vector<int> &A, int mid, int B){
    int count=1, sum=0;
        for(int i=0; i<A.size(); i++){
            if(A[i]>mid)  return false;
            if(sum+A[i]>mid){
                count++;
                sum = A[i];
            }else{
                sum+=A[i];
            }
        }
        if(count>B){
            return false;
        }else{
            return true;
        }
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(B>n) return -1;
    int l=INT_MAX, h=0, res=-1;
    for(int i=0; i<n; i++){
        l = min(l, A[i]);
        h += A[i] ;
    }
    while(l<=h){
        int mid = (l+h)/2;
        if(isPossible(A, mid, B)){
            res = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return res;
}