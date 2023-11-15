//MP3 tic tac toe.cpp - Breanna Sproul - 16 November 2023
//Game of tic tac toe between 2 players. 
//There is no switching of x or o between players for different games. The player that gets x will keep x.
#include<iostream>
#include<string>

using namespace std;


//function prototypes
int getPlayerInput(string playerName);
bool isLegalMove(char board[], int location);
void placeMarkerOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, int playerScore, int player2Score);

int main() {
	//variables
	int player1score = 0;
	int player2score = 0;
	int ties = 0;
	bool player1turn = true;
	bool player2turn = false;
	int mark_num;
	char player1mark = 'X';
	char player2mark = 'O';
	int player1tieCheck = 0;

	//asking for player names
	cout << "Player 1 enter your name: ";
	string player1name;
	cin >> player1name;
	cout << "Player 2 enter your name: ";
	string player2name;
	cin >> player2name;
	cout << "Hello! " << player1name << " will use X, and " << player2name << " will use O. The game will now begin!" << endl;

	//making board with array
	cout << endl;
	char board[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', };
	displayBoard(board);


	while (true) {

		//player 1 turn
		while (player1turn == true) {
			//get player input
			cout << "It is " << player1name << "'s turn. ";
			mark_num = getPlayerInput(player1name);

			//check if spot is taken, if it is then ask for input again
			if (isLegalMove(board, mark_num) == false) {
				cout << "ERROR 2 - This spot is already taken. Please select another spot. ";
				mark_num = getPlayerInput(player1name);
			}

			//once input is confirmed, the mark is placed
			placeMarkerOnBoard(board, player1mark, mark_num);

			//counter for ties
			player1tieCheck += 1;

			displayBoard(board);

			//checks win and tie condiions, continues otherwise
			if (hasThreeInRow(board, player1mark) == true) {
				cout << "Congrats! " << player1name << " has won this game. ";
				player1score += 1;
				player1turn = false;
				player2turn = false;
				break;
			}
			else if (player1tieCheck == 5) {
				cout << "A tie has occured.";
				ties += 1;
				player1turn = false;
				player2turn = false;
				break;
			}
			else {
				player1turn = false;
				player2turn = true;

			}

		}

		//player 2 turn
		while (player2turn == true) {
			//get player 2 input
			cout << "It is " << player2name << "'s turn. ";
			mark_num = getPlayerInput(player2name);

			//check if spot is taken, if it is then ask for input again
			if (isLegalMove(board, mark_num) == false) {
				cout << "ERROR 2 - This spot is already taken. Please select another spot. ";
				mark_num = getPlayerInput(player2name);
			}

			//once input is confirmed, the mark is placed
			placeMarkerOnBoard(board, player2mark, mark_num);
			displayBoard(board);

			//checks win condiitons
			if (hasThreeInRow(board, player2mark) == true) {
				cout << "Congrats! " << player2name << " has won this game. ";
				player2score += 1;
				player2turn = false;
				player1turn = false;
				break;
			}
			else {
				player1turn = true;
				player2turn = false;
			}
		}

		//game has ended
		if (player1turn == false && player2turn == false) {
			//checks for player input to make a new game or quit
			displayGameStats(ties, player1score, player2score);
			cout << "Would you like to play again? Press Y to play again and Q to quit: ";
			string check;
			cin >> check;
			if (check == "Q") {
				break;
			}
			else if (check == "Y") {
				clearBoard(board);
				displayBoard(board);

				//switches the 1st player components
				//turns
				bool temp_turns = player1turn;
				player1turn = player2turn;
				player2turn = temp_turns;
				//names
				string temp_names = player1name;
				player1name = player2name;
				player2name = temp_names;
				//mark
				char temp_mark = player1mark;
				player1mark = player2mark;
				player2mark = temp_mark;
				//scores
				int temp_scores = player1score;
				player1score = player2score;
				player2score = temp_scores;
				//resets tie counter
				player1tieCheck = 0;

				//restarts the game
				player1turn = true;
			}
		}

	}
}


//function definitions


//displayGameStats - prints the # of games tied, player 1 won, player 2 won
//@param: takes in the acculated ties and scores of both players
//@return: void but couts the ties and scores
void displayGameStats(int ties, int playerScore, int player2Score) {
	cout << endl;
	cout << "Player 1 score = " << playerScore << endl;
	cout << "Player 2 score = " << player2Score << endl;
	cout << "Ties = " << ties << endl;
	return;
}

//clearBoard:  reverts the board back to original without marks
//@param: takes the current char board[] to correctly revert it back to origin
//@return: void but does reset board[] array
void clearBoard(char board[]) {
	board[0] = '1';
	board[1] = '2';
	board[2] = '3';
	board[3] = '4';
	board[4] = '5';
	board[5] = '6';
	board[6] = '7';
	board[7] = '8';
	board[8] = '9';
	return;

}

//hasThreeInRow - returns true if a win is achieved
//@param: checks the char board[] to see if a specific char playerMark has reached 3 in a row
//@return: returns true if 3 of the same mark is in a row, otherwise returns false
bool hasThreeInRow(char board[], char playerMark) {
	if (board[0] == board[1] && board[1] == board[2]) {
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5]) {
		return true;
	}
	else if (board[6] == board[7] && board[7] == board[8]) {
		return true;
	}
	else if (board[0] == board[4] && board[4] == board[8]) {
		return true;
	}
	else if (board[6] == board[4] && board[4] == board[2]) {
		return true;
	}
	else if (board[0] == board[3] && board[3] == board[6]) {
		return true;
	}
	else if (board[1] == board[4] && board[4] == board[7]) {
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[8]) {
		return true;
	}
	else { return false; }

}

//placeMarkerOnBoard - places the mark on the board once input is confirmed
//@param: uses the char board[] to place the int location of the char playerMark
//@return: doesnt return anything, but does change board[] to show the new mark
void placeMarkerOnBoard(char board[], char playerMark, int location) {
	if (playerMark == 'X') {
		board[location] = 'X';
	}
	else if (playerMark == 'O') {
		board[location] = 'O';
	}
	return;
}


//isLegalMove: true if space is open, otherwise returns false
//@param: uses board[] and the location being input by user
//@return: true if space is open otherwise returns false
bool isLegalMove(char board[], int location) {
	if (board[location] == 'X' || board[location] == 'O') {
		return false;
	}
	else {
		return true;
	}
}

// getplayerinput: indicates which square the player wants to place their mark
// @param: playername - tells which players turn it is in order to recieve input
// @return: returns a value between 1 and 9
int getPlayerInput(string playerName) {
	//user input
	cout << "Enter in which space you want to mark: ";
	int input_num;
	cin >> input_num;

	//check for numbers that dont exist on board
	if (input_num < 1 || input_num > 9) {
		while (input_num < 1 || input_num > 9) {
			cout << "ERROR 1 - Please enter an integer between 1-9. ";
			cin >> input_num;
		}
	}
	//adjust number for array usage
	int mark_num = input_num - 1;
	//cout << "Test mark_num given: " << mark_num << endl;
	return mark_num;

}


//displayBoard: prints out the current board
//@param: board[] - 1-D array for board
//@return: no return but couts board 
void displayBoard(char board[]) {
	cout << " " << board[6] << " |" << " " << board[7] << " |" << " " << board[8] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[3] << " |" << " " << board[4] << " |" << " " << board[5] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[0] << " |" << " " << board[1] << " |" << " " << board[2] << endl;
	return;
}
