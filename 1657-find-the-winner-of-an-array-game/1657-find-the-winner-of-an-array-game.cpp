// class Solution {
// public:
//     int getWinner(vector<int>& arr, int k) {
//         int maxi=*max_element(arr.begin(),arr.end());
//         if(k>=arr.size())
//         return maxi;
        
//           int count=0;
//            int x=arr[0];
//             while(maxi!=arr[0])
//             { 
//                 if(arr[1]>x)  
//                 {   x=arr[1];
//                     count=1;
//                     if(k==1)
//                     return x;
//                     swap(arr[0],arr[1]);
//                     rotate(arr.begin()+1,arr.begin()+2,arr.end()); 
//                 }
//                 else
//                 {   count++;
//                     if(count==k)
//                      return x;
//                     rotate(arr.begin()+1,arr.begin()+2,arr.end());
//                 }
//             }
//         return maxi;
//     }
// };
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxEl = *max_element(begin(arr), end(arr));
        
        if(k >= n)
            return maxEl;
        
        
        int winner     = arr[0];
        int wins       = 0;
        
        for(int i = 1; i<n; i++) {
            if(winner<arr[i])
            {
                winner=arr[i];
                wins=1;
            }
            else
            {
                wins++;
            }
            if(wins==k)
             return winner;
        }
        
        return winner;
        
    }
};
