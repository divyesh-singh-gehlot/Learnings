#include <iostream>

using namespace std;

struct Node {
    int songId;
    Node* prev;
    Node* next;

    Node(int id) {
        songId = id;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlayer {
    Node* head;
    Node* tail;
    Node* currentSong;

public:
    MusicPlayer() {
        head = nullptr;
        tail = nullptr;
        currentSong = nullptr;
    }

    void addSong(int songId) {
        Node* newNode = new Node(songId);
        if (head == nullptr) {
            head = tail = currentSong = newNode;
            cout << "Added song " << songId << " as the first song in the playlist." << endl;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            cout << "Added song " << songId << " to the end of the playlist." << endl;
        }
    }

    void playNext() {
        if (currentSong != nullptr && currentSong->next != nullptr) {
            currentSong = currentSong->next;
            cout << "Playing next song: " << currentSong->songId << endl;
        } else {
            cout << "No next song to play." << endl;
        }
    }

    void playPrev() {
        if (currentSong != nullptr && currentSong->prev != nullptr) {
            currentSong = currentSong->prev;
            cout << "Playing previous song: " << currentSong->songId << endl;
        } else {
            cout << "No previous song to play." << endl;
        }
    }

    void switchSong(int songId) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->songId == songId) {
                currentSong = temp;
                cout << "Switched to song: " << songId << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song " << songId << " not found in the playlist." << endl;
    }

    int current() {
        if (currentSong != nullptr) {
            return currentSong->songId;
        } else {
            return -1;
        }
    }
};

int main() {
    MusicPlayer player;
    int query, songId;
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    while (q--) {
        cout << endl;
        cout<<"Enter query:" <<endl;
        cout<<"1. Add Song" <<endl;
        cout<<"2. Play next Song" <<endl;
        cout<<"3. Play Previous Song" <<endl;
        cout<<"4. Switch Song" <<endl;
        cout<<"5. Current Song" <<endl;
        cin >> query;

        switch (query) {
            case 1:
                cout << "Enter song ID to add: ";
                cin >> songId;
                player.addSong(songId);
                break;
            case 2:
                player.playNext();
                break;
            case 3:
                player.playPrev();
                break;
            case 4:
                cout << "Enter song ID to switch to: ";
                cin >> songId;
                player.switchSong(songId);
                break;
            case 5:
                cout << "Current song ID: " << player.current() << endl;
                break;
            default:
                cout << "Invalid query! Please enter a valid option." << endl;
        }
    }

    return 0;
}
