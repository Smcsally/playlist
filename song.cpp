// song.cpp

#include <iostream>
#include <cstring>
#include "song.h"

using namespace std;

//make a song with no name and title
Song::Song(){
	title = new char[100];
	artist = new char[100];
}

//make a song with a title and artist
Song::Song(char t[], char a[]){
	title = new char[strlen(t)];
	artist = new char[strlen(a)];
	strcpy(title, t);
	strcpy(artist, a);
}

//delete the list
Song::~Song(){
	delete [] title;
	delete [] artist;
}

Song::Song(const Song& other){
	title = new char[100];
	artist = new char[100];

	strcpy(title, other.title);
	strcpy(artist, other.artist);
}
/*overload = operator
  Song::Song& operator=(const Song& other){
  strcpy(this.title, other.getTitle());
  strcpy(this.artist, other.getArtist());
  }*/

//overload == operator
bool operator==(const Song& a, const Song& b){
	if(strcmp(a.title,b.title) == 0 && strcmp(a.artist, b.artist) == 0){
		return true;
	}
	else{
		return false;
	}
}

//overload >> operator
ostream& operator<<(ostream& os, const Song& s){
	os << s.title << " - " << s.artist;

	return os;
}

void Song::setTitle(char t[]){
	strcpy(title, t);
}

void Song::setArtist(char a[]){
	strcpy(artist, a);
}
