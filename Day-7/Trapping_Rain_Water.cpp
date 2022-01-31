// T/C: O(n), S/C: O(n)
int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n); 
        vector<int> right_max(n);
        
        //calculate left bar height to trap water
        int curr_max = INT_MIN;
        for(int i=0; i<n; i++){
            curr_max = max(curr_max, height[i]);
            left_max[i] = curr_max;
        }
        
        //calculate right bar height to trap water
        curr_max = INT_MIN;
        for(int i=n-1; i>=0; i--){
            curr_max = max(curr_max, height[i]);
            right_max[i] = curr_max;
        }
        
        //calculate trapped water
        int res=0;
        for(int i=1; i<n-1; i++){
            res+= min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
//T/C: O(n), S/C:(1)
int trap(vector<int>& height) {
        int n = height.size();
        int l_max=0, r_max=0, l = 0, r = n-1, res=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=l_max){
                    l_max = height[l];
                }else{
                    res+= l_max - height[l];
                }
                l++;
            }else{
                if(height[r]>=r_max){
                    r_max = height[r];
                }else{
                    res+= r_max - height[r];
                }
                r--;
            }
        }
        return res;
    }    