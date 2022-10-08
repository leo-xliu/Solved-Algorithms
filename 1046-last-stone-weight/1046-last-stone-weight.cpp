class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        map<int, int> heap;
        for (int i = 0; i < stones.size(); i++){
            heap[stones[i]]++;
        }
        while (heap.size() > 1 || heap.begin()->second > 1){
            auto p  = heap.rbegin();
            int y = p->first;
            int x = (p->second > 1) ? (p->first) : ((++p)->first);
            if (heap[y] == 1) heap.erase(y);
            else heap[y]--;
            if (heap[x] == 1) heap.erase(x);
            else heap[x]--;
            if (x != y){
                heap[y-x]++;
            }
        }
        if (heap.empty()) return 0;
        return heap.begin()->first;
    }
};


//set.count() only returns 1 or 0 since values are unique and doesn't matter how many times it occurs
//it either exists or doesn't