//T/C:O(n^2), S/C:O(n)
string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;
        for(int i=1; i<n; i++){
            fact = fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k-1;
        string res="";
        while(true){
            res = res+ to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k = k%fact;
            fact = fact/nums.size();
        }
        return res;
    }