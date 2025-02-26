
// Math Quiz
// Nathan Beardslee

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	// creating filePath and line variables to use for input and output 
	string filePath = "QuizResults.txt";
	string line;	


	

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
	

	// Save results to file
	ofstream ofs(filePath);
	if (ofs)
	{
for (const string& result : results)
	{
		ofs << result << "\n";
	}
		ofs.close();
		cout << "Results saved to " << filePath << "\n";
	}
	else
	{
		cout << "Error opening file for writing.\n";
		return 1;
	}
	// reaad results for file
	ifstream ifs(filePath);
	if (ifs)
	{
		cout << "Reading results from " << filePath << ":\n";
		while (getline(ifs, line))
		{
			cout << line << "\n";
		}
		ifs.close();
	}
	else
	{
		cout << "Error opening file for reading.\n";
		return 1;
	}


	(void)_getch();
	return 0;
}