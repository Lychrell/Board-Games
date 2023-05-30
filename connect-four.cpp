#include <iostream>
using namespace std;

void resetBoard(char board[6][7]);
int getPosition();
int dropPiece(char board[6][7], int col, char piece);
bool hasWinner(char board[6][7], char piece, int row, int col);
void swapPlayer(char *piece);
void showBoard(char board[6][7]);
void showWinner(char currentPiece);

int main() {
	char board[6][7];
	int col, row;
	char currentPiece;

	resetBoard(board);
	currentPiece = '+';
	showBoard(board);

	while(true) {
		col = getPosition();
		row = dropPiece(board, col, currentPiece);

		showBoard(board);

		if(hasWinner(board, currentPiece, row, col) == true) {
			showWinner(currentPiece);
			break;
		}
		swapPlayer(&currentPiece);
	}

	return 0;
}





void resetBoard(char board[6][7]) {
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 7; j++) {
			board[i][j] = ' ';
		}
	}
}

void getPosition() {
	int col;

	cout << "Column: ";
	cin >> *col;

	*col -= 1;
	cout << endl;

	return col;
}

int dropPiece(char board[6][7], int col, char piece) {
	int row = 0;

	while(row < 6 && board[row+1][col] == ' ')
		row += 1;

	board[row][col] = piece;
	return row;
}

void swapPlayer(char *piece) {
	if(*piece == '+')
		*piece = '-';
	else
		*piece = '+';
}

void showBoard(char board[6][7]) {
	for(int i = 0; i < 6; i++) {
		cout << "   " << "|" << " ";
		for(int j = 0; j < 7; j++) {
			cout << board[i][j] << " ";
		}
		cout << "|" << "\n";
	}

	cout << "     1 2 3 4 5 6 7\n\n";
}

void showWinner(char currentPiece) {
	if(currentPiece == '+')
		cout << "Player 1 won."
	else
		cout << "Player 2 won."
}




int checkHorizontal(char board[6][7], char piece, int row, int col);
int checkVertical(char board[6][7], char piece, int row, int col);
int checkLeftDiagonal(char board[6][7], char piece, int row, int col);
int checkRightDiagonal(char board[6][7], char piece, int row, int col);

bool hasWinner(char board[6][7], char piece, int row, int col) {
	if(checkHorizontal(board, piece, row, col) >= 4)
		return true;
	if(checkVertical(board, piece, row, col) >= 4)
		return true;
	if(checkLeftDiagonal(board, piece, row, col) >= 4)
		return true;
	if(checkRightDiagonal(board, piece, row, col) >= 4)
		return true;

	return false;
}

int checkHorizontal(char board[6][7], char piece, int row, int col) {
	int count;
	int i, j;

	i = row;
	j = col;
	count = 0;

	while(board[i][j] == piece) {
		count++;
		j -= 1;
	}

	j = col + 1;
	while(board[i][j] == piece) {
		count++;
		j += 1;
	}

	return count;
}

int checkVertical(char board[6][7], char piece, int row, int col) {
	int count;
	int i, j;

	i = row;
	j = col;
	count = 0;

	while(board[i][j] == piece) {
		count++;
		i -= 1;
	}

	i = row + 1;
	while(board[i][j] == piece) {
		count++;
		i += 1;
	}

	return count;
}

int checkLeftDiagonal(char board[6][7], char piece, int row, int col) {
	int count;
	int i, j;

	i = row;
	j = col;
	count = 0;

	while(board[i][j] == piece) {
		count++;
		i -= 1;
		j -= 1;
	}


	i = row + 1;
	j = col + 1;

	while(board[i][j] == piece) {
		count++;
		i += 1;
		j += 1;
	}

	return count;
}

int checkRightDiagonal(char board[6][7], char piece, int row, int col) {
	int count;
	int i, j;

	i = row;
	j = col;
	count = 0;

	while(board[i][j] == piece) {
		count++;
		i -= 1;
		j += 1;
	}


	i = row + 1;
	j = col - 1;

	while(board[i][j] == piece) {
		count++;
		i += 1;
		j -= 1;
	}

	return count;
}