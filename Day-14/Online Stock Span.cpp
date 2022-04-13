//Like next greater on left
//Implementation-1 
stack<pair<int, int>> st;
    int t;
    StockSpanner() {
        t=0;
    }
    
    int next(int price) {
        t++;
        if(st.empty()){
            st.push({price, t});
            return 1;
        }else{
            int ans;
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            if(st.empty()){
                ans = t;
            }else{
                ans = t-st.top().second;
            }
            st.push({price, t});
            return ans;
        }
    }

//Implementation-2
stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int d=1;
        while(!st.empty() && st.top().first<=price){
            d+= st.top().second;
            st.pop();
        }
        st.push({price, d});
        return d;
    }    