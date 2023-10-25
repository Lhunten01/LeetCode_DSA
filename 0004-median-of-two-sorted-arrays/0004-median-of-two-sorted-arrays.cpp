class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &n1, vector<int> &n2)
        {
            int n = n1.size();
            int m = n2.size();
            int l = n - 1;
            int j = m - 1;
            int k = m + n; //size of vector after merging
            
            n1.resize(k); // resize n1 vector for inplace merge
            k = k - 1;
            while (l >= 0 && j >= 0)
            {
                if (n1[l] > n2[j])
                {
                    n1[k] = n1[l];
                    k--;
                    l--;
                }
                else
                {
                    n1[k] = n2[j];
                    k--;
                    j--;
                }
            }
            while (j >= 0)
            {
                n1[k] = n2[j];
                k--;
                j--;
            }
            
            k = m + n;
            if (k % 2 == 1)
                l = j = (k) / 2;
            else
            {
                l = (k / 2) - 1;
                j = l + 1;
            }
            return (n1[l] + n1[j]) / 2.0;
        }
};