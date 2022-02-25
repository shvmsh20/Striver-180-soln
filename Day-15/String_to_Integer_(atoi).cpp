int myAtoi(string s) {
        bool neg = false;
        int n = s.size();
        int i=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            neg = true;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        int ans=0;
        while(i<n){
            int temp = s[i]-'0';
            if((temp>=0 && temp<=9)==false){
                return ans;
            }
            if(ans>INT_MAX/10){
                
                return INT_MAX;
            }
            ans = ans*10 + temp;
            i++;
        }
        if(neg){
            ans = ans*-1;
        }
        return ans;
    }