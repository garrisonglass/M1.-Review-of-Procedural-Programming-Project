// M1. Review of Procedural Programming Project.cpp : Rock, Paper, Scissors

#include <iostream>
#include <string>
#include <random>

using namespace std;

// Function prototypes
string getPlayerChoice();
string getNPCchoice(mt19937& rando);
int whoIsTheWinner(const string& player, const string& NPC);
void updateScores(int results, int& playerScore, int& NPCscore);
void displayFinal(int playerScore, int NPCscore);

int main()
{
// Random number generator setup
	random_device rd;
	mt19937 rando(rd());

	int playerScore = 0;
	int NPCscore = 0;

	cout << "Welcome to Rock, Paper, Scissors!\n";

	while (true)
	{
		string player = getPlayerChoice();

		if (player == "quit")
			break;

		string NPC = getNPCchoice(rando);

		cout << "Computer choise: " << NPC << endl;

		int result = whoIsTheWinner(player, NPC);
		updateScores(result, playerScore, NPCscore);

		if (result == 0)
			cout << "It's a draw!" << endl;
		else if (result == 1)
			cout << "You win this round!" << endl;
		else
			cout << "Computer wins this round!" << endl;

		    cout << "Current Score - You: " << playerScore
			     << " | Computer: " << NPCscore << endl;
	}
	displayFinal(playerScore, NPCscore);

}
// Prompts and validates the player's choice
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
			choice == "quit")
		{
			return choice;
		}

		cout << "That isn't an option. Please try again." << endl;
	}
}
//Randomly generates the computer's choice using <random>
string getNPCchoice(mt19937& rando)
{
	uniform_int_distribution<int> distro(0, 2);
	int num = distro(rando);

	if (num == 0)
		return "rock";
	if (num == 1)
		return "paper";
	    return "scissors";
}
// Determines winner of a round
// Returns: 0 = draw, 1 = player wins, 2 = computer wins
int whoIsTheWinner(const string& player, const string& NPC)
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
// Updates scores based results from each round
void updateScores(int results, int& playerScore, int& NPCscore)
{
	if (results == 1)
		playerScore++;
	else if (results == 2)
		NPCscore++;
}
// Displays final results
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
// Future expansion: Rock-Paper-Scissors-Lizard-Spock
// Player Input:
// -Allow "lizard" and "Spock" as valid entries in getPlayerChoice()
// NPC choice:
// -Change uniform_int_distribution range from (0, 2) to (0, 4).
// - Map: 
// 0 -> rock 
// 1 -> paper 
// 2 -> scissors 
// 3 -> lizard 
// 4 -> spock
// Winner Logic (whoIsTheWinner):
// As Sheldon Cooper famously summarizes:
//
// "Scissors cuts Paper
// Paper covers Rock
// Rock crushes Lizard
// Lizard poisons Spock
// Spock smashes Scissors
// Scissors decapitates Lizard
// Lizard eats Paper
// Paper disproves Spock
// Spock vaporizes Rock
// ...and as it always has, Rock crushes Scissors."
//
// No change to updateScores() or displayFinal() as they will already support this.
