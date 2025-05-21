/*
	Name: TestScores
	Copyright: 2023
	Author: Bekbol Shiribaiev
	Date: 07/10/23 18:14
	Description: This program dynamically allocates user-defined
	test scores sorts them in ascending order and calculates the average
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getNumScores(int &);
int *getTestScores(int);
void sortingScores(int [], int);
double avgScore(int [], int);
void displayScores(int [], int);

// Main test driver
int main() {
	int numScores;
	int *scores;
	getNumScores(numScores);
	scores = getTestScores(numScores);
	sortingScores(scores, numScores);
	displayScores(scores, numScores);
	avgScore(scores, numScores);
	delete [] scores;
}

// Gets the amount of scores from a user
void getNumScores(int & size) {
	cout << "How many test scores are there? ";
	cin >> size;
	if (size < 0) {
		cout << "You can't enter negative number of test scores!";
		return;
	}
	cout << endl;
}

// Gets number's data from a user
int *getTestScores(int size) {
	int *scores = nullptr;
	scores = new int[size];
	cout << "Enter the test scores: ";
	for (int i = 0; i < size; i++) {
		cin >> *(scores + i);
		if (*(scores + i) < 0) {
			cout << "You can't enter negative scores! ";
			delete [] scores;
			return nullptr;
		}
	}
	cout << endl;
	return scores;
}

// Sorts the numbers in ascending order
void sortingScores(int scores[], int size) {
	int minIndex, minValue;
	for (int i = 0; i < (size - 1); i++) {
		minIndex = i;
		minValue = scores[i];
		for (int j = i + 1; j < size; j++) {
			if (scores[j] < minValue) {
				minValue = scores[j];
				minIndex = j;
			}
		}
		swap(scores[minIndex], scores[i]);
	}
}

// Calculates the average score
double avgScore(int scores[], int size) {
	double total = 0;
	for (int i = 0; i < size; i++)
		total += scores[i];
	double avg = total / size;
	cout << fixed << setprecision(2);
	cout << "The average test score is " << avg << endl;
	return avg;
}

// Displays the scores on the screen
void displayScores(int scores[], int size) {
	cout << "Test scores: " << endl;
	for (int i = 0; i < size; i++) {
		cout << scores[i] << endl;
	}
}

