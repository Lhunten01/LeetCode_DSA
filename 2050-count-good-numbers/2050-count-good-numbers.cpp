class Solution {
public:
long long mod = 1000000007; 
     long long pow(long long x, long long y) {
       if(y==0)
       return 1;
       long long ans=pow(x,y/2);
       ans*=ans;
       ans%=mod;
       if(y%2)
       ans*=x;
       ans%=mod; 
        return ans;
    }
    int countGoodNumbers(long long n) {

        long long oddIndexes=n/2;
        long long evenIndexes=n/2+n%2;
        return (pow(5,evenIndexes)*pow(4,oddIndexes))%mod;
    }
};