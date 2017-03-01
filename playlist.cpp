// playlist.cpp

#include <iostream>
#include "playlist.h"
using namespace std;

// make an empty list
Playlist::Playlist() {
    head = NULL;
    tail = NULL;
}

// delete the list
Playlist::~Playlist() {
    // remove first one until there is no first one
    while(head != NULL) {
        remove(head->s);
    }
}


// copy constructor
Playlist::Playlist(const Playlist& other) {
    Node* current = other.head;
    head = tail = NULL;
    while(current != NULL) {
        addAtEnd(current->s);
        current = current->next;
    }
}


// assignment operator
Playlist& Playlist::operator=(const Playlist& other) {
    // clear the list
    while(head != NULL) {
        remove(head->s);
    }

    // copy over the other
    Node* current = other.head;
    head = tail = NULL;
    while(current != NULL) {
        addAtEnd(current->s);
        current = current->next;
    }

    return *this;
}


// add an element to the start
void Playlist::addAtStart(Song song) {
    // make the node
    Node* node = new Node;
    node->s = song;
	cout << node->s << endl;
    node->prev = NULL;

    // if head is NULL, it's the ONLY one
    if(head == NULL) {
        head = node;
        tail = node;
        node->next = NULL;
		cout << "added to beginning of list";
    } else {
        node->next = head;
        head->prev = node;
        head = node;
		cout << "added to beginning";
    }
}

// add an element to the end
void Playlist::addAtEnd(Song song) {
    // make the node
    Node* node = new Node;
    node->s = song;
	//cout << node->s << endl;
    node->next = NULL;

    // if tail is NULL, it's the ONLY one
    if(tail == NULL) {
        head = node;
        tail = node;
        node->prev = NULL;
		//cout << "added to end of list";
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
		//cout << "added to end of list";
    }
}

// remove an element
void Playlist::remove(Song song) {
    // find the node with our number
    Node* current = head;

    while(current != NULL) {
        if(current->s == song) {
            // FOUND IT

            // if the previous is NULL, we are removing head!
            if(current->prev == NULL) {
                head = current->next;
                if(head != NULL) {
                    head->prev = NULL;
                } else {
                    tail = NULL;
                }
            } else {
                // point previous's next pointer at the one after current
                current->prev->next = current->next;

                // also point next's previous pointer to current's prev
                if(current->next != NULL) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
            }

            // delete node
            delete current;

            // return
            return;
        }

        current = current->next;
    }

    // if we got here we didn't find it!
    cout << song << " was not found in the list!" << endl;
}


// print the list Forward
void Playlist::printForward() const {
    // the node we are currently on
    Node* current = head;

    // while we're not at the end
    while(current != NULL) {
        // print the data portion
        cout << current->s << endl;

        // move onto the next one
        current = current->next;
    }
	
    cout << endl;
}

// print the list Backward
void Playlist::printBackward() const {
    // the node we are currently on
    Node* current = tail;

    // while we're not at the start
    while(current != NULL) {
        // print the data portion
        cout << current->s << endl;

        // move back to the previous one
        current = current->prev;
    }

    cout << endl << endl;
}

int Playlist::count() {
	Node* current = head;
	int count = 0;

	while (current != NULL) {
		// increment count
		count++;

		// move onto the next one
		current = current->next;
	}
	return count;
}
bool Playlist::isEmpty(){
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
}
