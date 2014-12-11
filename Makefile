chess:	main.cpp chess.h
	g++ -o chessGame main.cpp

clean:
	rm chessGame
	rm err.txt
	
run: chess
	./chessGame 2> err.txt

debug: chess
	./chessGame

