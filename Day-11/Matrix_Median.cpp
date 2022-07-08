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

int Solution::findMedian(vector<vector<int> > &A) {
    int l=INT_MAX, h = INT_MIN;
    int n = A.size(), m = A[0].size();
    for(int i=0; i<n; i++){
        l = min(l, A[i][0]);
        h = max(h, A[i][m-1]);
    }
    int desired = (n*m+1)/2;
    while(l<h){
        int place=0;
        int mid = l+(h-l)/2;
        for(int i=0; i<n; i++){
            place+= upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(place<desired){
            l = mid+1;
        }else{
            h = mid;
        }
    }
    return l;
}
