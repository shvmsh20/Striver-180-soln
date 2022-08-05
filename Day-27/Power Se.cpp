vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.length();
		    vector<string> res;
		    for(int i=1; i<pow(2, n); i++){
		        string t;
		        for(int j=0; j<n; j++){
		            if(i&(1<<j)){
		                t.push_back(s[j]);
		            }
		        }
		        res.push_back(t);
		    }
		    sort(res.begin(), res.end());
		    return res;
		}