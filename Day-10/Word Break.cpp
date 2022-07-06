void solve(int ind, int n, string &s, unordered_map<string, int> &mp, 
           vector<string> &temp, vector<string> &res){
    if(ind==n){
        string ans="";
        for(int i=0; i<temp.size(); i++){
            if(i==temp.size()-1){
                ans+= temp[i];
            }else{
                ans+= temp[i]+' ';
            }
        }
        res.push_back(ans);
        return;
    }
    for(int i=ind; i<n; i++){
        if(mp.find(s.substr(ind, i-ind+1))!=mp.end()){
            temp.push_back(s.substr(ind, i-ind+1));
            solve(i+1, n, s, mp, temp, res);
            temp.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_map<string, int> mp;
    for(string x: dictionary){
        mp[x]++;
    }
    int n = s.size();
    vector<string> res;
    vector<string> temp;
    solve(0, n, s, mp, temp, res);
    return res;
}