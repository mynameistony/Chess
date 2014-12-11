/*TODO:
*-Continue defining piece moves
*
*
*
*
*
*
*/
#pragma once

using namespace std;

class MoveList{
	public:

		int count;

		int moves[];

		MoveList(){
			count = 0;
		};
	
		void addMove(int r, int c){
			moves[count++] = (r * 10) + c;
		};

		int getMove(int index){
			return moves[index];
		};

		void printMoves(){
			cout << "R, C\tChoose:\n";
			for(int i = 0; i < count; i++)
				cout << moves[i]/10 << ", " << moves[i]%10 << "\t" << i+1 << endl;
		};

		

};

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

		char type, symbol;
};

class Board {

	public:

	Piece* board[10][10];

	MoveList* currMoves;

	Piece* getPiece(int r, int c){
		return board[r][c];
	};

	MoveList* getMoves(int currPlayer, int r, int c){

		Piece* thisPiece = board[r][c];

		MoveList* tmpMoves = new MoveList();

		switch(tolower(thisPiece->getType())){
			case 'r':
				cerr << "Rook Selected at: " << r << ", " << c << endl;
				cerr << "Can Move to : \n";

				for(int testR = r+1; testR < 9; testR++){
					cerr << "Checking: " << testR << ", " << c << endl;
					if(board[testR][c]->getPlayer() == currPlayer)break;
					if(board[testR][c]->getPlayer() >= 0){
						tmpMoves->addMove(testR,c);
					}
				}

				for(int testR = r-1; testR > 0; testR--){
					cerr << "Checking: " << testR << ", " << c << endl;
					if(board[testR][c]->getPlayer() == currPlayer)break;
					if(board[testR][c]->getPlayer() >= 0)
						tmpMoves->addMove(testR,c);

				}

				for(int testC = c+1; testC < 9; testC++){
					cerr << "Checking: " << r << ", " << testC << endl;
					if(board[r][testC]->getPlayer() == currPlayer)break;
					if(board[r][testC]->getPlayer() >= 0){
						tmpMoves->addMove(r,testC);
					}
				}

				for(int testC = c-1; testC > 0; testC--){
					cerr << "Checking: " << r << ", " << testC << endl;
					if(board[r][testC]->getPlayer() == currPlayer)break;
					if(board[r][testC]->getPlayer() >= 0)
						tmpMoves->addMove(r,testC);

				}

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
				cerr << "Pawn Selected at: " << r << ", " << c << endl;
				cerr << "Can move to: \n";

				switch(currPlayer){
					
					case 1:
						if(r < 8){		
							if(board[r+1][c]->getPlayer() == 0){
								cerr << '[' << r+1 << ',' << c << "] " << endl;
								tmpMoves->addMove(r+1,c);								

							}
						}
						if(r < 8 && c < 8){
							if(board[r+1][c+1]->getPlayer() == 2){
								cerr << "[" << r+1 << "," << c+1 << "] " << endl;
								tmpMoves->addMove(r+1,c+1);
							}
						}
						if(r < 8 && c > 1){
							if(board[r+1][c-1]->getPlayer() == 2){
								cerr << "[" << r+1 << "," << c-1 << "] " << endl;
								tmpMoves->addMove(r+1,c-1);
							}
						}

					break;

					case 2:
						if(r > 0){
							if(board[r - 1][c]->getPlayer() == 0){
								cerr << '[' << r-1 << ',' << c << "] " << endl;
								tmpMoves->addMove(r-1,c);
							}
						}
						if(r > 0 && c < 8){
							if(board[r - 1][c + 1]->getPlayer() == 1){
								cerr << "[" << r-1 << "," << c+1 << "] " << endl;
								tmpMoves->addMove(r-1,c+1);
							}
						}
						if(r > 0 && c > 0){
							if(board[r - 1][c - 1]->getPlayer() == 1){
								cerr << "[" << r-1 << "," << c-1 << "] " << endl;
								tmpMoves->addMove(r-1,c-1);						
							}
						}
					break;	

				}
			break;
		}

		return tmpMoves;
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
							tmp = new Piece(1,'P');
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

	void movePiece(int startR, int startC, MoveList* movelist,int index){
		int newR = movelist -> getMove(index) / 10;
		int newC = movelist -> getMove(index) % 10;

		board[newR][newC] = board[startR][startC];

		board[startR][startC] = new Piece(0,'-');



	};

	
};

class Game {

	public:
		Game(){
			currPlayer = 1;
			emptySpace = new Piece(0,'-');
		};

		Board thisBoard;

		void clearScreen(){
			for(int i = 0; i < 25; i++)
				cout << endl;
		};

		void playerTurn(){
			clearScreen();
			cout << "Player " << currPlayer << "'s Turn" << endl;
			thisBoard.printBoard();

			int startR, startC, endR, endC;
			
			do{				
				cout << "Enter Row: ";
				cin >> startR;

				cout << "Enter Col: ";
				cin >> startC;

			}while(!checkValidChoice(currPlayer,startR,startC));
						
			MoveList* theseMoves = thisBoard.getMoves(currPlayer, startR, startC);
			
			cout << "Count: " << theseMoves->count << endl;
			theseMoves->printMoves();

			int moveChoice = 0;

			cout << "Move to: ";
			cin >> moveChoice;

			thisBoard.movePiece(startR, startC, theseMoves, moveChoice-1);

			if(currPlayer == 1)
				currPlayer = 2;
			else
				currPlayer = 1;

		};
		
		bool checkValidChoice(int thisPlayer, int row, int col){
			Piece* thisPiece = thisBoard.board[row][col];

			MoveList* tmpMoves = thisBoard.getMoves(thisPlayer,row,col);

			if(thisPiece->getPlayer() != thisPlayer){
				cout << "Not your piece, Try Again\n";
				return false;
			}
			else if(tmpMoves->count < 1){
				cout << "No Moves, Try Again\n";
				return false;
			}
			else
				return true;

		};

		

		Piece* emptySpace;
		int currPlayer;

};
