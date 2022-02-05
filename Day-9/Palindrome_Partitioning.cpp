//  T/C: O( (2^n) *k*(n/2) ), S/C: O(k * x)
bool isPalindrome(string &s, int l, int h){
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    
    void util(string &s, int ind, vector<string> &v, vector<vector<string>> &res){
        if(ind==s.size()){
            res.push_back(v);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                v.push_back(s.substr(ind, i-ind+1));
                util(s, i+1, v, res);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        util(s, 0, v, res);
        return res;
    }