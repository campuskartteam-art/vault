#include <iostream>
#include <string>
using namespace std;

// Node class for doubly linked list
class Song {
public:
    string name;
    Song* prev;
    Song* next;

    // Constructor
    Song(string songName) {
        name = songName;
        prev = nullptr;
        next = nullptr;
    }
};

// Playlist class
class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current; // pointer to currently playing song

public:
    Playlist() {
        head = tail = current = nullptr;
    }

    // Add song at the end
    void addSong(string name) {
        Song* newSong = new Song(name);

        if(head == nullptr) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << name << " added to playlist.\n";
    }

    // Delete a song by name
    void deleteSong(string name) {
        Song* temp = head;
        while(temp != nullptr) {
            if(temp->name == name) {
                if(temp->prev != nullptr)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if(temp->next != nullptr)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                if(current == temp)
                    current = temp->next ? temp->next : temp->prev;

                delete temp;
                cout << name << " deleted from playlist.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found!\n";
    }

    // Play next song
    void nextSong() {
        if(current == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        if(current->next != nullptr) {
            current = current->next;
            cout << "Playing: " << current->name << endl;
        } else {
            cout << "Already at the last song!\n";
        }
    }

    // Play previous song
    void prevSong() {
        if(current == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        if(current->prev != nullptr) {
            current = current->prev;
            cout << "Playing: " << current->name << endl;
        } else {
            cout << "Already at the first song!\n";
        }
    }

    // Show playlist
    void display() {
        if(head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        Song* temp = head;
        cout << "Playlist: ";
        while(temp != nullptr) {
            if(temp == current)
                cout << "[" << temp->name << "] "; // indicate current song
            else
                cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ================= Main Function =================
int main() {
    Playlist playlist;
    int choice;
    string name;

    do {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Play Next Song\n";
        cout << "4. Play Previous Song\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter song name to add: ";
                cin.ignore();
                getline(cin, name);
                playlist.addSong(name);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                cin.ignore();
                getline(cin, name);
                playlist.deleteSong(name);
                break;

            case 3:
                playlist.nextSong();
                break;

            case 4:
                playlist.prevSong();
                break;

            case 5:
                playlist.display();
                break;

            case 6:
                cout << "Exiting playlist simulation.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 6);

    return 0;
}


// ✅ Algorithm
// Initialization
// Start
// Create class Song with fields → name, prev, next
// Create class Playlist with pointers → head, tail, current
// Initialize head = tail = current = NULL

// Operation 1: Add Song
// Input songName
// Create new node newSong
// If playlist is empty (head == NULL)
// Set head = tail = current = newSong
// Else
// Set tail->next = newSong
// Set newSong->prev = tail
// Update tail = newSong
// Print "Song added"

// Operation 2: Delete Song
// Input songName
// Set pointer temp = head
// Search list until temp->name == songName OR temp == NULL
// If song not found → print "Song not found" and stop
// Else remove node:
// If deleting first node → update head = temp->next
// If deleting last node → update tail = temp->prev
// If middle node → link temp->prev->next = temp->next and temp->next->prev = temp->prev
// If current == temp → update current to next song if exists otherwise previous
// Delete temp
// Print "Song deleted"
    
// Operation 3: Play Next Song
// If playlist empty (current == NULL) → print "Playlist empty"
// Else if current->next != NULL
// current = current->next
// Print "Playing current->name"
// Else print "Already at last song"

// Operation 4: Play Previous Song
// If playlist empty (current == NULL) → print "Playlist empty"
// Else if current->prev != NULL
// current = current->prev
// Print "Playing current->name"
// Else print "Already at first song"

// Operation 5: Display Playlist
// If head == NULL → print "Playlist empty"
// Else traverse from head to tail
// While traversing print song names
// Mark current song as [name]
// End Program
// Repeat menu until user chooses Exit
// Stop

// 🧾 Pseudo Code

// START

// CREATE Song node (name, prev, next)
// CREATE Playlist with head = NULL, tail = NULL, current = NULL

// FUNCTION addSong(name):
//     CREATE newSong
//     IF head == NULL THEN
//         head = tail = current = newSong
//     ELSE
//         tail.next = newSong
//         newSong.prev = tail
//         tail = newSong
//     ENDIF
//     PRINT "Song added"

// FUNCTION deleteSong(name):
//     temp = head
//     WHILE temp != NULL AND temp.name != name DO
//         temp = temp.next
//     ENDWHILE
//     IF temp == NULL THEN
//         PRINT "Song not found"
//         RETURN
//     ENDIF

//     IF temp.prev != NULL THEN
//         temp.prev.next = temp.next
//     ELSE
//         head = temp.next
//     ENDIF

//     IF temp.next != NULL THEN
//         temp.next.prev = temp.prev
//     ELSE
//         tail = temp.prev
//     ENDIF

//     IF current == temp THEN
//         IF temp.next != NULL THEN
//             current = temp.next
//         ELSE
//             current = temp.prev
//         ENDIF
//     ENDIF

//     DELETE temp
//     PRINT "Song deleted"

// FUNCTION nextSong():
//     IF current == NULL THEN
//         PRINT "Playlist empty"
//     ELSE IF current.next != NULL THEN
//         current = current.next
//         PRINT "Playing current.name"
//     ELSE
//         PRINT "Already at last song"
//     ENDIF

// FUNCTION prevSong():
//     IF current == NULL THEN
//         PRINT "Playlist empty"
//     ELSE IF current.prev != NULL THEN
//         current = current.prev
//         PRINT "Playing current.name"
//     ELSE
//         PRINT "Already at first song"
//     ENDIF

// FUNCTION display():
//     IF head == NULL THEN
//         PRINT "Playlist empty"
//     ELSE
//         temp = head
//         WHILE temp != NULL DO
//             IF temp == current THEN
//                 PRINT "[" + temp.name + "]"
//             ELSE
//                 PRINT temp.name
//             ENDIF
//             temp = temp.next
//         ENDWHILE
//     ENDIF

// REPEAT
//     DISPLAY menu
//     INPUT choice
//     SWITCH(choice):
//         CASE 1: INPUT songName; addSong(songName)
//         CASE 2: INPUT songName; deleteSong(songName)
//         CASE 3: nextSong()
//         CASE 4: prevSong()
//         CASE 5: display()
//         CASE 6: PRINT "Exit"
//         DEFAULT: PRINT "Invalid choice"
//     END SWITCH
// UNTIL choice == 6

// STOP


