// class Solution {
// public:
//     bool checkpalindrome(string s,int i,int j)
//     {  
//         while(i<=j)
//         {
//             if(s[i]!=s[j])
//             return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         if(s.length()==1)
//         return s;
//         if(s.length()==2)
//        { 
//            if(s[0]!=s[1])
//           { string l="";
//            l+=s[0];
//            return l;}
//          return s;
//        }
//           int count=0;
//           string ans="";
//         for(int i=0;i<s.length();i++)
//         {
//             for(int j=i+1;j<s.length();j++)
//             {
//                 if(checkpalindrome(s,i,j))
//                 {
//                     if(count<j-i+1)
//                     {
//                         count=j-i+1;
//                         ans=s.substr(i,j-i+1);
//                     }
//                 }
//             }
//         }
//         if(ans=="")
//         return ans+=s[0];
//         return ans;
//     }
// };
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        int start = 0; // Start index of the longest palindromic substring.
        int maxLen = 1; // Length of the longest palindromic substring.

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All individual characters are palindromes.
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2.
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for palindromes of length 3 or more.
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1; // Ending index of the current substring.

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
