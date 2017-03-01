# macros
FLAGS = -g

# make the main program
playlist: playlist.o main.o song.o
	clang++ $(FLAGS) playlist.o main.o song.o -o playlist
	@echo "All done"

# make the playlist object file
playlist.o: playlist.cpp playlist.h song.h
	clang++ $(FLAGS) -c playlist.cpp

# make the main object file
main.o: main.cpp playlist.h song.h
	clang++ $(FLAGS) -c main.cpp

# make the song object file
song.o: song.cpp song.h
	clang++ $(FLAGS) -c song.cpp

# delete unneeded files
clean:
	rm -f playlist *.o
