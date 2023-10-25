class Solution {
public:
long long modulo = 1000000007; 
     long long pow(long long base, long long exp) {
        if (exp == 0) return 1;
        long long halfPower = pow(base, exp / 2) % modulo;
        long long result = (halfPower * halfPower) % modulo;

        if (exp % 2 == 1) {
            result = (result * base) % modulo;
        }

        return result;
    }
    int countGoodNumbers(long long n) {

        long long oddIndexes=n/2;
        long long evenIndexes=n/2+n%2;
        return (pow(5,evenIndexes)*pow(4,oddIndexes))%modulo;
    }
};