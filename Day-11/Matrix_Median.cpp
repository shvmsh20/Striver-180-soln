//T/C: O(32*r*log(c)) 
int Solution::findMedian(vector<vector<int> > &A) {
    int start = 1, end = 1e5, mid;
    int r = A.size(), c = A[0].size(), n = r*c;
    while(start<=end){
        mid = start+(end-start)/2;
        int ans=0;
        for(int i=0; i<r; i++){
            int l = 0, h = c-1;
            int m = (l+h)/2;
            while(l<=h){
                if(A[i][m]<=mid){
                    l = m+1;
                }else{
                    h = m-1;
                }
            }
            ans+=l;
        }
        if(ans<=n/2){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return start;
}
