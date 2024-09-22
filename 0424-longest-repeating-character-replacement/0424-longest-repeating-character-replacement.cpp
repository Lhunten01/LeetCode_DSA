class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int n=s.length();
        int maxcount=0;
        int ans=0;
        while(r<n)
        {  
           mp[s[r]]++;
           maxcount=max(maxcount,mp[s[r]]);
           if((r-l+1-maxcount)>k)
           {
            mp[s[l]]--;
            l++;
           }
            ans=max(r-l+1,ans);
            r++;
        }
        return ans;
    }
};