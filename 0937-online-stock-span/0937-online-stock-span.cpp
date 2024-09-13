class StockSpanner {
public:
   stack<pair<int,int>>st;
    StockSpanner() {
        st;
    }
    
    int next(int price) {
         pair<int,int>x={price,1};
         while(!st.empty()&&st.top().first<=price)
         {
            x.second+=st.top().second;
            st.pop();
         }
         st.push(x);
         return x.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */