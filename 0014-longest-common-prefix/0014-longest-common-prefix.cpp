class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          sort(strs.begin(),strs.end());
          int n=strs.size();
        string str=strs[0];
        for(int i=1;i<n;i++)
        { string s=strs[i];
            for(int j=0;j<str.size();j++)
            { 
                if(s[j]!=str[j])
                 {
                     str.resize(j);
                    break;
                 }
            }
        }
        return str;
    }
};