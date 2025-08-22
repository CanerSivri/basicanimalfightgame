#include "Tiger.h"
#include <iostream>

using namespace std;

Tiger::Tiger(string n, string g, int h, int power, int s, int c, double jump) : Animal(n, g, h, power, s, c) {
	max_jump = jump;
}

Tiger::~Tiger() {} 

double Tiger::getJumpHeight() const {
	return max_jump;
}

void Tiger::increaseJumpHeight(double height) {
	max_jump += height;
}

void Tiger::displayInfo() const {
	Animal::displayInfo();
	cout << "Animal's maximum jump height: " << getJumpHeight() << endl;
}

void Tiger::performAttack(Animal* target) {
	int damage = getPower();
	int remainingHealth = target->getHealth() - damage;
	if (remainingHealth < 0) {
		remainingHealth = 0;
	}
	target->setHealth(remainingHealth);
	cout << getName() << " attacks " << target->getName() << "." << target->getName() << " has left with " << target->getHealth() << " hp." << endl;
}

void Tiger::run() {
	if (getCondition() < 25) {
		cout << getName() << " is too tired to run." << endl;
		return;
	}
	increaseJumpHeight(30);
	increaseSpeed(35);
	increasePower(15);
	decreaseCondition(25);
	cout << getName() << " started to running.Its condition has decreased to " << getCondition() << ".Attack power has increased to " << getPower() << ", its speed has increased to " << getSpeed() << " and max jump height reached to " << getJumpHeight() << " cm." << endl;
}

void Tiger::useSpecialAbility() {
	run();
}

void Tiger::bite(Animal* other) {
	increasePower(30);
	int damage = getPower();
	int remainingHealth = other->getHealth() - damage;
	if (remainingHealth < 0) {
		remainingHealth = 0;
	}
	other->setHealth(remainingHealth);
	cout << getName() << " has bitten " << other->getName() << " with " << getPower() << " attack power. " << other->getName() << " has left with " << other->getHealth() << " hp." << endl;
}