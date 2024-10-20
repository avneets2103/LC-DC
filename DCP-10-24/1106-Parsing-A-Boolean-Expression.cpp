class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto ch: expression){
            if(ch==',') continue;
            if(ch!=')') st.push(ch);
            else{
                bool andd = true, orr = false;
                while(st.top()!='('){
                    char curr = st.top();
                    st.pop();
                    if(curr=='t') orr = true;
                    if(curr=='f') andd = false;
                }
                st.pop();
                if(st.top()=='!'){
                    if(!orr){
                        st.push('t');
                    }else{
                        st.push('f');
                    }
                }else if(st.top()=='&'){
                    if(!andd){
                        st.push('f');
                    }else{
                        st.push('t');
                    }
                }else if(st.top()=='|'){
                    if(!orr){
                        st.push('f');
                    }else{
                        st.push('t');
                    }
                }
            }
        }
        bool andd = true, orr = false;
        while(st.top()=='t' || st.top()=='f'){
            char curr = st.top();
            st.pop();
            if(curr=='t') orr = true;
            if(curr=='f') andd = false;
        }
        st.pop();
        if(st.empty()) return orr;
        if(st.top()=='!'){
            if(!orr){
                return true;
            }else{
                return false;
            }
        }else if(st.top()=='&'){
            if(!andd){
                return false;
            }else{
                return true;
            }
        }else if(st.top()=='|'){
            if(!orr){
                return false;
            }else{
                return true;
            }
        }
        return true;
    }
};