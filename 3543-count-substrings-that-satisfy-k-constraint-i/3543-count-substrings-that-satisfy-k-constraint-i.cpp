class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
           int count0=0;
           int count1=0;
           for(int j=i;j<n;j++)
           {
              if(s[j]=='1')
              count1++;
              if(s[j]=='0')
              count0++;
              if(count1>k&&count0>k)
              break;
              else
              count++;
           }
        }
        return count;
    }
};