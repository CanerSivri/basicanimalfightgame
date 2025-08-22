#include "Team.h"
#include "Animal.h" 
#include <iostream>

using namespace std;

Team::Team(string name) {
	teamName = name;
}

Team::~Team() {}

string Team::getTeamName() const {
	return teamName;
}

void Team::addAnimal(Animal* animal) {
	animals.push_back(animal);
	cout << animal->getName() << " has been added to team " << getTeamName() << "." << endl;
}

void Team::removeAnimalfromTeam(int i) {
	if (i < 0 || i >= animals.size()) { 
		cout << "Invalid index!" << endl;
		return;
	}
	cout << animals[i]->getName() << " has been removed from team " << getTeamName() << "." << endl;
	animals.erase(animals.begin() + i);
}

int Team::getTotalHealth() const {
	int total = 0;
	for (int i = 0; i < animals.size(); i++) { 
		total += animals[i]->getHealth();
	}
	return total;
}

int Team::getTotalAttackPower() const {
	int total = 0;
	for (int i = 0; i < animals.size(); i++) { 
		total += animals[i]->getPower();
	}
	return total;
}

double Team::getAverageCondition() const {
	if (animals.empty()) return 0;

	int total = 0;
	for (int i = 0; i < animals.size(); i++) { 
		total += animals[i]->getCondition();
	}
	double avg = total;
	avg = avg / animals.size(); 
	return avg;
}

void Team::displayTeamStatus() const {
	cout << "~~~ Team: " << getTeamName() << " ~~~" << endl;
	if (animals.empty()) {
		cout << "No animals are in the team." << endl;
		return;
	}
	for (int i = 0; i < animals.size(); i++) { 
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		animals[i]->displayInfo();
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Total team health: " << getTotalHealth() << endl;
	cout << "Total team power: " << getTotalAttackPower() << endl;
	cout << "Average condition: " << getAverageCondition() << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

vector<Animal*>& Team::getAnimals() {
	return animals;
}