class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result=0;
    for(auto it :left)
    {
        result=max(result,it);
    }
     for(auto it :right)
    {
        result=max(result,n-it);
    }
    return result;
    }
};