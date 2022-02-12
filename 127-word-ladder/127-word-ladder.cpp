class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        set<string> s;
        
        for(auto i : wordList){
            s.insert(i);
            //cout << i << " ";
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
                    for(int m ='a'; m <= 'z'; m++){
                        string arr = word;
                        arr[j] = (char) m;
                        //cout << arr << " ";
                        if(s.find(arr) != s.end()){
                            //cout << arr << " ";
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