// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         const int MOD = 1000000007;
//         stack<int> st;  // Stack to maintain indices and their count
//         vector<int> left(arr.size()), right(arr.size());

//         for (int i = 0; i < arr.size(); i++) {
//             while (!st.empty() && arr[i] < arr[st.top()]) {
//                 st.pop();
//             }
//             if (st.empty()) {
//                 left[i] = -1;
//             } else {
//                 left[i] = st.top();
//             }
//             st.push(i);
//         }

//         while (!st.empty()) {
//             st.pop();
//         }

//         for (int i = arr.size() - 1; i >= 0; i--) {
//             while (!st.empty() && arr[i] < arr[st.top()]) {
//                 st.pop();
//             }
//             if (st.empty()) {
//                 right[i] = arr.size();
//             } else {
//                 right[i] = st.top();
//             }
//             st.push(i);
//         }

//         long long ans = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             ans = (ans + (long long)arr[i] *(i- left[i]) * (right[i]-i)) % MOD;
//         }
//         return ans;
//     }
// };

typedef unsigned long long ll;
class Solution {
public:
    
    //This is just we are finding next smaller to each element to left
    //Similar : Leetcode-84
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    //This is just we are finding next smaller to each element to right
    //Similar : Leetcode-84
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        
        ll sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i]; //distance to nearest smaller to left from i
            
            ll d2 = NSR[i] - i; //distance to nearest smaller to right from i
            
           
            ll total_ways_for_i_min = d1*d2;
            ll sum_i_in_total_ways  = arr[i] * (total_ways_for_i_min);
            
            sum  = (sum + sum_i_in_total_ways)%M;
        }
        
        return sum;
        
    }
};
