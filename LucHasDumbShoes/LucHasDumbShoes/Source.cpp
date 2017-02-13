#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class Luc
{
private:
	int age;
	bool stinky;
	string name;
public:
	void init(int a, bool s, string n);
	void printInfo();
	int getAge();
};

bool compare(Luc *l1, Luc *l2);
vector<Luc *> listofLucs;

int main() {

	cout << "starting program" << endl << endl;
	system("pause");


	Luc *Utke = new Luc;
	Utke->init(26, true, "Utke");

	Luc *Moore = new Luc;
	Moore->init(17, true, "Moore");

	Luc *Osborne = new Luc;
	Osborne->init(12, true, "Osborne");

	Luc *Porter = new Luc;
	Porter->init(45, false, "Porter");

	listofLucs.push_back(Utke);
	listofLucs.push_back(Moore);
	listofLucs.push_back(Osborne);
	listofLucs.push_back(Porter);

	system("pause");
	cout << "printing vector for testing:" << endl;
	vector<Luc*>::iterator iter;
	for (iter = listofLucs.begin(); iter != listofLucs.end(); ++iter) {
		(*iter)->printInfo();
	}

	sort(listofLucs.begin(), listofLucs.end(), compare);


	system("pause");

	
	cout << endl << endl << endl << "printing sorted vector:" << endl;
	for (iter = listofLucs.begin(); iter != listofLucs.end(); ++iter) {
		(*iter)->printInfo();
	}


	cout << "goodbye!" << endl;

}//end main

void Luc::init(int a, bool s, string n) {

	age = a;
	stinky = s;
	name = n;

}
void Luc::printInfo() {
	cout << name << " is " << age << " years old and stinky is " << stinky << endl;
}

int Luc::getAge() {
	return age;
}

bool compare(Luc* l1, Luc* l2) {
	if ((*l1).getAge() < (*l2).getAge()){
		//cout << "return true" << endl;;
	return true;
	}
	else {
		//cout << "return false"<<endl;
		return false;
	}
}