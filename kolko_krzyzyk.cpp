#include <iostream>
#include <random>
using namespace std;

void printBoard(char board[3][3]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << board[i][j] << " ";
			if (j < 2) cout << "|";
		}
		cout << endl;
		if (i < 2) cout << "---+---+---" << endl;
	}
}

bool checkWin(char board[3][3], char symbol) {
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) return true;
	}
	if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol)) return true;

	return false;
}

int main()
{
	int a{}, b{};
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 3);

	char board[3][3]{
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	cout << "Gram kolko krzyzyk" << endl;
	for (int turn = 0; turn < 6; turn++)
	{
		int kor1, kor2;
		printBoard(board);
		cout << "Wprowadz 2 cyfry (0 - 2)(0 - 2): ";
		cin >> a >> b;
		while (a < 0 && a > 2 && b < 0 && b > 2 && board[a][b] != ' ') {
			cout << "Niepoprawne liczby! Wprowadz ponownie (0 - 2)(0 - 2) ";
			cin >> a >> b;
		}
		board[a][b] = 'X';

		if (checkWin(board, 'X'))
		{
			printBoard(board);
			cout << "Wygrales! ";
			break;
		}

		bool full = true;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board[i][j] == ' ')
					full = false;

		do
		{
			kor1 = dist(gen);
			kor2 = dist(gen);
		} while (board[kor1][kor2] != ' ');
			board[kor1][kor2] = 'O';
			cout << "Bot wygral pozycje " << kor1 << " i " << kor2 << endl;

		if (checkWin(board, 'O'))
		{
			printBoard(board);
			cout << "Przegrales! ";
			break;
		}

		if (full) {
			printBoard(board);
			cout << "remis!";
			break;
		}
	}
}
