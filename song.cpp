// song.cpp

#include <iostream>
#include <cstring>
#include <atlstr.h>
#include "song.h"

using namespace std;

//make a song with no name and title
Song::Song(){
	strcpy(title, "0");
	strcpy(artist, "0");
}

//make a song with a title and artist
Song::Song(char t[100], char a[100]){
	strcpy(title, t);
	strcpy(artist, a);
}

//delete the list
/*Song::~Song(){
	delete [] title;
	delete [] artist;
}*/

Song::Song(const Song& other){
	strcpy(title, other.title);
	strcpy(artist, other.artist);
}


//overload == operator
bool operator==(const Song& a, const Song& b){
	if(strcmp(a.title,b.title) == 0 && strcmp(a.artist, b.artist) == 0){
		return true;
	}
	else{
		return false;
	}
}

//overload << operator
ostream& operator<<(ostream& os, const Song& s) {
	os << s.title << " - " << s.artist;

	return os;
}

void Song::setTitle(char t[100]){
	strcpy(title, t);
}

void Song::setArtist(char a[100]){
	strcpy(artist, a);
}
