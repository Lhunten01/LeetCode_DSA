class SeatManager {
private:priority_queue<int,vector<int>,greater<int>>arr;
  
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
        {
            arr.push(i);
        }
    }
    
    int reserve() {
        int x=arr.top();
        arr.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
       arr.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */