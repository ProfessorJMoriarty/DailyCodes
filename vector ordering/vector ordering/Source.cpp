#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class Luke
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

bool compare(Luke *l1, Luke *l2);

int main() {

	cout << "starting program"<<endl<<endl;
	system("pause");
	vector<Luke *> listofLukes;

	Luke *Utke = new Luke;
	Utke->init(26, true, "Utke");
	
	Luke *Moore = new Luke;
	Moore->init(17, true, "Moore");
	
	Luke *Osborne = new Luke;
	Osborne->init(12, true, "Osborne");
	
	Luke *Porter= new Luke;
	Porter->init(45, false, "Porter");

	listofLukes.push_back(*Utke);
	listofLukes.push_back(*Moore);
	listofLukes.push_back(*Osborne);
	listofLukes.push_back(*Porter);

	system("pause");
	cout << "printing vector for testing:" << endl;
	vector<Luke>::iterator iter;
	for (iter = listofLukes.begin(); iter != listofLukes.end(); ++iter) {
		 iter->printInfo();
	}

	sort(listofLukes.begin(), listofLukes.end(), compare);
	system("pause");
	cout <<endl<<endl<<endl<< "printing sorted vector:" << endl;
	for (iter = listofLukes.begin(); iter != listofLukes.end(); ++iter) {
		iter->printInfo();
	}


}

void Luke::init(int a, bool s, string n) {

	age = a;
	stinky = s;
	name = n;

}
void Luke::printInfo() {
	cout << name << " is " << age << " years old and stinky is " << stinky <<endl;
}

int Luke::getAge(){
	return age;
}

bool compare(Luke *l1, Luke *l2) { 
	if (l1->getAge() < l2->getAge())
		return true;
	else
		return false;
}
