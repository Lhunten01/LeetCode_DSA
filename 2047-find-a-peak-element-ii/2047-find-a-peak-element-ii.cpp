#include <vector>
using namespace std;

class Solution {
public:
    int check(vector<vector<int>>& mat, int mid, int& row) {
        int maxi = INT_MIN;
        row = 0;
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            if (mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                row = i;
            }
        }
        return maxi;
    }

    bool isPeak(vector<vector<int>>& mat, int row, int col) {
        int n = mat.size();
        int m = mat[0].size();
        int current = mat[row][col];
        if (row > 0 && mat[row - 1][col] > current) return false;
        if (row < n - 1 && mat[row + 1][col] > current) return false;
        if (col > 0 && mat[row][col - 1] > current) return false;
        if (col < m - 1 && mat[row][col + 1] > current) return false;
        return true;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = 0;
            int peakValue = check(mat, mid, row);

            if (isPeak(mat, row, mid)) {
                return {row, mid};
            }

            if (mid > 0 && mat[row][mid - 1] > peakValue) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return {};
    }
};
