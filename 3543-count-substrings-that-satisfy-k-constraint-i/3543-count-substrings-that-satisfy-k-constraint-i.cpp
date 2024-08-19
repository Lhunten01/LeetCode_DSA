class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count1=0,count0=0;
        int i=0,j=0;
        int count=0;
        int n=s.length();
        while(j<n){
            if(s[j]=='1')
            count1++;
            if(s[j]=='0')
            count0++;
            while(count1>k&&count0>k)
                {  if(s[i]=='1')
                  count1--;
                   else
                   count0--;
                    i++;
                }
               count+=j-i+1;
               j++;
        }
        return count;
    }
};