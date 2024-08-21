class Solution {
public:
     bool checkPalindrome(int i,int j,string s)
     {
         while(i<=j)
         {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
         }
        return true; 
     }
     void givePalindrome(int index,string s,vector<vector<string>>&sol,vector<string>temp)
     {
        if(index==s.length())
        {  
            sol.push_back(temp);
           
           return;
        }
        for(int i=index;i<s.length();i++)
        {
            if(checkPalindrome(index,i,s))
            {  
                string s1=s.substr(index,i-index+1);
                temp.push_back(s1);
                givePalindrome(i+1,s,sol,temp);
                temp.pop_back();
            }
        }

     }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>sol;
        vector<string>temp;
       givePalindrome(0,s,sol,temp);
       return sol;
    }
};