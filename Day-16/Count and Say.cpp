//M-1 
string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s = countAndSay(n-1);
        string res="";
        int m = s.size();
        int count=1;
        for(int i=0; i<m-1; i++){
            if(s[i]==s[i+1]){
                count++;
            }else{
                res = res + to_string(count) + s[i];
                count=1;
            }
        }
        
            res = res + to_string(count) + s[m-1];
        
        return res;
    }

//M-2
string countAndSay(int n) {
        string s="1";
        for(int i=2; i<=n; i++){
            string temp="";
            s = s + '$';
            int count=1;
            for(int j=1; j<=s.size()-1; j++){
                if(s[j]==s[j-1]){
                    count++;
                }else{
                    temp = temp + to_string(count) + s[j-1];
                    count=1;
                }
            }
            s = temp;
        }
        return s;
    }    