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