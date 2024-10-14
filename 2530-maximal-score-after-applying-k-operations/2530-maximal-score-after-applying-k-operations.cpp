class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it: nums)pq.push(it);
        long long ans=0;
        while(k--){
             ans += pq.top();
             int a = pq.top();
             pq.pop();
             if(a%3==0) pq.push(a/3);
             else pq.push(a/3 + 1);
        }
        return ans;
    }
};