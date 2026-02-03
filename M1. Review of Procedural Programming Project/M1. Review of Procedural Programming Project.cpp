// M1. Review of Procedural Programming Project.cpp : Grade Book

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Constants
const int MAX_CLASS_SIZE = 150;
const int NUM_TEST_SCORES = 5;

// Functions
int ReadData(string names[], double scores[][NUM_TEST_SCORES]);
double GetAvg(const double scores[], int size);
char GetLetterGrade(double average);
void printReport(const string names[], const double averages[], const char grades[], int count);

int main()
{
    cout << "Hello World!\n";
}
// Determines the letter grade based on average score
char GetLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
	else return 'F';
}
