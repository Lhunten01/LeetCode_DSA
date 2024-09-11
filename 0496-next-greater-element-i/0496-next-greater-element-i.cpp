class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        st.push(-1);
        int n=nums2.size();
        int m=nums1.size();
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--)
        {
            int x=nums2[i];
            while(st.top()!=-1&&st.top()<x)
            {
              st.pop();
            }
            mp[x]=st.top();
            st.push(x);
        }


        for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;

        for(int i=0;i<m;i++)
        {
          nums1[i]=mp[nums1[i]];
        }
        return nums1;
    }
};