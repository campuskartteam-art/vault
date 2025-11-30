
#include <iostream>
#include <chrono>
using namespace std;

// ================= Sorting Algorithms =================

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[minIndex], arr[i]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ================= Main Program =================
int main() {
    int n;
    cout << "Enter number of rooms: ";
    cin >> n;

    int prices[1000];

    cout << "\nEnter room prices:\n";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
       
    }

   auto s1 = chrono::high_resolution_clock:: now();
   bubbleSort(prices,n);
   auto e1=chrono::high_resolution_clock::now();
 auto bt = chrono::duration_cast<chrono::microseconds>(e1-s1).count();

    auto s2 = chrono::high_resolution_clock:: now();
  selectionSort(prices,n);
   auto e2=chrono::high_resolution_clock::now();
 auto st = chrono::duration_cast<chrono::microseconds>(e2-s2).count();

   auto s3 = chrono::high_resolution_clock:: now();
  insertionSort(prices,n);
   auto e3=chrono::high_resolution_clock::now();
 auto it = chrono::duration_cast<chrono::microseconds>(e3-s3).count();

 cout<<"Time: "<<bt<<endl;
 cout<<"Time: "<<st<<endl;
 cout<<"Time: "<<it<<endl;

    return 0;
}

// ✅ Algorithm
// Start
// Input n → number of rooms
// Declare an array prices[n]
// Read all room prices
// Record starting time for Bubble Sort
// Apply Bubble Sort on prices
// Record ending time and calculate execution time
// Record starting time for Selection Sort
// Apply Selection Sort on prices
// Record ending time and calculate execution time
// Record starting time for Insertion Sort
// Apply Insertion Sort on prices
// Record ending time and calculate execution time
// Display time taken by each sorting algorithm
// End

// 📝 Pseudocode
// START
// INPUT n   // number of rooms
// DECLARE array prices[n]
// PRINT "Enter room prices"
// FOR i = 0 TO n-1 DO
//     READ prices[i]
// END FOR
// // -------- Bubble Sort --------
// start1 = current_time
// CALL bubbleSort(prices, n)
// end1 = current_time
// bt = end1 - start1

// // -------- Selection Sort --------
// start2 = current_time
// CALL selectionSort(prices, n)
// end2 = current_time
// st = end2 - start2

// // -------- Insertion Sort --------
// start3 = current_time
// CALL insertionSort(prices, n)
// end3 = current_time
// it = end3 - start3

// PRINT "Time (Bubble): ", bt
// PRINT "Time (Selection): ", st
// PRINT "Time (Insertion): ", it

// END
