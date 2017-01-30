#include <iostream>
using namespace std;

class Utkus {
	int width, height;
public:
	int getWidth();
};

int main() {
	list<Utkus*> listOfItems;
	list<Item*>::iterator it;
	Now I am using this code to create an item :

	Item *p = new Item();
	p->id = itemCrowbar;
	listOfItems.push_back(p);
}

int Utkus::getWidth() {
	return width;

}