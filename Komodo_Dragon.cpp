#include "Komodo_Dragon.h"
#include <iostream>

using namespace std;

Komodo_Dragon::Komodo_Dragon(string n, string g, int h, int power, int s, int c, bool venom) : Animal(n, g, h, power, s, c) {
	isItVenomous = venom;
}

Komodo_Dragon::~Komodo_Dragon() {} 

void Komodo_Dragon::displayInfo() const {
	Animal::displayInfo();
	cout << "Is it venomous: " << (getVenomState() ? "Yes" : "No") << endl;
}

bool Komodo_Dragon::getVenomState() const {
	return isItVenomous;
}

void Komodo_Dragon::performAttack(Animal* target) {
	if (getVenomState() == 1) { 
		increasePower(30);
	}
	int damage = getPower();
	int remainingHealth = target->getHealth() - damage;
	if (remainingHealth < 0) {
		remainingHealth = 0;
	}
	target->setHealth(remainingHealth);
	cout << getName() << " attacks " << target->getName() << "." << target->getName() << " has left with " << target->getHealth() << " hp." << endl;
}

void Komodo_Dragon::bite(Animal* other) {
	if (getVenomState() == 1) {
		increasePower(50);
	}
	else {
		increasePower(30);
	}
	int damage = getPower();
	int remainingHealth = other->getHealth() - damage;
	if (remainingHealth < 0) {
		remainingHealth = 0;
	}
	other->setHealth(remainingHealth);
	cout << getName() << " has bitten " << other->getName() << " with " << getPower() << " attack power. " << other->getName() << " has left with " << other->getHealth() << " hp." << endl;
}

void Komodo_Dragon::run() {
	if (getCondition() < 25) {
		cout << getName() << " is too tired to run." << endl;
		return;
	}
	increasePower(15);
	increaseSpeed(10);
	decreaseCondition(25);
	cout << getName() << " started to running.Its condition has decreased to " << getCondition() << ". Attack power has increased to " << getPower() << " and its speed has increased to " << getSpeed() << "." << endl;
}

void Komodo_Dragon::useSpecialAbility() {
	run();
}