class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int i=0;
        while(s[i]=='0' && i<s.size())i++;;
        if(i==s.size())return 0;
        int count_one=0;
        cout<<i<<endl;
        for(int j=i;j<s.size();j++){
              if(s[j]=='1')
                {count_one++;
                cout<<"one";}
              else{
                ans += count_one;
                cout<<"zerp";
              }
        }
        return ans;
    }
};