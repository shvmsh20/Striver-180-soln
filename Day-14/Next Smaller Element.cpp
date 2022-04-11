//Next Greater 1
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> v(n);
    v[0]=-1;
    st.push(A[0]);
    for(int i=1; i<n; i++){
        if(A[i]>st.top()){
            v[i] = st.top();
        }else{
            while(!st.empty() && st.top()>=A[i]){
                st.pop();
            }
            if(st.empty()){
                v[i]=-1;
            }else{
                v[i] = st.top();
            }
        }
        st.push(A[i]);
    }
    return v;

}

//Next Greater Element II
vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){
            st.push(nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }else{
                res[i] = st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }