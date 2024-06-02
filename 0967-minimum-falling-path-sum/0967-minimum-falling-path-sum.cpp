class Solution {
public:
    int findMin(int i, int j, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || j >= n)
            return 1e9;
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int up = matrix[i][j] + findMin(i - 1, j, matrix, n, dp);
        int left = matrix[i][j] + findMin(i - 1, j - 1, matrix, n, dp);
        int right = matrix[i][j] + findMin(i - 1, j + 1, matrix, n, dp);
        
        return dp[i][j] = min(up, min(left, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for(int j=0;j<n;j++)
            {  
             
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal += 1e9; 
            }
            int rightDiagonal = matrix[i][j];
            if (j + 1 < n) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal += 1e9; 
            }
            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }
       
    for (int j = 0; j < n; j++) {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
    }
};
