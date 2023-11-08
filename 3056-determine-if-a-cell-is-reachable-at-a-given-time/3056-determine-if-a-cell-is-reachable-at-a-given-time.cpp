class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Calculate the absolute difference between x and y coordinates
        int diff_in_x_coords = abs(fx-sx);
        int diff_in_y_coords = abs(fy-sy);

        // If the final and initial coordinates are the same, and t!=1 then they are reachable
        if (diff_in_x_coords==0 && diff_in_y_coords==0) return t!=1;
        // If the differences of both the coordinates are less than time t, return true
        if (diff_in_x_coords<=t && diff_in_y_coords<=t) return true;
        // Else not possible to reach exactly at t. 
        return false;
    }
};