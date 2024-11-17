#include <iostream>
#include <vector>
using namespace std;


bool isPossible(vector<int>arr,int n, int m,int mid){
    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid)
        {
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m||arr[i]>mid)
            {
                return false;
            }
            pageSum=arr[i];
        }

    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    int start=0;
    int sum=0;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int end=sum ;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(isPossible(arr,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
        
    }
    return ans;
}

 bool isPossible(vector<int>& nums, int k,int mid){
        int array_sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
           
            if(array_sum<=mid)
             array_sum+=nums[i];
             else{
                if(count>k)
                return false;
                else
                count++;
                array_sum=nums[i];
             }
        }
        return true;
 }

    int splitArray(vector<int>& nums, int k) {
        int start=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }

        int end=sum;
        int mid=start+(end-start)/2;
        while(start<=end)
        {
            if(isPossible(nums,k,mid))
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }

    }



main()
{
     std::vector<int> myVector = {2,3,1,2,1};
  cout<<findPages(myVector,5,2);
  //cout<<splitArray(myVector,2);
    return 0;
}