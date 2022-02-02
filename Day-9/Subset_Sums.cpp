// T/C: O(pow(2,n)*log(pow(2,n))), S/C: O(pow(2,n))
void util(vector<int> arr, int i, int N, vector<int> &res, int sum){
        if(i==N){
            res.push_back(sum);
            return;
        }
        util(arr, i+1, N, res, sum);
        util(arr, i+1, N, res, sum+arr[i]);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        util(arr, 0, N, res, 0);
        sort(res.begin(), res.end());
        return res;
    }