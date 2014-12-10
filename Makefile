chess:	main.cpp chess.h
	g++ -o chessGame main.cpp

clean:
	rm chessGame
	
run: chess
	./chessGame

