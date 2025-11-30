#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

bool linearsearch(string s[], string key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (key == s[i])
            return true;
    }
    return false;
}

bool binarysearh(string s[], string key, int n)
{
    int lo = 0, hi = n - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (s[mid] == key)
            return true;
        else if (s[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter no of movie: ";
    cin >> n;

    string s[10];

    cout << "Enter movie names: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    string key;

    cout << "Enter movie to search: ";
    cin >> key;

    auto start1 = chrono::high_resolution_clock::now();

    if (linearsearch(s, key, n))
        cout << "Result found";
    else
        cout << "Result not found";

    auto end1 = chrono::high_resolution_clock::now();
    auto timeLinear = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();

    // ------------------ Binary Search ------------------
    sort(s, s + n);
    auto start2 = chrono::high_resolution_clock::now();
    if (binarysearh(s, key, n))
        cout << "Result found ";
    else
        cout << "result not found";
    auto end2 = chrono::high_resolution_clock::now();
    auto timeBinary = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
    cout << "\nTimre: " << timeLinear << "  " << timeBinary;

    return 0;

}

// ✅ Algorithm
// Start
// Input number of movies n
// Declare array s[n] to store movie names
// Read all movie names
// Input movie name to search → key
// Record start time
// Apply Linear Search:
// Compare key with every element in array
// If a match is found → return true
// Record end time and calculate elapsed time for linear search
// Sort the movie list
// Record start time
// Apply Binary Search:
// Set low = 0, high = n−1
// Repeat until low > high
// Find mid = (low + high) / 2
// If key == mid element → return true
// If key < mid element → high = mid − 1
// Else → low = mid + 1
// Record end time and calculate elapsed time for binary search
// Display results and time comparison
// End

// 📝 Pseudocode
// START
// INPUT n
// DECLARE array s[n]
// PRINT "Enter movie names"
// FOR i = 0 TO n-1 DO
//     READ s[i]
// END FOR
// INPUT key to search
// // ---- Linear Search ----
// start1 = current_time
// SET found = false
// FOR i = 0 TO n-1 DO
//     IF s[i] == key THEN
//         found = true
//         BREAK
//     END IF
// END FOR
// end1 = current_time
// timeLinear = end1 - start1
// PRINT "Result found" IF found == true ELSE "Result not found"
// // ---- Binary Search ----
// SORT array s
// start2 = current_time
// SET lo = 0, hi = n - 1
// SET found = false
// WHILE lo <= hi DO
//     mid = (lo + hi) / 2
//     IF s[mid] == key THEN
//         found = true
//         BREAK
//     ELSE IF s[mid] < key THEN
//         lo = mid + 1
//     ELSE
//         hi = mid - 1
//     END IF
// END WHILE
// end2 = current_time
// timeBinary = end2 - start2
// PRINT "Result found" IF found == true ELSE "Result not found"
// PRINT timeLinear, timeBinary
// END
