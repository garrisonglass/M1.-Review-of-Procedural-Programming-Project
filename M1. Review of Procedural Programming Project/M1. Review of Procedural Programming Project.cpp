// M1. Review of Procedural Programming Project.cpp : Grade Book

#include <iostream>
#include <string>
#include <iomanip>
#include <random>

using namespace std;

// Function prototypes
string getPlayerChoice();
string getNPCchoice(mt19937& rng);
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

		if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit")
		{
			return choice;
		}

		cout << "That isn't an option. Please try again." << endl;
	}
}
