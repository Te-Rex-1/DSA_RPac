#include <stdio.h>

void bubbleSort(int array[], int size) {
    int key ;
    for (int step = 0; step < size - 1; ++step) {
        
        // Loop to compare array elements
        for (int i = 0; i < size - step - 1; ++i) { 
            // Compare two adjacent elements
            if (array[i] > array[i + 1]) {
                // Swap if the element found is greater
                // than the next element
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }                 
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {20, -2, 45, 0, 11, -9};
    int size = sizeof(data) / sizeof(data[0]);
    
    bubbleSort(data, size);
    
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
    
    return 0;
}
