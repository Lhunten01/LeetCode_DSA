class Solution {
public:
   void combination(string& digit,int index,string mapping[],vector<string>& ans,string intake)
    {
    if(index>=digit.length())
    {
        ans.push_back(intake);
        return;
    }
       int number=digit[index]-'0';
       string value=mapping[number];
       for(int i=0;i<value.length();i++)
       {
           intake.push_back(value[i]);
           combination(digit,index+1,mapping,ans,intake);
           intake.pop_back();
        }
     }
    vector<string> letterCombinations(string digits) {
       string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        int index=0;
        string intake="";
        if(digits.length()==0)
            return ans;
        combination(digits,index,mapping,ans,intake);
        return ans;
        
    }
};