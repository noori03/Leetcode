class Solution {
public:
    bool check(vector<int> freq1,vector<int> freq2){
       for(int i=0;i<27;i++){
        if(freq1[i]!=freq2[i])return false;
       }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int n = s1.length();
        int m = s2.length();
        int sum = 0, sum2 = 0;
        vector<int> freq1(27, 0);
         vector<int> freq2(27, 0);
        for (int i = 0; i < n; i++) {
            sum += (s2[i] - 'a' + 1);
            sum2 += (s1[i] - 'a' + 1);
            
            freq1[s2[i] - 'a' + 1]++;
            freq2[s1[i] - 'a' + 1]++;
        }

        if (sum == sum2 && check(freq1,freq2))
            return true;
        for (int i = 1; i <= m - n; i++) {
            sum += (s2[i + n - 1] - 'a' + 1);
            sum -= (s2[i - 1] - 'a' + 1);
            freq1[(s2[i + n - 1] - 'a' + 1)] ++;
            freq1[(s2[i - 1] - 'a' + 1)]--;
            if (sum == sum2 && check(freq1,freq2)) {                
                return true;
            }
        }
        return false;
    }
};