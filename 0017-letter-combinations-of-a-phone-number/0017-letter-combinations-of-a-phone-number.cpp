class Solution {
public:
      void findCombination(int index,string digits,unordered_map<int,string>&mp,vector<string>&ans,string &s)
      { if(index==digits.size())
        {  
            ans.push_back(s);
            return;
        }
            int x=digits[index]-'0';
            for(int j=0;j<mp[x].size();j++)
            {
               s.push_back(mp[x][j]);
               findCombination(index+1,digits,mp,ans,s);
               s.pop_back();
            }
      }
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0)
        return {};
        unordered_map<int,string>mp;
         mp[1]=""; mp[2]="abc"; mp[3]="def"; mp[4]="ghi";  mp[5]="jkl"; mp[6]="mno"; mp[7]="pqrs"; mp[8]="tuv"; mp[9]="wxyz";
         vector<string>ans;
         string s="";
         findCombination(0,digits,mp,ans,s);
         return ans;
    }
};