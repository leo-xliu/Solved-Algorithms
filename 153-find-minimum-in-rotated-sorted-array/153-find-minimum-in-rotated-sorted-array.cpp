class Solution {
public:
    int findMin(vector<int>& nums) {
        int l(0), h(nums.size()-1);
        int val = nums[0];
        int minelem = val;
        while (l <= h){
            int mid = (h-l)/2 + l;
            if (nums[mid] < val){
                minelem = min(minelem, nums[mid]);
                h = mid-1;
            }
            else l = mid+1;
        }
        return minelem;
    }
};


//use binary search to find smallest value index
//start with the pivot value which is the first index
//if nums[mid] <= val then store the min value and h = mid-1;
//we shift the high value because we know all values after it will be greater 
//if nums[mid] > val then l = mid+1;
//this is because the values will keep increasing after the pivot until we reach the smallest value
