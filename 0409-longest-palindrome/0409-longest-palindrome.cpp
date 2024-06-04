class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alpha(52,0);
        for(auto it: s){
           if(it>='a' && it<='z')   
              alpha[it-'a']++;
            else alpha[it-'A'+26]++;
        }
           
       
        int ans=0;
        int odd=0;
        for(auto it : alpha){
            if(it%2==0) ans+=it;
            else {
                ans += (it-1);
                odd=1;
                }
        
    }
    return odd+ans;
    }
};