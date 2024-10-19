class Solution {
    string findStr(int n){
        if(n==0) return "0";
        string minusOne = findStr(n-1);
        string invert = "";
        for(auto ch: minusOne){
            if(ch=='0') invert += '1';
            else invert += '0';
        }
        reverse(invert.begin(), invert.end());
        return minusOne + "1" + invert;
    }
public:
    char findKthBit(int n, int k) {
        return findStr(n)[k-1];
    }
};