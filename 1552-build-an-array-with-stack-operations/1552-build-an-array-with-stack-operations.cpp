class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
         vector<string> output;
    int should_ve = 1;
    for(int i=1;i<=target.size();i++){
        if(target[i-1] != should_ve){
            int cnt = target[i-1]-should_ve;
            while(cnt--)
                output.push_back("Push"), output.push_back("Pop");
        }
        output.push_back("Push");
        should_ve = target[i-1] + 1;
    }

    return output;
    }
};