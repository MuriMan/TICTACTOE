#include <iostream>
#include <string>
using namespace std;

namespace tictactoe
{
	const int BOARD_LENGTH = 3;

	string board[BOARD_LENGTH] = {
		"___",
		"___",
		"___"
	};

	void print_board()
	{
		cout << "  1 2 3" << endl;

		for (int i = 0; i < BOARD_LENGTH; i++)
		{
			cout << i + 1 << " ";
			for (int j = 0; j < 3; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout.flush();
	}

	bool move_is_valid(int x, int y)
	{
		if (y < 0 or y > 2)
			return false;
		if (x < 0 or x > 2)
			return false;

		if (board[y][x] != '_')
			return false;

		return true;
	}
	
	int moves = 0;
	char curr_move = 'X';
	
	void take_move()
	{
		cout << "ENTER YOUR MOVE " << curr_move << "-PLAYER: " << endl;
		curr_move = moves % 2 == 0 ? 'X' : 'O';

		string s; getline(cin, s);
		if (s == "quit")
		{
			(void)system("cls");
			(void)exit(0);
		}

		int x, y; cin >> x >> y;
		x--; y--;

		while (!move_is_valid(x, y))
		{
			cout << "THAT IS INVALID. RETRY: " << endl;
			cin >> x >> y;
			x--; y--;
		}

		board[y][x] = curr_move;
		
		moves++;
	}

	bool check_win()
	{
		for (int i = 0; i < BOARD_LENGTH; i++)
		{
			if (board[i] == "XXX" or board[i] == "OOO")
				return true;
		}

		for (int i = 0; i < BOARD_LENGTH; i++)
		{
			if(board[0][i] == board[1][i] and board[1][i] == board[2][i] and board[0][i] != '_')
				return true;
		}

		if (board[0][0] == board[1][1] and board[1][1] == board[2][2])
			return true;
		if (board[2][0] == board[1][1] and board[1][1] == board[0][2])
			return true;

		return false;
	}

	bool loop()
	{
		(void)system("cls");
		(void)print_board();
		(void)take_move();

		if (moves == 9)
			return true;

		if (moves > 4)
			return check_win();

		return false;
	}
}
