#include "Shark.h"
#include <iostream>

using namespace std;

Shark::Shark(string n, string g, int h, int power, int s, int c, sharkSpecies spec) : Animal(n, g, h, power, s, c) {
	specy = spec;
}

Shark::~Shark() {} 

string Shark::getSpecy() const {
	switch (specy) {
	case Mako:
		return "Mako";
	case Bull:
		return "Bull";
	case Great_White:
		return "Great White";
	case Nurse:
		return "Nurse";
	default:
		return "Unknown";
	}
}

void Shark::displayInfo() const {
	Animal::displayInfo();
	cout << "Animal's specy: " << getSpecy() << endl;
}

void Shark::bite(Animal* other) {
	increasePower(40);
	int damage = getPower();
	int remainingHealth = other->getHealth() - damage;
	if (remainingHealth < 0) {
		remainingHealth = 0;
	}
	other->setHealth(remainingHealth);
	cout << getName() << " has bitten " << other->getName() << " with " << getPower() << " attack power. " << other->getName() << " has left with " << other->getHealth() << " hp." << endl;
}

void Shark::performAttack(Animal* target) {
	int damage = getPower();
	int remainingHealth = target->getHealth() - damage;
	if (remainingHealth < 0) {
		remainingHealth = 0;
	}
	target->setHealth(remainingHealth);
	cout << getName() << " attacks " << target->getName() << "." << target->getName() << " has left with " << target->getHealth() << " hp." << endl;
}

void Shark::swim() {
	if (getCondition() < 20) {
		cout << getName() << " is too tired to swim." << endl;
		return;
	}
	increasePower(25);
	increaseSpeed(40);
	decreaseCondition(20);
	cout << getName() << " swam.Its condition has decreased to " << getCondition() << ". Attack power has increased to " << getPower() << " and its speed has increased to " << getSpeed() << "." << endl;
}

void Shark::useSpecialAbility() {
	swim();
}