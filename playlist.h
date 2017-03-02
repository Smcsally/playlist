// playlist.h

#include <iostream>
#include "song.h"
using namespace std;

class Playlist {
    public:
        // make an empty list
        Playlist();

        // delete the list
        ~Playlist();

        // copy constructor and operator=
        Playlist(const Playlist& other);
        Playlist& operator=(const Playlist& other);

        // add an element to the start
        void addAtStart(Song song);

        // add an element to the end
        void addAtEnd(Song song);

        // remove an element
        void remove(Song song);

        // print the list Forward
        void printForward() const;

        // print the list Backward
        void printBackward() const;

		//get the number of songs in the playlist
		int count();

		//shuffle the list
		static void shuffle(Playlist& other);

    private:
        struct Node {
            Song s;
			Node* next;
            Node* prev;
        };

        Node* head;
        Node* tail;
};


