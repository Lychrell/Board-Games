#include <iostream>
#include <ctime>
#include <cctype>
using namespace std;

string pickWord(string word[25]);
string getInput();
int checkGuess(string answer, string guess, int hint[5]);
void showHints(string guess, int hint[5]);

int main() {
	string word[25] = {
		"about", "after", "could", "early", "every", 
		"first", "found", "great", "group", "house", 
		"large", "later", "never", "often", "other", 
		"small", "still", "there", "think", "those", 
		"under", "until", "where", "while", "world"
	};
	string guess, answer;
	int hint[5];
	int correctGuess;

	answer = pickWord(word);

	while(true) {
		guess = getInput();
		correctGuess = checkGuess(answer, guess, hint);

		if(correctGuess == 5) {
			cout << " You got the word!";
			break;
		}

		showHints(guess, hint);
	}

	return 0;
}





string pickWord(string word[25]) {
	int choice;

	srand(time(NULL));
	choice = 1 + rand() % 25;

	return word[choice];
}

string getInput() {
	string input;

	cout << "  Guess: ";
	cin >> input;

	return input;
}

int checkGuess(string answer, string guess, int hint[5]) {
	int correctGuess = 0;

	for(int i = 0; i < guess.length(); i++) {
		guess[i] = tolower(guess[i]);
		if(answer[i] == guess[i]) {
			hint[i] = 2;
			correctGuess++;
		}
		else if(answer.find(guess[i]) != string::npos) {
			hint[i] = 1;
			answer[answer.find(guess[i])] = ' ';
		}
		else
			hint[i] = 0;
	}
	
	return correctGuess;
}

void showHints(string guess, int hint[5]) {
	int correctGuess = 0;
	int correctLetter = 0;
	cout << "  ";

	for(int i = 0; i < 5; i++) {
		if(hint[i] == 2) {
			cout << "[" << guess[i] << "] ";
			correctGuess++;
		}
		else if(hint[i] == 1) {
			cout << "(" << guess[i] << ") ";
			correctLetter++;
		}
		else
			cout << guess[i] << " ";
	}

	cout << "\n";
	cout << " Correct guess: " << correctGuess << ", ";
	cout << "correct letter: " << correctLetter << "\n\n";
}