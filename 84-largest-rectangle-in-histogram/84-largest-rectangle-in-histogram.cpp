class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        int max_ele = INT_MIN;
        vector<int> left, right;

        stack<pair<int,int>> l,r;

        for (int i = 0; i < n; i++)
        {
            if (l.empty())
            {
                left.emplace_back(-1);
                l.push({i,a[i]});
                continue;
            }

            while (!l.empty() && l.top().second >= a[i])
            {
                l.pop();
            }

            if (!l.empty())
            {
                left.emplace_back(l.top().first);
            }else
                left.emplace_back(-1);

            l.push({i,a[i]});  
        }

        for (int i = n-1; i >=0; i--)
        {
            if (r.empty())
            {
                right.emplace_back(n);
                r.push({i,a[i]});
                continue;
            }

            while (!r.empty() && r.top().second >= a[i])
            {
                r.pop();
            }

            if (!r.empty())
            {
                right.emplace_back(r.top().first);
            }else
                right.emplace_back(n);

            r.push({i,a[i]});  
        }
        reverse(right.begin(),right.end());


        for (int i = 0; i < n; i++)
        {
            int ans = (right[i] - (left[i] + 1)) * a[i];
            if(max_ele < ans)
                max_ele = ans;
        }

        return max_ele;
    }
};