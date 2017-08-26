#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	queue<float> transactions;
	transactions.push(101.32);
	transactions.push(-5.42);
	transactions.push(45.17);
	transactions.push(-34.22);
	float balance = 0.0;

	while (transactions.empty() != 1)
	{
		cout << transactions.front() << "  pushed to balance acocunt" << endl;
		balance = balance + transactions.front();
		transactions.pop();
	}
	cout << endl << "Final balance:  $" << balance << endl;
	cin.get();
	return 0;
}