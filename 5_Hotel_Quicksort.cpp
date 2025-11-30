#include <iostream>
using namespace std;

// Quick Sort function to sort room prices
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // last element taken as pivot
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int main() {
    int n;

    cout << "Enter number of rooms: ";
    cin >> n;

    int price[n];
    cout << "Enter room prices:\n";
    for(int i=0;i<n;i++)
        cin >> price[i];

    // sorting using quick sort
    quickSort(price, 0, n-1);

    cout << "\nSorted room prices: ";
    for(int i=0;i<n;i++)
        cout << price[i] << " ";
}

// ✅ Algorithm
// Start
// Input number of rooms n
// Declare array price[n]
// Accept all room prices in the array
// Call Quick Sort with parameters: array, low = 0, high = n − 1
// In partition() function:
// Select the last element as pivot
// Rearrange array so elements smaller than pivot are on left and greater on right
// Return the index p (pivot correct position)
// Recursively apply Quick Sort:
// On left sub-array (low → p−1)
// On right sub-array (p+1 → high)
// After sorting, display sorted room prices
// End

// 📝 Pseudocode
// START

// INPUT n
// DECLARE array price[n]

// PRINT "Enter room prices"
// FOR i = 0 TO n-1 DO
//     READ price[i]
// END FOR

// CALL quickSort(price, 0, n-1)

// PRINT "Sorted room prices:"
// FOR i = 0 TO n-1 DO
//     PRINT price[i]
// END FOR

// END


// FUNCTION quickSort(arr, low, high)
//     IF low < high THEN
//         p = partition(arr, low, high)
//         CALL quickSort(arr, low, p-1)
//         CALL quickSort(arr, p+1, high)
//     END IF
// END FUNCTION

// FUNCTION partition(arr, low, high)
//     pivot = arr[high]
//     i = low - 1

//     FOR j = low TO high - 1 DO
//         IF arr[j] < pivot THEN
//             i = i + 1
//             SWAP arr[i] and arr[j]
//         END IF
//     END FOR

//     SWAP arr[i+1] and arr[high]
//     RETURN i + 1
// END FUNCTION

