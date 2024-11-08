class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxi = pow(2,maximumBit);
        vector<int> ans(nums.size(),0);
        int Xor=0;
        int i=nums.size()-1;
        for(auto it:nums){
            int k;
            Xor ^=it;
            k = Xor^(maxi-1);
           
            ans[i--]=k;
        }
        cout<<maxi;
        return ans;
    }
};