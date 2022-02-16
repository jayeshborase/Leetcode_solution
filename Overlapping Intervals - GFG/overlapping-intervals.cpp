// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
  static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        //  if(intervals.size() == 1){
        //      //intervals[0][1]++;
        //      return intervals;
        //  }
         sort(intervals.begin(),intervals.end());
         vector<vector<int>> ans;
         for(int i = 0; i < intervals.size(); i++){
             int first = intervals[i][0];
             int second = intervals[i][1];
             while(i < intervals.size()-1 && second >= intervals[i+1][0]){
                 second = max(second,intervals[i+1][1]);
                 //cout << second << " ";
                 i++;
             }
             ans.push_back({first,second});
             
         }
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends