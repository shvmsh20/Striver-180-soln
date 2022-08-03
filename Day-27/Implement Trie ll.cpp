struct Node{
    int cp;
    int ew;
    Node* child[26];
    Node(){
        cp=0;
        ew=0;
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
};
class Trie{

    public:
    Node* root;
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new Node();
            }
            curr = curr->child[index];
            curr->cp++;
        }
        curr->ew++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                return 0;
            }
            curr = curr->child[index];
        }
       return curr->ew;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                return 0;
            }
            curr = curr->child[index];
        }
        return curr->cp;
    }

    void erase(string &word){
        // Write your code here.
        Node* curr = root;
        for(char x: word){
            int index = x-'a';
            if(curr->child[index]==nullptr){
                return;
            }
            curr = curr->child[index];
            curr->cp--;
        }
        curr->ew--;
        
    }
};