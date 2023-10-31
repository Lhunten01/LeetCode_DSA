class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
        return true;
        if(n<1)
        return false;
        if(n&(n-1))
        return false;
        else
        return true;
    }
};