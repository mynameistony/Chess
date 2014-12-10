#pragma once

using namespace std;

class Piece {
	public:
		Piece(int newPlayer, char newType){

			player = newPlayer;

			type = newType;
		};

		int getPlayer(){
			return player;
		};
		
		char getType(){
			return type;
		};
		void printInfo(){
			std::cout << "Player: " << player << "\tType: " << type << std::endl;
		};

		int player;

		char type;
};

class Board {

	public:

	Piece* board[10][10];

	Piece* getPiece(int r, int c){
		return board[r][c];
	};

	void showMoves(int currPlayer, int r, int c){

		Piece* thisPiece = board[r][c];

		switch(thisPiece->getType()){
			case 'r':
				cout << "Rook Selected\n";
			break;

			case 'h':
				cout << "Knight Selected\n";
			break;

			case 'b':
				cout << "Bishop Selected\n";
			break;

			case 'k':
				cout << "King Selected\n";
			break;

			case 'q':
				cout << "Queen Selected\n";
			break;

			case 'p':
				cout << "Pawn Selected\n";
				switch(currPlayer){
					
					case 1:
						if(r < 8)						
							if(board[r+1][c]->getPlayer() == 0)
								cout << '[' << r+1 << ',' << c << "] " << endl;
						if(r < 8 && c < 8)
							if(board[r+1][c+1]->getPlayer() == 2)
								cout << "[" << r+1 << "," << c+1 << "] " << endl;
						if(r < 8 && c > 1)
							if(board[r+1][c-1]->getPlayer() == 2)
								cout << "[" << r+1 << "," << c-1 << "] " << endl;
					break;

					case 2:
						cout << "Available Moves:\n";
						if(r > 0)
							if(board[r - 1][c]->getPlayer() == 0)
								cout << '[' << r-1 << ',' << c << "] " << endl;
						if(r > 0 && c < 8)
							if(board[r - 1][c + 1]->getPlayer() == 2)
								cout << "[" << r-1 << "," << c+1 << "] " << endl;
						if(r > 0 && c > 0)
							if(board[r - 1][c - 1]->getPlayer() == 2)
								cout << "[" << r-1 << "," << c-1 << "] " << endl;
					break;	

				}
			break;
		}
	};

	void printBoard(){
		cout << "$|0|1|2|3|4|5|6|7|8|$\n";

		for(int r = 0; r < 10; r++){
			cout << r <<'|';

			for(int c = 0; c < 10; c++)
				cout << board[r][c]->getType() << '|';

			cout << endl;
		}

	};

	Board(){

		for(int r = 0; r < 10; r++)
			for(int c = 0; c < 10; c++)
				board[r][c] = new Piece(0,'-');

		Piece* tmp;
		for(int r = 0; r < 10; r++){	
			for(int c = 0; c < 10; c++){

				switch(r){
					case 1:
						switch(c){
							case 1:tmp = new Piece(1,'R');break;
		
							case 2:tmp = new Piece(1,'H');break;

							case 3:tmp = new Piece(1,'B');break;

							case 4:tmp = new Piece(1,'Q');break;

							case 5:tmp = new Piece(1,'K');break;

							case 6:tmp = new Piece(1,'B');break;

							case 7:tmp = new Piece(1,'H');break;

							case 8:tmp = new Piece(1,'R');break;

							default:tmp = new Piece(-1,'|');break;
						}
					break;
					case 2:
						if(c == 0 || c == 9)
							tmp = new Piece(-1,'|');
						else
							tmp = new Piece(1,'p');
					break;

					case 3:
						if(c == 0 || c == 9)
							tmp = new Piece(-1,'|');
						else
							tmp = new Piece(0,'-');					
					break;
					case 4:
						if(c == 0 || c == 9)
							tmp = new Piece(-1,'|');
						else
							tmp = new Piece(0,'-');					
					break;
					case 5:
						if(c == 0 || c == 9)
							tmp = new Piece(-1,'|');
						else
							tmp = new Piece(0,'-');					
					break;
					case 6:
						if(c == 0 || c == 9)
							tmp = new Piece(-1,'|');
						else
							tmp = new Piece(0,'-');
					break;
					case 7:
						if(c == 0 || c == 9)
							tmp = new Piece(-1,'|');
						else
							tmp = new Piece(2,'p');					
					break;

					case 8:
						switch(c){
						
							case 1:tmp = new Piece(2,'r');break;
	
							case 2:tmp = new Piece(2,'h');break;

							case 3:tmp = new Piece(2,'b');break;

							case 4:tmp = new Piece(2,'k');break;

							case 5:tmp = new Piece(2,'q');break;

							case 6:tmp = new Piece(2,'b');break;

							case 7:tmp = new Piece(2,'h');break;

							case 8:tmp = new Piece(2,'r');break;

							default:tmp = new Piece(-1,'|');break;
						
						}


					break;

					case 0:
						tmp = new Piece(-1,'|');						
					break;

					case 9:
						tmp = new Piece(-1,'|');						
					break;
				}

				board[r][c] = tmp;

			}

		}
				
	};

	void movePiece(int startRow, int startCol, int endRow, int endCol){
		board[endRow][endCol] = board[startRow][startCol];
		board[startRow][startCol] = new Piece(0,'-');
	};

	
};

class Game {

	public:
		Game(){
			currPlayer = 1;
			emptySpace = new Piece(0,'-');
		};

		Board thisBoard;


		void playerTurn(){

			cout << "Player " << currPlayer << "'s Turn" << endl;
			thisBoard.printBoard();

			int startR, startC, endR, endC;
			
			do{				
				cout << "Enter Row: ";
				cin >> startR;

				cout << "Enter Col: ";
				cin >> startC;

			}while(!checkValidChoice(currPlayer,startR,startC));
						
			thisBoard.showMoves(currPlayer, startR, startC);

//			cout << "Move to: ";
//			cin >> moveChoice;

			cout << "Enter Row: ";
			cin >> endR;

			cout << "Enter Col: ";
			cin >> endC;
			
//			cerr << startR << "," << startC << "->" << endR << "," << endC << endl; 
//			cerr << thisBoard.board[startR][startC]->getType() << "->" << thisBoard.board[endR][endC]->getType();  	

//			thisBoard.board[endR][endC] = thisBoard.board[startR][startC];
//			thisBoard.board[endR][endC] = emptySpace;

//			cerr << thisBoard.board[startR][startC]->getType() << "->" << thisBoard.board[endR][endC]->getType();  	
			

			thisBoard.movePiece(startR, startC, endR, endC);

			if(currPlayer == 1)
				currPlayer = 2;
			else
				currPlayer = 1;

		};
		
		bool checkValidChoice(int thisPlayer, int row, int col){
			Piece* thisPiece = thisBoard.board[row][col];

			bool canMove = false;
			
			if(thisPiece->getPlayer() != thisPlayer){
				cout << "\rTry Again\n";
				return canMove;
			}
			else{
				return true;
			}

		};

		

		Piece* emptySpace;
		int currPlayer;

};
