int dequeue() {
        // Implement the dequeue() function
        if(sz==0){
            return -1;
        }
        int ans = q[frnt%n];
        frnt++;
        sz--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(sz==0){
            return -1;
        }
        return q[frnt%n];
    }
};