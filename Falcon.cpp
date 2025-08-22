#include "Falcon.h"
#include <iostream> 

using namespace std;

Falcon::Falcon(string n, string g, int h, int power, int s, int c, tailColour tail) : Animal(n, g, h, power, s, c) {
	tail_Colour = tail;
}

Falcon::~Falcon() {} 

string Falcon::getTailColour() const {
	switch (tail_Colour) {
	case Black:
		return "Black";
	case Gray:
		return "Gray";
	case Brown:
		return "Brown";
	default:
		return "Unknown";
	}
}

void Falcon::displayInfo() const {
	Animal::displayInfo();
	cout << "Animal's tail colour: " << getTailColour() << endl;
}

void Falcon::bite(Animal* other) {
	cout << getName() << " cannot bite." << endl;
}

void Falcon::performAttack(Animal* target) {
	int damage = getPower();
	int remainingHealth = target->getHealth() - damage;
	if (remainingHealth < 0) {
		remainingHealth = 0;
	}
	target->setHealth(remainingHealth);
	cout << getName() << " attacks " << target->getName() << "." << target->getName() << " has left with " << target->getHealth() << " hp." << endl;
}

void Falcon::fly() {
	if (getCondition() < 30) {
		cout << getName() << " is too tired to fly." << endl;
		return;
	}
	increasePower(60);
	increaseSpeed(35);
	decreaseCondition(30);
	increaseHealth(15);
	cout << getName() << " flew.Its condition has decreased to " << getCondition() << ". Attack power has increased to " << getPower() << ", hp has increased to " << getHealth() << " and its speed has increased to " << getSpeed() << "." << endl;
}

void Falcon::useSpecialAbility() {
	fly();
}