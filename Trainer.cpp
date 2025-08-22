#include "Trainer.h"
#include "Animal.h" 
#include <iostream>

using namespace std;

Trainer::Trainer(string n) {
	name = n;
}

Trainer::~Trainer() {
	cout << "Trainer " << getTrainerName() << " has left the zoo." << endl;
}

string Trainer::getTrainerName() const {
	return name;
}

void Trainer::addAnimal(Animal* animal) {
	trainedAnimals.push_back(animal);
	cout << getTrainerName() << " is now training " << animal->getName() << "." << endl;
}

void Trainer::buffAttack(int amount) {
	cout << getTrainerName() << " is increasing attack power of all assigned animals by " << amount << "." << endl;
	for (int i = 0; i < trainedAnimals.size(); i++) { 
		trainedAnimals[i]->increasePower(amount);
	}
}

void Trainer::buffHealth(int amount) {
	cout << getTrainerName() << " is healing all assigned animals by " << amount << " HP." << endl;
	for (int i = 0; i < trainedAnimals.size(); i++) { 
		trainedAnimals[i]->increaseHealth(amount);
	}
}

void Trainer::buffCondition(int amount) {
	cout << getTrainerName() << " is increasing condition of all assigned animals by " << amount << "." << endl;
	for (int i = 0; i < trainedAnimals.size(); i++) { 
		trainedAnimals[i]->increaseCondition(amount);
	}
}

void Trainer::buffAll(int amountAttack, int amountHealth, int amountCondition) {
	buffAttack(amountAttack);
	buffHealth(amountHealth);
	buffCondition(amountCondition);
}

void Trainer::displayTrainedAnimals() const {
	cout << "Trainer " << getTrainerName() << " is training the following animals:" << endl;
	for (int i = 0; i < trainedAnimals.size(); i++) { 
		cout << "- " << trainedAnimals[i]->getName() << endl;
	}
}

bool Trainer::hasTrainedAnimals() const {
	return !trainedAnimals.empty();
}