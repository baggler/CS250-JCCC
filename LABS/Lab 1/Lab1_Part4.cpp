#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	bool done = false;

	cout << "Enter the next word of the sentence, or UNDO to undo, or DONE to stop." << endl;
	stack<string> sentence;
	while (!done)
	{
		string word;
		cout << ">> ";
		cin >> word;

		if (word == "UNDO")
		{
			cout << "Removing top-most item from the stack." << endl;
			sentence.pop();
		}
		else if (word == "DONE")
		{
			done = true;
		}
		else
		{
			sentence.push(word);
		}
	}

	cout << endl << endl << "Finished sentence: ";

	while (sentence.empty() != 1)
	{
		cout << sentence.top() << " ";
		sentence.pop();
	}
	cin.get();
	cin.get();
	return 0;
}