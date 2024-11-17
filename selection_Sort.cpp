#include <iostream>  // For std::cout
#include <vector>    // For std::vector
#include <algorithm> // For std::swap

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {

        int min_idx;
        int count = nums.size();
     

        for (int i = 0; i < count; i++)
        {
            min_idx = i;
            for (int j = i + 1; j < count; j++)
            {
                /* code */
                if (nums[min_idx] > nums[j])
                {
                    /* code */
                    min_idx = j;
                }
            }
            // swap
            if (min_idx != i)
            {
                std::swap(nums[i], nums[min_idx]);
            }
        }

        return nums;
    }
};