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
	// creating filePaths and line variables to use for input and output for answers and input of the questions.
	string afilePath = "QuizResults.txt";
	string qfilePath = "questions.txt";
	string line;	



	cout << "Welcome to Math Quiz!";


	vector<string> questions;

	vector<int> answers = { 2, 2, 15, 3, 10, 2, 20, 16, 0, 1 };

	vector<string> results;


// Open the questions file and read its contents into the questions vector
ifstream qesFile(qfilePath);

if (!qesFile)
{
cout << "Error opening selected file.\n";
return 1;
}

while (getline(qesFile, line))
{
questions.push_back(line);
}
qesFile.close();


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
	ofstream ofs(afilePath);
	if (ofs)
	{
		for (const string& result : results)
		{
			ofs << result << "\n";
		}
		ofs.close();
		cout << "Results saved to " << afilePath << "\n";
	}
	else
	{
		cout << "Error opening file for writing.\n";
		return 1;
	}
	// read results from file
	ifstream ifs(afilePath);
	if (ifs)
	{
		cout << "Reading results from " << afilePath << ":\n";
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