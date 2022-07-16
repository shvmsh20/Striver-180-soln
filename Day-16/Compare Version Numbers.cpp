int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i=0, j=0;
        while(i<n && j<m){
            string r1="";
            while(i<n && version1[i]!='.'){
                r1 = r1+version1[i];
                i++;
            }
            i++;
            int t1 = stoi(r1);
            
            string r2="";
            while(j<m && version2[j]!='.'){
                r2 = r2+version2[j];
                j++;
            }
            j++;
            int t2 = stoi(r2);
            cout << t1 << " " << t2 << endl;
            if(t1<t2){
                return -1;
            }else if(t1>t2){
                return 1;
            }else{
                continue;
            }
        }
        while(i<n){
            string r1="";
            while(i<n && version1[i]!='.'){
                r1 = r1+version1[i];
                i++;
            }
            i++;
            int t1 = stoi(r1);
            int t2 = 0;
            cout << t1 << " " << t2 << endl;
            if(t1<t2){
                return -1;
            }else if(t1>t2){
                return 1;
            }
        }
        while(j<m){
            string r2="";
            while(j<m && version2[j]!='.'){
                r2 = r2+version2[j];
                j++;
            }
            j++;
            int t1 = 0;
            int t2 = stoi(r2);
            cout << t1 << " " << t2 << endl;
            if(t1<t2){
                return -1;
            }else if(t1>t2){
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