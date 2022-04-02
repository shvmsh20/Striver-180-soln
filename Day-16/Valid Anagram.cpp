//M-1
//T/C: O(nlogn)
bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return t==s;
    }

//M-2
//T/C: O(n)
bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n!=m) return false;
        vector<int> v(26);
        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(v[i]!=0){
                return false;
            }
        }
        return true;
    }    