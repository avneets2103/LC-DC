class CustomStack {
    vector<int> arr;
    int maxSz;
    int sz;
    int bI;
    int tI;
public:
    CustomStack(int maxSize) {
        arr = vector<int>(maxSize, -1);
        maxSz = maxSize;
        sz = 0;
        bI = -1;
        tI = -1;
    }
    
    void push(int x) {
        if(sz==maxSz) return;
        if(sz==0) bI = 0;
        arr[++tI]=x;
        sz++;
    }
    
    int pop() {
        if(sz==0) return -1;
        sz--;
        if(sz==0) bI=-1;
        return arr[tI--];
    }
    
    void increment(int k, int val) {
        if(sz==0) return;
        int i = 0;
        while(bI+i<=tI && i<k){
            arr[bI+i]+=val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */