#include<vector>
class Solution {
public:

int pivot(vector<int>& arr) {
   int start = 0;
        int end = arr.size() - 1;
        int mid;

        // Check running condition
        while (start <= end) {
            mid = start + (end - start) / 2;

            // Check for pivot element
            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                return mid;
            }
            if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1]) {
                return mid + 1;
            }

            // Decide the side to continue search
            if (arr[mid] >= arr[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return 0; // If no pivot is found, the array is not rotated
}

    int search(vector<int>& nums, int target) {
         int start=0;
        int end=nums.size()-1;
        int mid;
     int pivot_index=pivot(nums);
    if (target==nums[pivot_index])
    {
        /* code */
        return pivot_index;
    }
    else{
        if (target >nums[end])
        {
            /* code */
            end=mid-1;
        }
        else{
            start=pivot_index+1;
        }
        
    }

    while (start<=end)
    {
        /* code */
        mid=start+(end-start)/2;
        if(target==nums[mid])
        return mid;
        else if(target<nums[mid])
        end=mid-1;
        else
        start=mid+1;
    }
    return -1;
    }
};