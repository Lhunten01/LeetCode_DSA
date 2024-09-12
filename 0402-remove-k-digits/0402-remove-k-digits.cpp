class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n)
        return "0";
        string s;
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            int cnt=k;
            int x=num[i];
            while(!st.empty()&&cnt>0&&x<st.top())
            {
               cnt--;
               st.pop();
            }
          k=cnt;
          st.push(x);
        }
        while(!st.empty()&&k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
           s+=st.top();
           st.pop();
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(s[i]=='0')
        {
          i++;
        }
        int len=s.length();
        if(i==len)
        return "0";
        return s.substr(i,len-i);
    }
};