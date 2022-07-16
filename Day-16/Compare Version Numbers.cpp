int compareVersion(string v1, string v2) {
        int n = v1.length(), i=0;
        int m = v2.length(), j=0;
        while(i<n || j<m){
            int n1=0, n2=0;
            while(i<n && v1[i]!='.'){
                n1 = n1*10 + (v1[i]-'0');
                i++;
            }
            while(j<m && v2[j]!='.'){
                n2 = n2*10 + (v2[j]-'0');
                j++;
            }
            i++;
            j++;
            if(n1<n2){
                return -1;
            }else if(n1>n2){
                return 1;
            }
        }
        return 0;
    }
    //OR
    int compareVersion(string v1, string v2) {
        int n = v1.length(), i=0;
        int m = v2.length(), j=0;
        while(i<n || j<m){
            string rev1="", rev2="";
            while(i<n && v1[i]!='.' && v1[i]=='0'){
                i++;
            }
            if(i<n){
                if(v1[i]=='.'){
                    rev1="0";
                }else{
                    while(i<n && v1[i]!='.'){
                        rev1+= v1[i];
                        i++;
                    }
                }
                i++;
            }else{
                rev1='0';
            }
            
            
            while(j<m && v2[j]!='.' && v2[j]=='0'){
                j++;
            }
            if(j<m){
                if(v2[j]=='.'){
                    rev2="0";
                }else{
                    while(j<m && v2[j]!='.'){
                        rev2+= v2[j];
                        j++;
                    }
                }
                j++;
            }else{
                rev2='0';
            }
            
            if(stoi(rev1)<stoi(rev2)){
                return -1;
            }else if(stoi(rev1)>stoi(rev2)){
                return 1;
            }
            
        }
        return 0;
    }