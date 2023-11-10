class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int ast = asteroids[i];

            while (!st.empty() && st.top() > 0 && ast < 0) {
                if (abs(ast) > abs(st.top())) {
                    st.pop();
                } else if (abs(ast) == abs(st.top())) {
                    st.pop();
                    ast = 0; // Both asteroids are destroyed
                    break;
                } else {
                    ast = 0; // The current negative asteroid is destroyed
                    break;
                }
            }

            if (ast != 0) {
                st.push(ast);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
