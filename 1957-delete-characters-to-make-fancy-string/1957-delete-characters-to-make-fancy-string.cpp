class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        string ans;
        char ch=s[0];
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(ch==s[i]) count++;
            else {
                ch=s[i];
                count=1;
            }
            if(count>2) continue;
            else ans.push_back(s[i]);
        }
        return ans;
    }
};