class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it: nums)pq.push(it);
        
        long long ans=0;
        while(k--){
            int a = pq.top();
            pq.pop();
            ans += a;
            pq.push((a+2)/3);
        }
        return ans;
    }
};