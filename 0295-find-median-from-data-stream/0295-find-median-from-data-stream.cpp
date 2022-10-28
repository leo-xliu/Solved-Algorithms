class MedianFinder {
private: 
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        //starting stages
        if (maxq.empty()){
            maxq.push(num);
            return;
        }
        else if (minq.empty()){
            if (num < maxq.top()){
                minq.push(maxq.top());
                maxq.pop();
                maxq.push(num);
            }
            else {
                minq.push(num);
            }
            return;
        }
        
        //main algo
        (num <= maxq.top()) ? (maxq.push(num)) : (minq.push(num));
        int maxsize = maxq.size();
        int minsize = minq.size();
        if (maxsize == (minsize+2)){
            minq.push(maxq.top());
            maxq.pop();
        }
        else if (minsize == (maxsize+2)){
            maxq.push(minq.top());
            minq.pop();
        }
    }
    
    double findMedian() {
        int maxsize = maxq.size();
        int minsize = minq.size();
        if (maxsize == minsize){
            int mid1 = maxq.top();
            int mid2 = minq.top();
            return ((double) (mid1+mid2)/2);
        }
        else{
            int median = (minsize < maxsize) ? (maxq.top()) : (minq.top());
            return median;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


/* 
use two heaps
1 min heap 1 max heap
try to keep heaps as balanced as possibel in size
min heap will store top half of data stream in value
max heap will store bottom half of data stream in value 
this way the min and max represent the halfway points of the data stream
if the sizes are unbalanced then the one with more values will be the median
to insert new values, compare the new value with the min and max
if it is <= max then it belongs in the max heap
if it is >= min then it belongs in the min heap
however, if it chooses the heap with the smaller size, then we will need to pop off the max/min and put that into the other heap


*/