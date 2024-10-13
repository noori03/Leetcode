class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int it : nums){
            if(it==2){
                ans.push_back(-1);
            }
            else {
                for(int i=1 ;i<32;i++){
                    if((it & (1<<i)) == 0 ){
                       //i-1 bit is 1
                       int a = it ^ (1<< (i-1));
                       ans.push_back(a);
                       break;
                    }
                }
            }
        }
        return ans;
    }
};