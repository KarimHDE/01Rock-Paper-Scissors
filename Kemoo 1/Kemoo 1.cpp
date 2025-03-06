#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int NumberOfROunds()
{
	int numOfRounds;
	cout << "How many rounds you wanna play ?" << endl;
	cin >> numOfRounds;
	return numOfRounds;
}

string ChoiceToString(int choice) {
	switch (choice) {
	case 1: return "stone";
	case 2: return "paper";
	case 3: return "scissors";
	default: return "invalid choice";
	}
}

struct Game {
	int playerChoice;
	int computerChoice;
	string playagain;
};

void final_head()
{
	cout << "\n\t\t_____________________________________" << endl;
	cout << "\t\t\t  *** Game Over ***\n";
	cout << "\t\t_____________________________________" << endl;
	cout << "\t\t____________[Game Results ]__________\n";
}

void gameOver(int rounds, int playerwons, int computerwons, int draws)
{
	final_head();
	cout << "\t\tGame Rounds  : " << rounds << endl;
	cout << "\t\tPlayer wins  : " << playerwons << endl;
	cout << "\t\tComputer wins: " << computerwons << endl;
	cout << "\t\tdraws times  : " << draws << endl;
	if (playerwons > computerwons)
	{
		cout << "\t\tFinal winner : Player" << endl;
	}
	else if (computerwons > playerwons)
	{
		cout << "\t\tFinal winner : Computer" << endl;
	}
	else
	{
		cout << "\t\tFinal winner : No winner" << endl;
	}
	cout << "_________________________________________\n";
}

void startGame(int& rounds, int& playerwons, int& computerwons, int& draws)
{
	int numOfRounds;
	Game game;
	do {
		numOfRounds = NumberOfROunds();

		for (int i = 1; i <= numOfRounds; i++)
		{
			rounds++;
			cout << "Round [" << i << "] begins :\n" << endl;

			// ÇáÊÃßÏ ãä ÅÏÎÇá ÇááÇÚÈ áÞíãÉ ÕÍíÍÉ
			do {
				cout << "Your choice: [1] stone , [2] paper , [3] scissors ? ";
				cin >> game.playerChoice;
				if (game.playerChoice < 1 || game.playerChoice > 3)
				{
					cout << "Invalid choice! Please enter a number between 1 and 3.\n";
				}
			} while (game.playerChoice < 1 || game.playerChoice > 3);

			game.computerChoice = RandomNumber(1, 3);

			if (game.playerChoice == game.computerChoice)
			{
				system("color 6F");
				draws++;
				cout << "\n____________________Round [" << i << "]____________________\n";
				cout << "\nplayer   choice  : " << ChoiceToString(game.playerChoice) << "\ncomputer choice  : " << ChoiceToString(game.computerChoice) << "\nRound winner     :[No winner]" << endl;
				cout << "_________________________________________________\n";
			}
			else if ((game.playerChoice == 1 && game.computerChoice == 3) || (game.playerChoice == 2 && game.computerChoice == 1) || (game.playerChoice == 3 && game.computerChoice == 2))
			{
				system("color 2F");
				playerwons++;
				cout << "\n____________________Round [" << i << "]____________________\n";
				cout << "\nplayer   choice  : " << ChoiceToString(game.playerChoice) << "\ncomputer choice  : " << ChoiceToString(game.computerChoice) << "\nRound winner     :[player]" << endl;
				cout << "_________________________________________________\n";
			}
			else
			{
				system("color 4F");
				computerwons++;
				cout << "\a";
				cout << "\n____________________Round [" << i << "]____________________\n";
				cout << "\nplayer   choice  : " << ChoiceToString(game.playerChoice) << "\ncomputer choice  : " << ChoiceToString(game.computerChoice) << "\nRound winner     :[computer]" << endl;
				cout << "_________________________________________________\n";
			}
		}
		gameOver(rounds, playerwons, computerwons, draws);
		cout << "Do you want to play again? (y/n)" << endl;
		cin >> game.playagain;

	} while (game.playagain == "y" || game.playagain == "Y");
}

int main()
{
	srand((unsigned)time(NULL));
	int playerwons = 0, computerwons = 0, draws = 0, rounds = 0;
	startGame(rounds, playerwons, computerwons, draws);
	return 0;
}
