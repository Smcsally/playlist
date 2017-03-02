//main file
#include <iostream>
#include <cstring>
#include "playlist.h"
using namespace std;

int main(){
	//make an empty list
	Playlist list;	
	
	//commands for playlist
	char user_input [15];
	char title [50];
	char artist [50]; 

	//interface
	cout << "** Playlist Manager! **" << endl;
	cout << "Commands:" << endl;
	cout << "add" << endl;
	cout << "remove" << endl;
	cout << "count" << endl;
	cout << "play" << endl;
	cout << "shuffle" << endl;
	cout << "quit" << endl;
	cout << endl;

	//main controlling loop
	while(strcmp(user_input, "quit") != 0){
		cout << ": ";
		cin >> user_input;
		cin.ignore();

		if(strcmp(user_input, "add") == 0){
			Song temp;
			cout << "Enter Title: ";
			cin.getline(title, 100);
			cout << "Enter Artist: ";
			cin.getline(artist, 100);
			temp.setTitle(title);
			temp.setArtist(artist);
			//test the creation of temp song
			//cout << "Temp: " << temp << endl;
				list.addAtEnd(temp);
		}
		else if(strcmp(user_input, "play") == 0){
			list.printForward();
		}
		else if (strcmp(user_input, "remove") == 0) {
			Song temp;
			cout << "Enter Title: ";
			cin.getline(title, 100);
			cout << "Enter Artist: ";
			cin.getline(artist, 100);
			temp.setTitle(title);
			temp.setArtist(artist);
			list.remove(temp);
			cout << endl;
		}
		else if (strcmp(user_input, "count") == 0) {
			cout << list.count();
			cout << endl;
		}
		else if (strcmp(user_input, "shuffle") == 0) {
			Playlist::shuffle(list);
		}
		else{

		}
	}
	return 0;
}
