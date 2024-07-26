class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int first=-1;
        int count=0;
       
        string ans="";
        for(int i=0;i<n;i++)
         {
            if(s[i]=='(')
            {
               if(first==-1)
               {
                first=i;
               }
               count++;
            }
            if(s[i]==')')
            {
                count--;
            }
            if(count==0)
            {
                 ans+=s.substr(first+1,i-first-1);
                first=-1;
            }
         }
  return ans;
    }
};