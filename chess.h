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

		bool checkValidMove(int thisChoice){
			if(thisChoice > count || thisChoice < 1){
				cout << "Invalid Move\n";
				return false;
			}
			else
				return true;
		};

		int getCount(){
			return count;
		};

		MoveList(){
			count = 0;
		};
	
		void addMove(int r, int c){
			cerr << r << ", " << c << " is move #" << count+1 << endl;
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

	Piece* getPiece(int r, int c){
		return board[r][c];
	};

	MoveList* getMoves(int currPlayer, int r, int c){

		Piece* thisPiece = board[r][c];

		MoveList* tmpMoves = new MoveList();

		switch(tolower(thisPiece->getType())){
			case 'r':
				cout << "Rook Selected at: " << r << ", " << c << endl;
				cout << "Can Move to : \n";

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
				cout << "Horsie Selected at: " << r << ", " << c << endl;
				cout << "Can Move to \n";

				if(r < 8 && c < 7)
					if((board[r+1][c+2]->getPlayer() >= 0) && (board[r+1][c+2]->getPlayer() != currPlayer))
						tmpMoves->addMove(r+1,c+2); 				

				if(r < 7 && c < 8)
					if((board[r+2][c+1]->getPlayer() >= 0) && (board[r+2][c+1]->getPlayer() != currPlayer))
						tmpMoves->addMove(r+2,c+1); 				

				if(r > 1 && c > 0)
					if((board[r-2][c-1]->getPlayer() >= 0) && (board[r-2][c-1]->getPlayer() != currPlayer))
						tmpMoves->addMove(r-2,c-1); 				

				if(r > 0 && c > 1)
					if((board[r-1][c-2]->getPlayer() >= 0) && (board[r-1][c-2]->getPlayer() != currPlayer))
						tmpMoves->addMove(r-1,c-2); 				

				if(r < 8 && c > 1)
					if((board[r+1][c-2]->getPlayer() >= 0) && (board[r+1][c-2]->getPlayer() != currPlayer))
						tmpMoves->addMove(r+1,c-2); 				

				if(r > 0 && c < 7)
					if((board[r-1][c+2]->getPlayer() >= 0) && (board[r-1][c+2]->getPlayer() != currPlayer))
						tmpMoves->addMove(r-1,c+2); 				

				if(r < 7 && c > 0)
					if((board[r+2][c-1]->getPlayer() >= 0) && (board[r+2][c-1]->getPlayer() != currPlayer))
						tmpMoves->addMove(r+2,c-1); 				

				if(r > 1 && c < 8)
					if((board[r-2][c+1]->getPlayer() >= 0) && (board[r-2][c+1]->getPlayer() != currPlayer))
						tmpMoves->addMove(r-2,c+1); 				
		

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
				cout << "Pawn Selected at: " << r << ", " << c << endl;
				cout << "Can move to: \n";

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

			default:
				cerr << "Undefined piece selected";
			break;
		}

		return tmpMoves;
	};

	void printBoard(){
		cout << " C|1|2|3|4|5|6|7|8||\n";

		for(int r = 0; r < 10; r++){
			
			if(r == 0)
				cout << "R|";
			else
				cout << r <<'|';

			for(int c = 0; c < 10; c++){
				cout << board[r][c]->getType();
			
				if(c !=0 && c != 9)
					cout << '|';
			}

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

		

			int startR, startC, input;
			
			do{				

				cout << "Enter Row, then Col, then press Enter\n";

				cin >> input;

				startR = input/10;

				startC = input%10;

			}while(!checkValidChoice(currPlayer,startR,startC));
						
			MoveList* theseMoves = thisBoard.getMoves(currPlayer, startR, startC);
			
			theseMoves->printMoves();

			int moveChoice = 0;

			do{
				cout << "Move to: ";
				cin >> moveChoice;

			}while(!theseMoves->checkValidMove(moveChoice));

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
