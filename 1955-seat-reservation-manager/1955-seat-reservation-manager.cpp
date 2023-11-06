class SeatManager {
private:priority_queue<int,vector<int>,greater<int>>arr;
  int check=1;
public:
    SeatManager(int n) {
    }
    
    int reserve() {
       if(!arr.empty()) {
           int x=arr.top();
        arr.pop();
        return x;
        }
      check++;
      return check-1;
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