class Solution {
public:
    int search(vector<int>& nums, int target) {
        int val = nums[0];
        int l(0), h(nums.size()-1);
        int maxi = 0;
        while (l <= h){
            int mid = (h-l)/2 + l;
            if (nums[mid] >= val){
                maxi = max(maxi, mid);
                l = mid+1;
            }
            else h = mid-1;
        }
        if (target >= val){
            l = 0;
            h = maxi;
        }
        else {
            l = maxi+1;
            h = nums.size()-1;
        }
        while (l <= h){
            int mid = (h-l)/2 + l;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};

//binary search for the index that separates the two sorted arrays (aka the largest value)
//target here will be the first val of the array since that is the pivot 
//if mid is greater than pivot, then store its index and l = mid +1
//this is because we know it is still ascending (still within pivoted array)
//if mid is less than pivot, then h = mid -1
//this tells us we have passed the last index of the pivoted array so we mnust go right
//we do not care about equals to since all values are distinct and we start with the pivot as the first index anyway
//determine which of the two sorted arrays the real target belongs in
//binary search the one it belongs to 