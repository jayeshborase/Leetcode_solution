class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    
    vector<int> ans;
    queue<int> q {{1,2,3,4,5,6,7,8,9}};
    
    while(!q.empty())
    {
        int curr=q.front();     q.pop();
        if(curr>high) 
            break;        //reached upperlimit
        if(curr>=low && curr<=high)
            ans.push_back(curr);
        
        int num = curr%10;
        int next = curr*10 + (num+1);
        
        if(num<9)        //if curr=89, num=9, next=890+9+1=900 - test case failed at this condition, i.e. to avoid getting 900, etc.
            q.push(next);           //1234 -> 12345, if curr=1234, next=12345 pushed to queue
    }
    return ans;        
}
};