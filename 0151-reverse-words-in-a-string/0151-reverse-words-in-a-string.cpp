class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int first=-1;
        string ans="";
          for(int i=n-1;i>=0;i--)
          {
              if(s[i] !=' ')
              {
                if(first==-1)
                 first=i;
              }
              else
              { if(first!=-1)
                 {  if(!ans.empty()) ans += " ";
                    ans+=s.substr(i+1,first-i);
                    first=-1;
                 }
              }
          }
          if(first!=-1)
                 {  if(!ans.empty()) ans += " ";
                    ans+=s.substr(0,first+1);
                    first=-1;
                 }
          return ans;
    }
};