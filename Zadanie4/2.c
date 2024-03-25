#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        
        return binarySearch(arr, mid + 1, right, target);
    }
    
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 1, 10, 0, 66, 10, 88};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 66;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element %d nie został znaleziony.\n", target);
    else
        printf("Element %d został znaleziony na indeksie %d.\n", target, result);
    return 0;
}
