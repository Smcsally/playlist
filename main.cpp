//main file
#include <iostream>
#include <cstring>
#include "playlist.h"
using namespace std;

int main(){
	//make an empty list
	Playlist list;	
	Song temp;
	//commands for playlist
	char user_input [15];
	char title [50];
	char artist [50]; 
	char quit [] = "quit";
	char add [] = "add";
	char remove [] = "remove";
	char count [] = "count";
	char play [] = "play";
	char shuffle [] = "shuffle";

	//interface
	cout << "** Playlist Manager! **" << endl;
	cout << "Commands:" << endl;
	cout << "add" << endl;
	cout << "remove" << endl;
	cout << "count" << endl;
	cout << "play" << endl;
	cout << "shuffle" << endl;
	cout << "quit" << endl;

	while(strcmp(user_input, quit) != 0){
		cout << ": ";
		cin >> user_input;

		if(strcmp(user_input, add) == 0){
			cout << "Enter Title: ";
			cin >> title;
			cout << "Enter Artist: ";
			cin >> artist;
			temp.setTitle(title);
			temp.setArtist(artist);
			if(list.isEmpty()){
				list.addAtStart(temp);
			}
			else{
				list.addAtEnd(temp);
			}
		}
		else if(strcmp(user_input, play) == 0){
			list.printForward();
		}
		else{

		}
	}
	return 0;
}
