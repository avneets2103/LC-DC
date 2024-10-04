#define ll long long 
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        ll i = 0, sum=-1, j = skill.size()-1, chem=0;
        while(i<j){
            chem += skill[i]*skill[j];
            if(sum==-1){
    
                sum = skill[i]+skill[j];
            }else{
                if(skill[i]+skill[j]!=sum)return -1;
            }
            i++; j--;
        }
        return chem;
    }
};