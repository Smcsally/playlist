// song.h

#include <iostream>
using namespace std;

class Song {
    public:
        // make an song with no name and title
        Song();

	   //make a song with a title and artist
	   Song(char name[100], char artist[100]);

        // delete the list
        //~Song();

        // copy constructor
        Song(const Song& other);

	   // overload operators
       //Song& operator=(const Song& other);
	   friend bool operator==(const Song& a, const Song& b);
	   friend ostream& operator<<(ostream& os, const Song& s);

        // set the title of the song
        void setTitle(char t[100]);

        // set the artist of the song
        void setArtist(char a[100]);

    private:
	   char title[100];
	   char artist[100];
};


