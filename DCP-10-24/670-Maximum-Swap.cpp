class Solution {
public:
    int maximumSwap(int num) {
        priority_queue<string> pq;
        string str = to_string(num);
        pq.push(str);
        int len = str.size();
        for(int i = 0; i<len-1; i++){
            for(int j = i+1; j<len; j++){
                string temp = str;
                if(str[i] < str[j]){
                    swap(temp[i], temp[j]);
                    pq.push(temp);
                }
            }
        }
        return stoi(pq.top());
    }
};