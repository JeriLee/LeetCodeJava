/*
写一个循环队列
*/

class MyCircularQueue {
public:
    int* arr;
    int l = 0;
    int r = 0;
    int k = 16;

    MyCircularQueue(int k) {
        arr = new int[k+1];
        this->k = k;
    }
    
    ~MyCircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return l == r;
    }

    bool isFull() {
        int next = (r+1) % (k+1);
        return next == l;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            arr[r] = value;
            r = (r+1)%(k+1);
            return true;
        }
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else{
            l = (l+1)%(k+1);
            return true;
        }
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[l];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int last = (r-1);
        if(last<0) last +=k+1;
        return arr[last];
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */