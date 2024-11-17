#include <iostream>
using namespace std;

int bin_Search(int arr[], int key, int size)
{
    int start = 0;
    int end = size - 1;
   
    while (start <= end)
    {
         int mid = start+(end-start)/2;
        if (arr[mid] == key)
            return mid;

        /* code */
        if (arr[mid] < key)
        {
            /* code */

            start=mid+1;
        }
        else if (arr[mid] > key)
        {
            end =mid-1;
            
        }
    }
    return -1;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "index is " << bin_Search(arr, 2, size);
    cout << "index is " << bin_Search(arr, 7, size);

    return 0;
}