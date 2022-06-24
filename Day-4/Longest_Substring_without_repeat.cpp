// Optimal
int lengthOfLongestSubstring(string str) {
        unordered_set<char> s;
        int i=0, j=0, n=str.size();
        int res=0;
        while(j<n){
            if(s.find(str[j])==s.end()){
                res = max(res, j-i+1);
                s.insert(str[j]);
                j++;
            }else{
                while(i<j && s.find(str[j])!=s.end()){
                    s.erase(str[i]);
                    i++;
                }
            }
        }
        return res;
    }
    //OR
int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l=0, r=0, mx=0, curr=0;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                curr++;
                mx = max(curr, mx);
                st.insert(s[r]);
                r++;
            }else{
                while(st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                    curr--;
                }
            }
        }
        return mx;
    }

// Best
int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0, r=0, mx=0, curr=0;
        while(r<s.size()){
            if((mp.count(s[r])==0) || (mp.count(s[r]) && l>mp[s[r]])){
                curr = r-l+1;
                mx = max(curr, mx);
                mp[s[r]] = r;
                r++;
            }else{
                l = mp[s[r]]+1;
            }
           
        }
        return mx;
    }
