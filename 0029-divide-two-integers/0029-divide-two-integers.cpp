class Solution {
public:
    int divide(int dividend, int divisor) {
    if (divisor == 0) {
        return INT_MAX;
    }
    
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    long long ldividend = llabs(static_cast<long long>(dividend));
    long long ldivisor = llabs(static_cast<long long>(divisor));

    long long quotient = 0;
    while (ldividend >= ldivisor) {
        long long temp = ldivisor;
        long long multiple = 1;
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        quotient += multiple;
    }

    quotient *= sign;

    if (quotient > INT_MAX) {
        return INT_MAX;
    } else if (quotient < INT_MIN) {
        return INT_MIN;
    } else {
        return static_cast<int>(quotient);
    }
}

};