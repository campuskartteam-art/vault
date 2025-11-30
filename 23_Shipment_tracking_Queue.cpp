#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> parcel;
    int ch;
    string p;

    while(true){
        cout<<"\n1 Add Parcel\n2 Process Parcel\n3 Show Pending\n4 Exit\nEnter: ";
        cin>>ch;

        if(ch==1){
            cin>>p;
            parcel.push(p);
        }
        else if(ch==2){
            if(parcel.empty()) cout<<"No parcel!\n";
            else{ cout<<"Processed: "<<parcel.front()<<endl; parcel.pop(); }
        }
        else if(ch==3){
            queue<string> temp=parcel;
            cout<<"Pending: ";
            while(!temp.empty()){ cout<<temp.front()<<" "; temp.pop();}
            cout<<endl;
        }
        else break;
    }
}

// 🔷 Algorithm
// Start
// Declare a queue parcel
// Repeat forever:
// Display menu
// Input choice ch
// If ch == 1:
// Input parcel name
// Add (push) the parcel into queue
// Else if ch == 2:
// If queue is empty → display "No parcel"
// Else → print and remove (pop) the front parcel
// Else if ch == 3:
// Create a temporary queue temp = parcel
// Display all the elements of temp
// Else if ch == 4 → Exit loop
// End

// 🔷 Pseudocode
// DECLARE queue parcel
// DECLARE integer ch
// DECLARE string p

// REPEAT FOREVER
//     DISPLAY menu
//     READ ch

//     IF ch == 1 THEN
//         READ p
//         ENQUEUE p to parcel

//     ELSE IF ch == 2 THEN
//         IF parcel is empty THEN
//             PRINT "No parcel!"
//         ELSE
//             PRINT "Processed: " + FRONT element of parcel
//             DEQUEUE parcel

//     ELSE IF ch == 3 THEN
//         COPY parcel to temp
//         PRINT "Pending:"
//         WHILE temp is not empty
//             PRINT temp.front()
//             DEQUEUE temp
//         END WHILE

//     ELSE IF ch == 4 THEN
//         BREAK
// END REPEAT

// END
