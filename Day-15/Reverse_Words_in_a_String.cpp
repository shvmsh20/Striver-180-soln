//Sol1
//T/C: O(n), S/C:O(n) vector/stack used
string reverseWords(string s) {
        vector<string> v;
        string temp="";
        for(int i=0; i<s.size(); i++){
           if(s[i]!=' '){
               temp+=s[i];
           }else{
               if(temp!=""){
                   v.push_back(temp);
                   temp="";
               }
           }    
        }
        if(temp!=""){
            v.push_back(temp);
        }
        string ans="";
        int n = v.size();
        for(int i=n-1; i>=0; i--){
            ans = ans+ v[i];
            ans= ans+ (i==0?"":" ");
        }
        return ans;
    }


//Sol2
//T/C: O(n), S/C:O(1)only output string used
string reverseWords(string s) {
        string ans="", temp="";
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                ans = temp+ (ans.size()!=0?" ":"") +ans;
                temp=""; 
            }
        }
        if(temp!=""){
            ans = temp+ (ans.size()!=0?" ":"") +ans;
        }
        return ans;
    } 