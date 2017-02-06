#include <iostream>
using namespace std;

int main() { //starting point of program

	int input; //variables are bool, char, int, double 
	cout << "how many cookies do you want?" << endl;
	cin >> input;

	if (input <= 5) {
		cout << "hey, you should take some more, we've got lots!" << endl;
		cout << "run the program again :)";

	}
	else if (input < 10)
		cout << "ok, here are your " << input << " cookies" << endl;
	else
		cout << "geez man, don't be greedy" << endl;
	


}