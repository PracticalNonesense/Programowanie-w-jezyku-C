#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        // Jeśli element znajduje się w środku
        if (arr[mid] == target)
            return mid;
        
        // Jeśli element jest mniejszy od środkowego, to szukaj w lewej połowie
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        
        // W przeciwnym razie szukaj w prawej połowie
        return binarySearch(arr, mid + 1, right, target);
    }
    
    // Jeśli element nie jest obecny w tablicy
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
