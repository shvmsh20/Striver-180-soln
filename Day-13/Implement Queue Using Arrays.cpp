vector<int> v(100);
    int front;
    int rear;
    int size;
    Queue() {
        // Implement the Constructor
        size=0;
        front=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        
        if(size==0){
            return true;
        }else {
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        v[(rear+1)%100] = data;
        rear = rear++;
        size++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(size==0) retun -1;
        int temp = v[front%100];
        front = front--;
        size--;
        return temp;
        
    }

    int front() {
        // Implement the front() function
        if(size==0) return -1;
        return v[front];
    }