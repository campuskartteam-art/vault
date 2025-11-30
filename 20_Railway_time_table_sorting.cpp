#include <iostream>
#include <ctime>
using namespace std;

// Insertion Sort
void insertionSort(int a[], int n) {
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
    }
}

// Selection Sort
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
}

int main(){
    int n, arr1[50], arr2[50];
    cout<<"Enter number of train arrival timings: ";
    cin>>n;

    cout<<"Enter times (24hr format e.g. 930, 1540):\n";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        arr2[i]=arr1[i];
    }

    clock_t t1=clock();
    insertionSort(arr1,n);
    clock_t t2=clock();

    clock_t t3=clock();
    selectionSort(arr2,n);
    clock_t t4=clock();

    cout<<"\nSorted Timings (Insertion Sort): ";
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<"\nTime taken = "<<float(t2-t1)<<" units";

    cout<<"\n\nSorted Timings (Selection Sort): ";
    for(int i=0;i<n;i++) cout<<arr2[i]<<" ";
    cout<<"\nTime taken = "<<float(t4-t3)<<" units\n";
}

// ⭐ Algorithm
// MAIN ALGORITHM
// Start
// Input n (number of train arrival timings)
// Declare arrays arr1 and arr2
// Input n arrival times and store them in both arrays
// Record starting time t1
// Call insertionSort(arr1, n)
// Record ending time t2
// Record starting time t3
// Call selectionSort(arr2, n)
// Record ending time t4
// Display sorted array using insertion sort and (t2 - t1) time
// Display sorted array using selection sort and (t4 - t3) time
// End

// 🔹 Insertion Sort Algorithm

// Start
// For each element from index 1 to n-1
// a. Select current value as key
// b. Compare key with previous elements
// c. Shift all elements larger than key to the right
// d. Insert key into correct position
// End

// 🔹 Selection Sort Algorithm

// Start
// For each index i from 0 to n-2
// a. Assume min = i
// b. Find smallest value in i+1 to n-1
// c. Swap smallest value with element at index i
// End

// 📌 Pseudocode
// MAIN PSEUDOCODE
// START
// INPUT n
// DECLARE array arr1[ ], arr2[ ]

// FOR i = 0 to n-1
//     INPUT arr1[i]
//     arr2[i] = arr1[i]
// END FOR

// t1 = current_time
// CALL insertionSort(arr1, n)
// t2 = current_time

// t3 = current_time
// CALL selectionSort(arr2, n)
// t4 = current_time

// PRINT "Sorted Using Insertion Sort" and arr1 values
// PRINT "Time Taken = (t2 - t1)"

// PRINT "Sorted Using Selection Sort" and arr2 values
// PRINT "Time Taken = (t4 - t3)"
// END

// 🔹 Insertion Sort Pseudocode
// FUNCTION insertionSort(a, n)
//     FOR i = 1 to n-1
//         key = a[i]
//         j = i - 1
//         WHILE j >= 0 AND a[j] > key
//             a[j + 1] = a[j]
//             j = j - 1
//         END WHILE
//         a[j + 1] = key
//     END FOR
// END FUNCTION

// 🔹 Selection Sort Pseudocode
// FUNCTION selectionSort(a, n)
//     FOR i = 0 to n-2
//         min = i
//         FOR j = i + 1 to n-1
//             IF a[j] < a[min]
//                 min = j
//             END IF
//         END FOR
//         SWAP a[i] and a[min]
//     END FOR
// END FUNCTION
