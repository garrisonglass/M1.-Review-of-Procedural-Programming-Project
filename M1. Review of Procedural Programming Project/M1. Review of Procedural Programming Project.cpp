// M1. Review of Procedural Programming Project.cpp : Grade Book
//**comments to expand to rock, paper, scissors, lizard, Spock**
#include <iostream>
#include <string>
#include <iomanip>
#include <random>

using namespace std;

// Function prototypes
string getPlayerChoice();
string getNPCchoice(mt19937& rando);
int whoIsTheWinner(string player, string NPC);
void updateScores(int results, int playerScore, int NPCscore);
void displayFinal(int playerScore, int NPCscores);

int main()
{

}

string getPlayerChoice()
{
	string choice;

	while (true)
	{
		cout << "Enter rock, paper, scissors, or quit: ";
		cin >> choice;

		if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit")// **add || choice == "lizard" || choice == "Spock"**
		{
			return choice;
		}

		cout << "That isn't an option. Please try again." << endl;
	}
}

string getNPCchoice(mt19937& rando)
{
	uniform_int_distribution<int> distro(0, 2);// **2 would need to be a 4**
	int num = distro(rando);

	if (num == 0) 
		return "rock";
	if (num == 1)
		return "paper";
	return "scissors";
// include (num == 2) for "scissors", (num == 3) for "lizard" and return for "Spock"; 
}

int whoIsTheWinner(string player, string NPC)
{
	if (player == NPC)
		return 0;

	else if ((player == "rock" && NPC == "scissors") ||
		     (player == "paper" && NPC == "rock") ||
		     (player == "scissors" && NPC == "paper"))
		return 1;
	
	else
		return 2;
	
}