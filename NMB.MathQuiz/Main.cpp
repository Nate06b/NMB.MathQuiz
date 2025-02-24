
// Math Quiz
// Nathan Beardslee

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	
	cout << "Welcome to Math Quiz!";
	
	vector<string> questions = {
		"1 + 1 =",
		"4 / 2 =",
		"3 * 5 =",
		"7 - 4 =",
		"5 + 5 =",
		"6 / 3 =",
		"10 * 2 =",
		"8 + 8 =",
		"9 - 9 =",
		"10 / 10 ="
	};
	vector<int> answers = { 2, 2, 15, 3, 10, 2, 20, 16, 0, 1 };
	vector<string> results;
		

	for (int i = 0; i < 3; i++)
	{ // Ask 3 questions for randomization
		srand(time(NULL)); // Initialize randomization

		int index = rand() % questions.size();
		string question = questions[index];

		cout << "\nQuestion " << i + 1 << ": " << question;
		int answer;
		cin >> answer;

		if (answer == answers[index])
		{
			cout << "\nCorrect!\n";
		}
		else
		{
			cout << "\nIncorrect!\n";
		}

		results.push_back(question + " " + to_string(answer) + ": ");
	}
	cout << "\nResults: ";
	for (const string& result : results)
	{
		cout << result;
	}

	(void)_getch();
	return 0;
}
