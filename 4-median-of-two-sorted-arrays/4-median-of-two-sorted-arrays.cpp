class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) return(findMedianSortedArrays(nums2, nums1));
        int half = (n+m+1)/2;
        int l(0), h(n);
        double res = 0.0;
        while(l <= h){
            int mid = (h+l)/2; //index of partition 1
            int part2 = half-mid; //index of parititon 2
            //check if it is valid parition
            int left1 = (mid > 0) ? (nums1[mid-1]) : INT_MIN;
            int left2 = (part2 > 0) ? (nums2[part2-1]) : INT_MIN;
            int right1 = (mid < n) ? (nums1[mid]) : INT_MAX;
            int right2 = (part2 < m) ? (nums2[part2]) : INT_MAX;
            //if valid then break
            if (left1 <= right2 && left2 <= right1){
                if ((n+m) % 2) res = max(left1, left2);
                else res = (max(left1, left2) + min(right1, right2))/2.0;
                break;
            }
            else if (left1 > right2) h = mid-1;
            else l = mid+1;
        }
        return res;
    }
};


//we want to form a partition of each array such that there is a left partition on each array and also a right partition
//our goal is that our partitions are valid such that all values in the combined left parition is less than the values in the right partition
//we want our total left paritition size shared across both arrays to be half of the combined size
//this ensures that we are at the median
//we will use the array with the lesser amount of values as the main array that we will partition 
//first find roughly half the combined array size floor((m+n)/2)
//then create low and hight pointers for nums1
//subtract the pointers and use that as the parition split
//let this be part of the left side because we use integer division to find the mid so it is already right skewed
//then subtract this amount from the half which will tell us the size of partition for the second array 
//now we can check if the partition is valid
//the partition is valid if the right most values of each left partition are less than or equal to the opposite array's left most values for the right parition. 
//this gives a valid partition because the arrays are sorted so we know individually, the paritions are already correct but we must cross examine to make sure it is satisfactory with the other array too. then it will be a valid parition across them combined 
//if it is valid, then we can find the median
//if it is not valid, then we must repartition the main array using binary search
//by changing low, we are increasing the size of our main partition 
    //change low if the right farthest in the other arrays partition is greater
    //this way we can decrease the size of the other array
//by changing high, we are decreasing the size of our main parition
    //if main arrays right most value of the left partition is greater than the other array's right parition
    //this way we can decrease the size and make the other one bigger
//we can repeating this process until we obtain a valid parition
//the moment we find the valid partition we can obtain our answer since this has to be the mean as both size are equal size
//now we must find the median and our method differs based on even or odd
//if the entire size is odd, we simply take the leftmost right partition values and find the min of them
//this would be the value closest to the middle
//if it is even, then we have to again do the smallest of the right partitions but we must also find the max of the 
//left partition and then find the average of the 2 
//there is an edge case for when the partition is size 0 
//to counter this issue, we make the left side of each array the smallest possible int value (as close to -inf)
//then we make the right side of each array the biggest possible int value (as close to inf)
//this way if we ever do encounter those values, we will be okay since the max/min of the same value will still be the same value 
//note there will always be a valid partition since both are sorted
