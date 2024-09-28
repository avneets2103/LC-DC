class DLLNode {   
public:
    DLLNode* next;
    DLLNode* prev;
    int val;
    DLLNode(int val){
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class MyCircularDeque {
    DLLNode* st, * end;
    int sz;
    int k;
public:
    MyCircularDeque(int k) {
        st = NULL;
        end = NULL;
        sz = 0;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(sz==k) return false;
        DLLNode* newNode = new DLLNode(value);
        if(st==NULL){
            st = newNode;
            end = st;
        }else{
            newNode->next = st;
            st->prev = newNode;
            st = newNode;
        }
        sz++;
        return true;
    }
    
    bool insertLast(int value) {
        if(sz==k) return false;
        DLLNode* newNode = new DLLNode(value);
        if(end==NULL){
            st = newNode;
            end = st;
        }else{
            newNode->prev = end;
            end->next = newNode;
            end = newNode;
        }
        sz++;
        return true;
    }
    
    bool deleteFront() {
        if(sz==0) return false;
        st = st->next;
        if(st){
            st->prev = NULL;
        }
        sz--;
        if(sz==0){
            end = NULL;
            st = NULL;
        }
        return true;
    }
    
    bool deleteLast() {
        if(sz==0) return false;
        end = end->prev;
        if(end){
            end->next = NULL; 
        }
        sz--;
        if(sz==0){
            end = NULL;
            st = NULL;
        }
        return true;
    }
    
    int getFront() {
        if(sz==0) return -1;
        if(!st) return -1;
        return st->val;
    }
    
    int getRear() {
        if(sz==0) return -1;
        if(!end) return -1;
        return end->val;
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==k;
    }
};