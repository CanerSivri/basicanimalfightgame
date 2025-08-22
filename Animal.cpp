#include "Animal.h"


using namespace std; 

int Animal::totalAnimals = 0;

Animal::Animal(string n, string g, int h, int power, int s, int c) {
	name = n;
	gender = g;
	health = h;
	attackPower = power;
	speed = s;
	condition = c;
	totalAnimals++;
}

Animal::~Animal() {
	totalAnimals--;
	cout << totalAnimals << " animals have remained." << endl; 
}

string Animal::getName() const {
	return name;
}

string Animal::getGender() const {
	return gender;
}

int Animal::getHealth() const {
	return health;
}

void Animal::setHealth(int new_health) {
	health = new_health;
	if (health < 0) {
		health = 0;
	}
}

void Animal::increaseHealth(int h) {
	health += h;
}

int Animal::getPower() const {
	return attackPower;
}

void Animal::increasePower(int power) {
	attackPower += power;
}

int Animal::getSpeed() const {
	return speed;
}

void Animal::increaseSpeed(int increase) {
	speed += increase;
}

int Animal::getCondition() const {
	return condition;
}

void Animal::increaseCondition(int amount) {
	condition += amount;
	if (condition > 100) {
		condition = 100;
	}
}

void Animal::decreaseCondition(int amount) {
	condition -= amount;
	if (condition < 0) {
		condition = 0;
	}
}

void Animal::displayInfo() const {
	cout << "Animal's name: " << getName() << endl;
	cout << "Animal's gender: " << getGender() << endl;
	cout << "Animal's health: " << getHealth() << endl;
	cout << "Animal's attack power: " << getPower() << endl;
	cout << "Animal's speed: " << getSpeed() << endl;
	cout << "Animal's condition: " << getCondition() << endl;
}

void Animal::getAnimalCount() {
	cout << "Total animal count is: " << totalAnimals << endl;
}