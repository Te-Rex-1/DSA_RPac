#include <iostream>
//#include <vector>
using namespace std;

int first_occur(int arr[], int key, int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    int store_ans = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            store_ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    return store_ans;
}

int last_occur(int arr[], int key, int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    int store_ans = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            store_ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    return store_ans;
}

int mountatin(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        /* code */
        mid = start + (end - start) / 2;
        // for checking
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        if (arr[mid] > arr[mid + 1] && arr[mid - 1] < arr[mid + 1])
        {
            return mid;
        }
        else
        {
            end = mid - 1;
        }
    }
}
int pivot(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid;

    // Check running condition
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        // Check for pivot element
        if (mid > 0 && arr[mid] < arr[mid - 1])
        {
            return mid;
        }
        if (mid < size - 1 && arr[mid] > arr[mid + 1])
        {
            return mid + 1;
        }

        // Decide the side to continue search
        if (arr[mid] >= arr[start])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1; // If no pivot is found (though it should always be found in a rotated array)
}

int search_Rotated(int arr[], int target, int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    int pivot_index = pivot(arr, size);

    if (arr[pivot_index] == target)
    {
        return pivot_index;
    }
    else if (arr[pivot_index] < target < arr[end])
        start = pivot_index + 1;
    else
        end = pivot_index - 1;
    while (start <= end)
    {
        /* code */
        mid = start + (end - start) / 2;
        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

long long int mySqrt_Bin(int x)
{
    int start = 0;
    int end = x;
    long long int mid = start + (end - start) / 2;
    long long int ans;
    long long int sq;
    while (start <= end)
    {
        /* code */
                   // cout << "testing in bin sqr"<<endl;

        sq = mid * mid;
        if ((sq == x))
        {
            /* code */
            return mid;
        }
        else if (x > (sq))
        {
            /* code */
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

double morePrecise(int precise, int ans, int no) {
    double factor = 1;
    double temp = ans;
    for (int i = 0; i < precise; i++) {
            //cout << "testing in more "<<endl;

        factor /= 10;
        for (double j = temp; j * j < no; j += factor) {
            temp = j;
        }
    }
    return temp;
}

int main()
{

    // int even[7] = {6, 7, 0, 1, 2, 3, 4};
    // int test[1] = {1};
    // cout << "testing"<<endl;
    // cout<<"1"<<endl;
    // cout<<"First Occurence is at index  "<<first_occur(even,3,5)<<"\n";
    // cout<<"Last Occurence is at index "<<last_occur(even,3,5);
    // cout<<"index of moutain"<<mountatin(even,3);
    // cout<<"index of pivot element"<<pivot(even,5);
    // cout<<"index of searched element is : "<< search_Rotated(test,3,2);
    // cout<<"square root ="<<mySqrt_Bin(99999999999);
    
    cout << "Answer for sqaure root is " << morePrecise(10, mySqrt_Bin(137), 137);
   // cout<<"out";
    return 0;
}

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//          int start=0;
//     int end=arr.size()-1;
//     int mid;
//     int ans;
//     while (start<end)
//     {
//         /* code */
//         mid=start+(end-start)/2;
//         // for checking
//        if(arr[mid]<arr[mid+1]){
//         start=mid+1;
//        }

//        else{
//         end=mid;
//        }

//         ans=mid;
//     }
//       return ans;
//     }
// };