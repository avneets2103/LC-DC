class MyCalendar {
    vector<pair<int, int>> dates;
    pair<int, int> justBefore(int start){
        int s = 0, e = dates.size()-1;
        pair<int, int> ans = {-1, -1};
        while(s<=e){
            int mid = s + (e-s)/2;
            if(dates[mid].first > start) e = mid-1;
            else{
                s = mid+1;
                ans = dates[mid];
            }
        }
        return ans;
    }
    pair<int, int> justAfter(int start){
        int s = 0, e = dates.size()-1;
        pair<int, int> ans = {INT32_MAX, INT32_MAX};
        while(s<=e){
            int mid = s + (e-s)/2;
            if(dates[mid].first < start) s = mid+1;
            else{
                e = mid-1;
                ans = dates[mid];
            }
        }
        return ans;
    }
    void insert(pair<int, int> p){
        dates.push_back(p);
        int i = dates.size()-1;
        while(i>0 && dates[i].first < dates[i-1].second ){
            swap(dates[i], dates[i-1]);
            i--;
        }
    }
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        pair<int, int> bef = justBefore(start), aff = justAfter(start);
        if(bef.second >= start || aff.first <= end-1) return false;
        insert({start, end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */