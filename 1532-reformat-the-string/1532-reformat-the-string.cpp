class Solution {
public:
    string reformat(string s) {
        string digits="";
        string letters="";
         if(s.length()==1)
         return s;

       for(int i=0;i<s.length();i++) 
       {
        if(isdigit(s[i]))
        {
           digits.push_back(s[i]);
        }
        else
        letters.push_back(s[i]);
       }
       if(digits.length()!=letters.length())
      { if(digits.length()+1!=letters.length()&&letters.length()+1!=digits.length())
        return "";
       }
        int i=0;
        int j=0;
        int k=0;
        cout<<digits<<" "<<letters<<" ";
       if(digits.length()>letters.length())
      {  while(true)
        {   
            if(i<digits.length())
            {
                s[k]=digits[i];
                i++;
                k++;
            }
            if(j<letters.length())
            {
                s[k]=letters[j];
                j++;
                k++;
            }
            else
            break;
        }
        }
        else
        {
            while(true)
        {   
            
            if(j<letters.length())
            {
                s[k]=letters[j];
                j++;
                k++;
            }
            if(i<digits.length())
            {
                s[k]=digits[i];
                i++;
                k++;
            }
            else
            break;
        } 
        }
        return s;
    }
};