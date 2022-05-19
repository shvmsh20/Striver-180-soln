priority_queue <int, vector<int>, greater<int> > minhp;
    priority_queue <int> maxhp;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxhp.size()==0){
            maxhp.push(num);
        }else if(maxhp.size()==minhp.size()){
            if(num<minhp.top()){
                maxhp.push(num);
            }else{
                int t = minhp.top();
                minhp.pop();
                maxhp.push(t);
                minhp.push(num);
            }
        }else{
            if(minhp.size()==0){
                if(num>maxhp.top()){
                    minhp.push(num);
                }else{
                    int t = maxhp.top();
                    maxhp.pop();
                    minhp.push(t);
                    maxhp.push(num);                    
                }
            }else{
                if(num>maxhp.top()){
                    minhp.push(num);
                }else{
                    int t = maxhp.top();
                    maxhp.pop();
                    minhp.push(t);
                    maxhp.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        double res;
        if(maxhp.size()==minhp.size()){
            res = 1.0*(maxhp.top()+minhp.top())/2;
        }else{
            res = (double) maxhp.top();
        }
        return res;
    }