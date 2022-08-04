struct Node{
    int ew;
    int cp;
    Node* child[26];
    Node(){
        ew=0;
        cp=0;
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
};

void buildTrie(Node* root, string &s){
    Node* curr = root;
    for(char x: s){
        int index = x-'a';
        if(curr->child[index]==nullptr){
            curr->child[index] = new Node();
        }
        curr = curr->child[index];
        curr->cp++;
    }
    curr->ew++;
}
void solve(Node* root, string &temp, string &res){
    if(temp.size()>res.size()){
        res = temp;
    }
    for(int i=0; i<26; i++){
        if(root->child[i]!=nullptr && root->child[i]->ew!=0){
            temp.push_back('a'+i);
            solve(root->child[i], temp, res);
            temp.pop_back();
        }
    }
}
string completeString(int n, vector<string> &a){
    // Write your code here.
    Node* root = new Node();
    for(auto x: a){
        buildTrie(root, x);
    }
    string res="";
    string temp="";
    solve(root, temp, res);
    if(res==""){
        return "None";
    }else{
        return res;
    }
}