#include <iostream>
#include "./tictactoe.cpp"
#include "./game.cpp"
using namespace std;

using namespace tictactoe;
using namespace game;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	(void)main_menu();

	bool game_ended = false;
	while (!game_ended) 
	{
		game_ended = loop();
	}

	(void)system("cls");
	(void)print_board();

	if (moves == 9) 
	{
		cout << "ITS A TIE. LOL. SKILL ISSUE." << endl;
	}
	else
	{
		cout << curr_move << " WINS." << endl;
	}

	cout.flush();
	cin.ignore();
}
