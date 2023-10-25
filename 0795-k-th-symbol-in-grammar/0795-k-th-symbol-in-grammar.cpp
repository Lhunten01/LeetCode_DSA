// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         if(n==1)
//          return 0;
//      string s="0";
//      for(int i=0;i<n;i++)
//      {
//          string temp;
//          for(int j=0;j<s.length();j++)
//          {
//              if(s[j]=='0')
//              temp+="01";
//              if(s[j]=='1')
//              temp+="10";
//          }
//          s=temp;
//      }  
//      cout<<s;
//      int x=s[k-1]-'0';
//      return x;
//     }
// };

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;  // Base case: The first row always has '0'.

        // Calculate the middle position in the previous row.
        int mid = pow(2, n - 1) / 2;

        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            // Invert the result from the previous row.
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }
};
