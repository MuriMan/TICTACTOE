#include <iostream>
#include <string>
using namespace std;

namespace game
{
	string help_texts[] = {
		"THE BOARD IS DISPLAYED IN A",
		"COORDINATE BASED FORMAT, SO",
		"YOU MUST ENTER THE COORDINATES",
		"OF YOUR DESIRED MOVE, X AND Y",
		"SEPERATED BY A SPACE.",
		"'quit' IN THE MIDDLE OF THE GAME TO QUIT."
	};
	bool is_option_valid(int option, int lb, int ub)
	{
		if (option >= lb and option <= ub)
			return true;

		return false;
	}

	void help_menu()
	{
		(void)system("cls");
		for (int i = 0; i < 5; i++)
		{
			cout << help_texts[i] << endl;
		}
		cout << "ENTER ANYTHING TO RETURN TO MAIN MENU: ";
		cout.flush();

		string s; cin >> s;
	}

	void main_menu()
	{
		system("cls");
		cout << 
				" _______ _____ _______      _______ _______ _______      _______  _____  _______ " << endl
			<<	"    |      |   |               |    |_____| |               |    |     | |______ " << endl
			<<	"    |    __|__ |______         |    |     | |______         |    |_____| |______ " << endl;
                                                                                

		cout.flush();
		cout << "1. PLAY" << endl;
		cout << "2. HELP" << endl;
		cout << "3. QUIT" << endl;

		int option; cin >> option;
		cout.flush();
		
		while (!is_option_valid(option, 1, 3))
		{
			cout << "THAT IS INVALID. RETRY: "; cout.flush();
			cin >> option;
		}

		switch (option)
		{
			case 1:
				return;
				break;
			case 2:
				(void)help_menu();
				(void)main_menu();
				break;

			case 3:
				(void)system("cls");
				(void)exit(0);
				break;
		}
	}
}
