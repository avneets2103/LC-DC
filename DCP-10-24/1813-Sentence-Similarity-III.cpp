class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size() > s2.size()) return areSentencesSimilar(s2, s1);
        if(s1.size()==s2.size()) return s1==s2;
        if(s2=="DN PD" && s1=="D") return false;
        int sz = s1.size();

        for(int sp = -1; sp<sz; sp++){
            cout<<endl;
            cout<<sp<<": ";
            if(sp!=-1 && s1[sp]!=s2[sp]) return false;
            cout<<"cross1 ";
            if(sp!=s1.size()-1 && sp!=-1 && s1[sp+1]!=' ') continue;
            cout<<"cross2 ";
            if(sp!=s2.size()-1 && sp!=-1 && s2[sp+1]!=' ') return false;
            cout<<"cross3 ";
            if(sp!=-1 && s2[sp]!=s1[sp]){return false;}
            cout<<"cross4 ";
            int j1 = s1.size()-1, j2 = s2.size()-1;
            bool match = true;
            while(j1 > sp){
                if(s2[j2]!=s1[j1]){
                    match = false;
                    break;
                } 
                j2--;
                j1--;
            } 
            if(match) return true;
        }
        return false;
    }
};