//T/C: O(3n) S/C: O(3n)
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int rightSmaller[n];
        rightSmaller[n-1] = n-1;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightSmaller[i] = n-1;
            }else{
                rightSmaller[i] = st.top()-1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(0);
        int leftSmaller[n];
        leftSmaller[0] = 0;
        for(int i=1; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftSmaller[i] = 0;
            }else{
                leftSmaller[i] = st.top()+1;
            }
            st.push(i);
        }
        int res=0, curr=0;
        for(int i=0; i<n; i++){
            curr = (rightSmaller[i]-leftSmaller[i]+1)*heights[i];
            res = max(res, curr);
            cout << leftSmaller[i] << " " << rightSmaller[i] << " "<< curr << endl;
        }
        return res;
    }

//T/C: O(2n) S/C: O(n) 
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res=0;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int index = st.top();
                st.pop();
                int leftBoundry = st.empty()?-1:st.top();
                int rightBoundry = i;
                int curr = (rightBoundry-leftBoundry-1)*heights[index];
                res = max(res, curr);
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top();
            st.pop();
            int rightBoundry = n;
            int leftBoundry = st.empty()?-1:st.top();
            int curr = (rightBoundry - leftBoundry-1)*heights[index];
            res = max(res, curr);
        }
        return res;
    }