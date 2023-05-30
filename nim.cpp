#include <iostream>
#include <ctime>
using namespace std;

void generatePiles(int piles[5]);
void getHeap(int *heap, int *amount);
void takeFromPiles(int piles[5], int heap, int amount);
bool emptyPiles(int piles[5]);
void swapPlayer(int *player);
void showPiles(int piles[5]);
void showWinner(int player);

int main() {
	int piles[5];
	int heap, amount;
	int player = 1;

	generatePiles(piles);

	while(true) {
		showPiles(piles);
		getHeap(&heap, &amount);
		takeFromPiles(piles, heap, amount);

		if(emptyPiles(piles) == true) {
			showWinner(player);
			break;
		}

		swapPlayer(&player);
	}

	return 0;
}





void generatePiles(int piles[5]) {
	srand(time(NULL));

	for(int i = 0; i < 5; i++) {
		piles[i] = 5 + rand() % 15; 
	}
}

void getHeap(int *heap, int *amount) {
	cout << " Pile: ";
	cin >> *heap;

	cout << " Amount: ";
	cin >> *amount;

	*heap -= 1;
	cout << "\n";
}

void takeFromPiles(int piles[5], int heap, int amount) {
	piles[heap] -= amount;
}

bool emptyPiles(int piles[5]) {
	int count = 0;

	for(int i = 0; i < 5; i++) {
		if(piles[i] == 0)
			count += 1;
	}
	
	if(count == 5)
		return true;
	else
		return false;
}

void swapPlayer(int *player) {
	if(*player == 1)
		*player = 2;
	else
		*player = 1;
}

void showPiles(int piles[5]) {
	cout << "  ";

	for(int i = 0; i < 5; i++)
		cout << i + 1 << ": " << piles[i] << "  ";

	cout << "\n";
}

void showWinner(int player) {
	cout << "Player " << player << " won.";
}