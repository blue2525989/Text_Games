/*
 * TicTacToe.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: Jason
 */
#include <iostream>
using namespace std;

// variables used to control game flow
bool gameOver = false;
int xWin = 0;
int score = 0;
string choice = "y";
int turnRow, turnCol;

// this is the size of the game board and intial set
const int ROWS = 3;
const int COLUMNS = 3;
char board[ROWS][COLUMNS] = { {'+', '+', '+'},
								{'+', '+', '+'},
								{'+', '+', '+'} };

// checks for eight different combos
int checkCombo(char c)
{
	// go through the board for char c
	// row 0 across
	if (board[0][0] == c) {
		if (board[0][1] == c) {
			if (board[0][2] == c) {
				return 1;
			}
		}
	}
	// row 1 across
	else if (board[1][0] == c) {
		if (board[1][1] == c) {
			if (board[1][2] == c) {
				return 1;
			}
		}
	}
	// row 2 across
	else if (board[2][0] == c) {
		if (board[2][1] == c) {
			if (board[2][2] == c) {
				return 1;
			}
		}
	}
	// col 0 down
	else if (board[0][0] == c) {
		if (board[1][0] == c) {
			if (board[2][0] == c) {
				return 1;
			}
		}
	}
	// col 1 down
	else if (board[0][1] == c) {
		if (board[1][1] == c) {
			if (board[2][1] == c) {
				return 1;
			}
		}
	}
	// col 2 down
	else if (board[0][2] == c) {
		if (board[1][2] == c) {
			if (board[2][2] == c) {
				return 1;
			}
		}
	}
	// diagonal 1
	else if (board[0][0] == c) {
		if (board[1][1] == c) {
			if (board[2][2] == c) {
				return 1;
			}
		}
	}
	// diagonal 2
	else if (board[0][2] == c) {
		if (board[1][1] == c) {
			if (board[2][0] == c) {
				return 1;
			}
		}
	}
	// else return 0, left out of else clause for scope reasons
	return 0;
}

// displays the updated board
void displayBoard()
{
	// display the board
	cout<< "Here's the tic-tac-toe board:\n"<<endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			cout<< board[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

// resets the board for a new game
void resetBoard()
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			board[i][j] = '+';
		}
	}
}

// place an x or o in a specific row and column
void addSpot(char move, int row, int col)
{
	board[row][col] = move;
}

/* MAIN METHOD */
int main()
{
	// while choice is y
	while (choice == "y")
	{
		// to play or not to play is the question here
		cout<< "Would you like to play tic-tac-toe? [y/n] "<<endl;
		cin>> choice;

		// sentinel to make answer be y or n
		while (choice != "y" && choice != "n")
		{
			// ask if player wants to play game or not
			cout<< "Would you like to play tic-tac-toe? [y/n] "<<endl;
			cin>> choice;
		}

		// if y is entered
		if (choice == "y") {

			// reset all flags used
			gameOver = false;
			xWin = 0;

			// reset all spaces on board
			resetBoard();

			// display board
			displayBoard();

			// variable for taking turns
			int i = 0;

			// while gameover is false
			while (gameOver == false) {

				// even numbers for x's turn
				if (i%2==0) {
					// ask for col and row
					cout<< "X's turn, please enter the row followed by column."<<endl;
					cout<< "enter row."<<endl;
					cin>> turnRow;
					cout<< "enter column."<<endl;
					cin>> turnCol;

					// sentinel incase spot already taken
					while (board[turnRow][turnCol] == 'x' || board[turnRow][turnCol] == 'o') {
						cout<< "\nplease neter a new row and col, current choice is taken."<<endl;
						// ask for col, row again
						cout<< "enter row."<<endl;
						cin>> turnRow;
						cout<< "enter column."<<endl;
						cin>> turnCol;
					}

					// place x in spot
					addSpot('x', turnRow, turnCol);

					// display updated board
					displayBoard();

					// increment i
					++i;

					// check for combos
					score = checkCombo('x');
					// if scores a combo
					if (score == 1) {
						xWin = 1;
						gameOver = true;
					}
				}

				// odd numbers are o's turn
				else {
					// ask for col and row
					cout<<"O's turn, please enter the row followed by column."<<endl;
					cout<<"enter row."<<endl;
					cin>>turnRow;
					cout<< "enter column."<<endl;
					cin>>turnCol;

					// sentinel incase spot already taken
					while (board[turnRow][turnCol] == 'x' || board[turnRow][turnCol] == 'o') {
						cout<< "\nplease enter a new row and col, current choice is taken."<<endl;
						// ask for col, row again
						cout<<"enter row."<<endl;
						cin>>turnRow;
						cout<< "enter column."<<endl;
						cin>>turnCol;
					}

					// place o in spot
					addSpot('o', turnRow, turnCol);

					// display updated board
					displayBoard();

					// increment i
					++i;

					// check for combos
					score = checkCombo('o');
					// if scores a combo
					if (score == 1) {
						xWin = 2;
						gameOver = true;
					}
				}
			}

			// use a for loop to double check the score again
			for (int i = 0; i < 1; i++) {
				// checks if x has a combo
				score = checkCombo('x');
				// if scores a combo
				if (score == 1) {
					xWin = 1;
					gameOver = true;
				}
				// checks if o has a combo
				score = checkCombo('o');
				if (score == 1) {
					xWin = 2;
					gameOver = true;
				}
			}

			// if x wins
			if (xWin == 1) {
				cout<<"\nX won the game, good job player 1!!\n" <<endl;
				//break;
			}

			// if y wins
			else if (xWin == 2) {
				cout<<"\nO won the game, good job player 2!!\n" <<endl;
				//break;
			}
		}

		// if no is entered, game over
		else if (choice == "n") {
			cout<< "Good bye."<<endl;
			break;
		}
	}

	// exit game
	return 0;
}
