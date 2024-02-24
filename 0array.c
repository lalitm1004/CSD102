#include <stdio.h>

void displayArray(int *array, int len) {
    /*
        Prints an array to the screen in O(n) time
    */
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");
}

int isArraySorted(int *array, int len) {
    /*
        Helper function to check if an array is sorted.
        Checks in O(n) time.
        Returns 1 if it is sorted, 0 in all other cases.
    */

    int isSorted = 1;
    for (int i = 0; i < len -1; i++) {
        if (array[i] > array[i+1]) {
            isSorted = 0;
            break;
        }
    }
    return isSorted;
}

int linearSearch(int *array, int len, int searchElement) {
    /*
        Searches for a given element in an array in O(n) time.
        Returns the index of the element or -1 if it is not in array.
    */
    for (int i = 0; i < len; i++) {
        if (array[i] == searchElement) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *array, int startIndex, int endIndex, int searchElement) {
    /*
        Searches for a given element in an array in O(log_2(n)) time.
        Returns the index of the element or -1 if it is not in array.
        Only works on sorted arrays
    */

    if (startIndex == endIndex) {
        // Base condition if array length is 1
        if (array[startIndex] == searchElement) {
            return startIndex;
        } else {
            return -1;
        }
    } else {
        int mid = startIndex + ((endIndex - startIndex) / 2);       // This method avoids integer overflow for large values of start/endIndex
        if (array[mid] == searchElement) {
            return mid;
        } else if (array[mid] > searchElement) {
            // Re run binary search on right half of array
            binarySearch(array, startIndex, mid - 1, searchElement);
        } else {
            // Re run binary search on left half of array
            binarySearch(array, mid + 1, endIndex, searchElement);
        }
    }
}

int main() {
    // Initialize the array of user input size
    int len;                // To keep track of max size of array
    printf("Enter size of array > "); scanf("%d", &len);
    int array[len];

    // Take user input
    for (int i = 0; i < len; i++) {
        printf("%d > ", i+1); scanf("%d", &array[i]);
    }

    // Simple user menu
    printf("---------------\nA - Display List\nB - Linear Search\nC - Binary Search\n---------------\n");
    char c;
    int searchElement;
    int index; 
    while (1) {
        switch ((c = getchar())) {
            case 'A':
                displayArray(array, len);
                break;
            case 'B':
                printf("Element to search for > "); scanf("%d", &searchElement);
                index = linearSearch(array, len, searchElement);
                printf("Element at index %d\n", index);
                break;
            case 'C':
                if (isArraySorted(array, len)) {
                    printf("Element to search for > "); scanf("%d", &searchElement);
                    index = linearSearch(array, len, searchElement);
                    printf("Element at index %d\n", index);
                } else {
                    printf("Array not sorted\n");
                }
                break;
            case '\n':
                break;
            default:
                break;
        }
    }

}