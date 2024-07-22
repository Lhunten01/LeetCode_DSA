class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int,int>>st;
        sort(intervals.begin(), intervals.end());
        st.push({intervals[0][0],intervals[0][1]});
        vector<vector<int>>ans;
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            int x=intervals[i][0];
            int y=intervals[i][1];
            pair<int,int>p=st.top();
            int low=p.first;
            int high=p.second;
           
            if(x<=high)
            {  st.pop();
               st.push({low,max(y,high)});  
            }
            else
           {
            st.push({x,y});
           }
        }
        while(!st.empty())
        {
           auto it=st.top();
           vector<int>sol;
           sol={it.first,it.second};
           ans.push_back(sol);
           st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};