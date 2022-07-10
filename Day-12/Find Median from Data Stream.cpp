//T/C: O(nlogn)
int n;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        if(left.size()==0){
            left.push(num);
        }else if(left.size()==right.size()){
            if(num<=right.top()){
                left.push(num);
            }else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }else{
            if(num>=left.top()){
                right.push(num);
            }else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        n++;
        
    }
    
    double findMedian() {
        if(n&1){
            return (double)left.top();
        }else{
            return (double)(left.top()+right.top())/2.00;
        }
    }