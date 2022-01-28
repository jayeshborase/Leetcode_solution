class WordDictionary {
public:
    vector<vector<string>> v;
    WordDictionary() {
        v.resize(501);
    }
    
    void addWord(string word) {
        v[word.length()].push_back(word);
    }
    
    bool search(string word) {
        int flg = 0;
        
        for(int i = 0; i < v[word.length()].size(); i++){
            for(int j = 0; j < word.length(); j++){
                if(word[j] == '.')
                    continue;
                if(word[j] != v[word.length()][i][j]){
                    flg = 1;
                    break;
                }
            }
            if(flg == 0)
                return 1;
            flg = 0;
        }
        
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */