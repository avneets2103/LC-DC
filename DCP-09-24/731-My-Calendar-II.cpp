class MyCalendarTwo {
    vector<pair<int, int>> overlap;
    vector<pair<int, int>> nonOverlap;
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for(auto o: overlap){
            int s = o.first, e = o.second;
            if(!(end <= s || start>=e)){
                return false;
            }
        }

        for(auto no: nonOverlap){
            int s = no.first, e = no.second;
            if(!(end <= s || start>=e)){
                overlap.push_back({max(s, start), min(e, end)});
            }
        }
        nonOverlap.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */