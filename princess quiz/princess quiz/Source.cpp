#include<iostream>
using namespace std;

int main() {

	//set up different categories
	bool doexit = false;
	int tiana = 0;
	int ariel = 0;
	int peach = 0;
	int KyloRen = 0;
	char input;
	cout << "let's find out what disney princess you are!!!" << endl << endl << endl;

	//first question
	do {
		doexit = true;
	cout << "What's your favorite color? (g for green, b for blue, p for pink, k for black" << endl;
	cin >> input;
	if (input == 'g')
		tiana = tiana + 1;
	else if (input == 'b')
		ariel = ariel + 1;
	else if (input == 'p')
		peach++; //lazy way of saying peach = peach +1
	else if (input == 'k')
		KyloRen++;
	else {
		cout << "invalid input, dummy!" << endl; //defensive programming
		doexit = false;
	}
	} while (doexit == false);

	//question 2
	cout << "What's your favorite food? (g = gumbo, s =seaweed, m = mushrooms, j = jellybeans)" << endl;
	cin >> input;
	if (input == 'g')
		tiana = tiana + 3;
	else if (input == 's')
		ariel = ariel + 1;
	else if (input == 'm')
		peach++; //lazy way of saying peach = peach +1
	else if (input == 'j')
		KyloRen++;
	else
		cout << "invalid input, dummy!" << endl; //defensive programming


												 //question 2
	doexit = true;
	do {
		cout << "What's your favorite music (metal (m), country(c), EDM (e), reggae (r)" << endl;
		cin >> input;
		if (input == 'e')
			tiana = tiana + 3;
		else if (input == 'r')
			ariel = ariel + 1;
		else if (input == 'm')
			peach += 5; //lazy way of saying peach = peach +5
		else if (input == 'c')
			KyloRen++;
		else {
			cout << "invalid input, dummy!" << endl; //defensive programming
			doexit = false;
		}
	} while (doexit == false);


	if ((tiana > ariel) && (tiana > peach) && (tiana > KyloRen))
		cout << "you're tiana!" << endl;
	else if ((ariel > tiana) && (ariel > peach) && (ariel > KyloRen))
		cout << "you're ariel" << endl;
	else if ((peach > tiana) && (peach > ariel) && (peach > KyloRen))
		cout << "you're peach" << endl;
	else if ((KyloRen > tiana) && (KyloRen > ariel) && (peach < KyloRen))
		cout << "you're KyloRen" << endl;
	else
		cout << "either you're tied (try again), or you had invalid responses" << endl;

}