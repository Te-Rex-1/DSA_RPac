#include <vector>
#include <algorithm>
#include <iostream>
void bubbleSort(vector<int>& arr, int n) {   
    bool swapped=false;
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            // If the element found is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped=true;
            }
        }
        if(!swapped)
        break;
    }
}
