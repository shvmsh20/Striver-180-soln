struct Node{
    Node* child[26];
    Node(){
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
};

void buildTrie(int start, int n, string &s, Node* root, int &count){
    Node* curr = root;
    for(int i=start; i<n; i++){
        int index = s[i]-'a';
        if(curr->child[index]==nullptr){
            curr->child[index] = new Node();
            count++;
        }
        curr = curr->child[index];
    }
}
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int n = s.length();
    int count=0;
    Node *root = new Node();
    for(int i=0; i<n; i++){
        buildTrie(i, n, s, root, count);
    }
    return count+1;
}