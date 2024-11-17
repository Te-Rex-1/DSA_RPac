// C Program to reverse an array using temporary array

#include <stdio.h>
#include <stdlib.h>

// function to reverse an array
void reverseArray(int arr[], int n) {                                                                                                                                                                                     
    
    // Temporary array to store elements in reversed order
    int temp;
  
    // Copy elements from original array to temp in reverse order
    for(int i = 0; i < n/2; i++)
        { temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;}
    // Copy elements back to original array
    // for(int i = 0; i < n; i++)
    //     arr[i] = temp[i];
}

int main() {
    int arr[] = { 1, 4, 3, 2, 6, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);
  
    for(int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    
    return 0;
}
