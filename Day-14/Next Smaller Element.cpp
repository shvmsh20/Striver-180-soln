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