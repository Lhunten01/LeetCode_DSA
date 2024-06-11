class Solution {
public:
    bool isStar(string &S1, int i) {
        for (int j = 0; j <= i; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    bool checkMatch(int i, int j, string &s, string &p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;
        if (i < 0 && j >= 0)
            return isStar(p, j);
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = checkMatch(i - 1, j - 1, s, p, dp);
        else {
            if (p[j] == '*') {
                return dp[i][j] = checkMatch(i - 1, j, s, p, dp) || checkMatch(i, j - 1, s, p, dp);
            } else {
                return dp[i][j] = false;
            }
        }
    }

    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return checkMatch(n1 - 1, n2 - 1, s, p, dp);
    }
};
