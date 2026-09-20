class TN{
public:
    TN* children[26];
    bool isEnd;
    TN(){
        for (int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class PrefixTree {
public:
    TN* root;
    PrefixTree() {
        root = new TN();
    }
    
    void ins(TN* node, string word){
        
        
    }

    void insert(string word) {
        TN* curr = root;

        for (char c: word){
            int i = c-'a';

            if (curr->children[i] == nullptr){
                curr->children[i] = new TN();
            }
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TN* curr =  root;

        for (char c: word){
            int i = c-'a';

            if (curr->children[i] == nullptr) return false;
            curr = curr->children[i];
        }

        return curr->isEnd;
    }
   
    bool startsWith(string prefix) {
        TN* curr =  root;

        for (char c: prefix){
            int i = c-'a';

            if (curr->children[i] == nullptr) return false;
            curr = curr->children[i];
        }

        return true;
    }
};
