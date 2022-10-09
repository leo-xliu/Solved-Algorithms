class KthLargest {
private: 
    priority_queue<int, vector<int>, greater<int>> pq; 
    int maxsize;
public:
    KthLargest(int k, vector<int>& nums) {
        maxsize = k;
        for (int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        while (pq.size() > maxsize){
            pq.pop();
        }
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > maxsize){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


//keep a min-heap with exactly k elements
//if the size exceeds k, remove the top
//otherwise, the top is the kth largest element 
//notice we can always just remove the smallest value if size is greater than k because this is a stream that cannot be deleted
//this means that the values greater than our current value will always remain in the stream unless replaced by an even larger number
//as long as we keep the k largest values, we are perfectly fine
//the heap will do all the work for us in the case that a bigger value is added to the stream


//priority queue data structure in C++
//priority_queue<data type> is just a max heap
//priority_queue<datat type, vector<data type>, greater<data type> to make it a min heap
//if the syntax is forgotten, you can always make a maxp heap a min heap by multiplying all values by -1
