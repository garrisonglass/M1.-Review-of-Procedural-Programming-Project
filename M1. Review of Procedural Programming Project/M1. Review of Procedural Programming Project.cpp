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
// Random number generator setup
	random_device rd;
	mt19937 rando(rd());

	cout << "Welcome to Rock, Paper, Scissors!\n";
}

string getPlayerChoice()
{
	string choice;

	while (true)
	{
		cout << "Enter rock, paper, scissors, or quit: ";
		cin >> choice;

		if (choice == "rock" || 
			choice == "paper" || 
			choice == "scissors" || 
			choice == "quit")// **add || choice == "lizard" || choice == "Spock"**
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
// **include (num == 2) for "scissors", (num == 3) for "lizard" and return for "Spock";** 
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

void updateScores(int results, int playerScore, int NPCscore)
{
	if (results == 1)
		playerScore++;
	else if (results == 2)
		NPCscore++;
}

void displayFinal(int playerScore, int NPCscore)
{
	cout << "\n--- Final Results ---\n";
	cout << "Your Score: " << playerScore << endl;
	cout << "Computer Score: " << NPCscore << endl;

	if (playerScore > NPCscore)
		cout << "You are the winner!" << endl;
	else if (NPCscore > playerScore)
		cout << "Computer wins!" << endl;
	else
		cout << "The game ends in a draw!" << endl;
}