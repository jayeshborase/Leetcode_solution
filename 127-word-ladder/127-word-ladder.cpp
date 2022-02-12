class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        set<string> s;
        
        for(auto i : wordList){
            s.insert(i);
        }
        
        q.push(beginWord);
        
        int changes = 1;
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0; i < sz; i++){
                string word = q.front();
                q.pop();
                
                if(word == endWord)
                    return changes;
                
                for(int j = 0; j < word.size(); j++){
                    string arr= word;
                    for(int m ='a'; m <= 'z'; m++){
                        arr[j] = (char) m;
                        if(s.find(arr) != s.end()){
                            q.push(arr);
                            s.erase(arr);
                        }
                    }
                }
            }
            changes++;
        }
        return 0;
    }
};