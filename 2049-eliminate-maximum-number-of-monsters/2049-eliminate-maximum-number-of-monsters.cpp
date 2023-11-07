class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int count = 0;
        int n = dist.size();

        vector<double> timeToReach(n);
        for (int i = 0; i < n; i++) {
            timeToReach[i] = static_cast<double>(dist[i]) / speed[i];
        }

        sort(timeToReach.begin(), timeToReach.end());

        for (int i = 0; i < n; i++) {
            if (timeToReach[i] <= i) {
                break;
            }
            count++;
        }

        return count;
    }
};
