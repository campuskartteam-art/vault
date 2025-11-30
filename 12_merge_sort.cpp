#include <iostream>
using namespace std;

// Merge two sorted halves
void merge(int books[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data
    for(int i=0; i<n1; i++) L[i] = books[left + i];
    for(int i=0; i<n2; i++) R[i] = books[mid + 1 + i];

    int i=0, j=0, k=left;

    // Merge sorted arrays
    while(i<n1 && j<n2) {
        if(L[i] < R[j]) books[k++] = L[i++];
        else books[k++] = R[j++];
    }

    // copy remaining
    while(i<n1) books[k++] = L[i++];
    while(j<n2) books[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int books[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(books, left, mid);        // left half
        mergeSort(books, mid + 1, right);   // right half
        merge(books, left, mid, right);     // merge
    }
}

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    int books[n];
    cout << "Enter book IDs:\n";
    for(int i=0;i<n;i++) cin >> books[i];

    mergeSort(books, 0, n-1);

    cout << "\nBooks arranged by robot (sorted IDs):\n";
    for(int i=0;i<n;i++) cout << books[i] << " ";

    return 0;
}

// ✅ Algorithm (Merge Sort for Arranging Books by ID)
// Input number of books n.
// Store all book IDs in an array books[].
// Call mergeSort(books, 0, n−1).
// In mergeSort(left, right):
// If left < right, then
// Find midpoint: mid = (left + right) / 2
// Recursively sort left half: mergeSort(left, mid)
// Recursively sort right half: mergeSort(mid + 1, right)
// Call merge(left, mid, right) to combine both sorted halves
// In merge(left, mid, right):
// Create temporary arrays L[] and R[] to store left and right halves.
// Use indices to compare and merge values back into books[] in sorted order.
// Copy any remaining elements from L[] or R[].
// Output the sorted array (books in ascending order of ID).

// 🧾 Pseudo-code

// START

// INPUT n
// DECLARE array books of size n

// FOR i = 0 TO n-1 DO
//     INPUT books[i]
// END FOR

// CALL mergeSort(books, 0, n-1)

// PRINT "Books arranged (sorted IDs):"
// PRINT books array

// FUNCTION mergeSort(books, left, right)
//     IF left < right THEN
//         mid = (left + right) / 2
//         CALL mergeSort(books, left, mid)
//         CALL mergeSort(books, mid + 1, right)
//         CALL merge(books, left, mid, right)
//     END IF
// END FUNCTION

// FUNCTION merge(books, left, mid, right)
//     n1 = mid - left + 1
//     n2 = right - mid

//     CREATE arrays L[n1], R[n2]

//     FOR i = 0 TO n1-1 DO
//         L[i] = books[left + i]
//     END FOR

//     FOR j = 0 TO n2-1 DO
//         R[j] = books[mid + 1 + j]
//     END FOR

//     i = 0, j = 0, k = left

//     WHILE i < n1 AND j < n2 DO
//         IF L[i] < R[j] THEN
//             books[k] = L[i]
//             i = i + 1
//         ELSE
//             books[k] = R[j]
//             j = j + 1
//         END IF
//         k = k + 1
//     END WHILE

//     WHILE i < n1 DO
//         books[k] = L[i]
//         i = i + 1
//         k = k + 1
//     END WHILE

//     WHILE j < n2 DO
//         books[k] = R[j]
//         j = j + 1
//         k = k + 1
//     END WHILE
// END FUNCTION

// END
