class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        int m = n/2;
        int Psum=skill[0]+skill[n-1];
        for(int i=1;i<m;i++){
            int Csum= skill[i]+skill[n-i-1];
            
            if(Psum != Csum){
                return -1;
            }
            Psum = Csum;
        }
        long long product=0;
        for(int i=0;i<m;i++){
            product += (skill[i]*skill[n-i-1]);
        }
        return product;
        
    }
};