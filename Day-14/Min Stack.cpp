// T/C: O(n), S/C: O(2n)
class MinStack {
public:
    stack<pair<int, int> > st;
    MinStack() {
       
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(make_pair(val, val));
        }else{
            int t = st.top().second;
            t = min(t, val);
            st.push(make_pair(val, t));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

//T/C: O(n), S/C: O(n)
class MinStack {
public:
    stack<long long> st;
    long long  mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        }else if(val>=mini){
            st.push(val);
        }else if(val<mini){
            long long m_val = (long long)2*val - mini;
            st.push(m_val);
            mini = val;
        }
    }
    
    void pop() {
        if(st.top()<mini){
            mini = 2*mini - st.top();
            st.pop();
        }else{
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<mini){
            return mini;
        }else{
            return st.top();
        }
    }
    
    int getMin() {
        return mini;
    }
};