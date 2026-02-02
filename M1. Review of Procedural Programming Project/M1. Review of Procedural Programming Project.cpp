// M1. Review of Procedural Programming Project.cpp : Grade Book

#include <iostream>

using namespace std;

// Constants
const int MAX_CLASS_SIZE = 150;
const int NUM_TEST_SCORES = 5;

// Functions
int ReadData(string nmaes[], double scores[][NUM_TEST_SCORES]);
double GetAvg(const double scores[], int size);
char GetLetterGrade(double average);
void printReport(const string names[], const double avergaes[], const char grades[], int count);

int main()
{
    cout << "Hello World!\n";
}

