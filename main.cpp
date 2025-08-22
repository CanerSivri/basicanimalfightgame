#include <iostream>
#include <string>
#include <vector>

#include "Tiger.h"
#include "Komodo_Dragon.h"
#include "Falcon.h" 
#include "Shark.h"  

#include "Team.h"
#include "Trainer.h"
#include "BattleArena.h"


using namespace std; 

int main() {
	vector<Animal*> allAnimals;
	vector<Team*> teams;
	vector<Trainer*> trainers;
	cout << "Welcome to the Animal Battle Game. Please select a choice from menu." << endl;
	int choice = -1;
	while (choice != 9) {
		cout << " ~~~~~~ Main Menu ~~~~~~ " << endl;
		cout << "1- Create an animal." << endl;
		cout << "2- Create a team." << endl;
		cout << "3- Create a trainer." << endl;
		cout << "4- Assign animal to a trainer." << endl;
		cout << "5- Add animal to a team." << endl;
		cout << "6- Buff trained animals." << endl;
		cout << "7- Display team information." << endl;
		cout << "8- Start battle." << endl;
		cout << "9- Exit." << endl;
		cin >> choice; 
		switch (choice) {
		case 1: {
			Animal* newAnimal = nullptr;
			int health = 0, power = 0, speed = 0, condition = 0, animalType = 0;
			double jump_height = 0;
			int VenomChoice = -1, tailChoice = -1, specyChoice = -1;
			string name, gender; // 
			cout << "Please select an animal type." << endl << "1- Tiger" << endl << "2- Komodo Dragon" << endl << "3- Falcon" << endl << "4- Shark" << endl;
			cin >> animalType;
			if (animalType == 1) {
				cout << "Enter animal's name: ";
				cin >> name; 
				cout << "Enter animal's gender: ";
				cin >> gender; 
				cout << "Enter animal's health: ";
				cin >> health;
				cout << "Enter animal's attack power: ";
				cin >> power;
				cout << "Enter animal's speed: ";
				cin >> speed;
				cout << "Enter animal's condition: ";
				cin >> condition;
				cout << "Enter animal's maximum jump height (cm): ";
				cin >> jump_height;
				newAnimal = new Tiger(name, gender, health, power, speed, condition, jump_height);
			}
			else if (animalType == 2) {
				cout << "Enter animal's name: ";
				cin >> name; 
				cout << "Enter animal's gender: ";
				cin >> gender; 
				cout << "Enter animal's health: ";
				cin >> health;
				cout << "Enter animal's attack power: ";
				cin >> power;
				cout << "Enter animal's speed: ";
				cin >> speed;
				cout << "Enter animal's condition: ";
				cin >> condition;
				cout << "Is it venomous? (1 for yes,0 for no): ";
				cin >> VenomChoice;
				bool venom = (VenomChoice == 1);
				newAnimal = new Komodo_Dragon(name, gender, health, power, speed, condition, venom);
			}
			else if (animalType == 3) {
				cout << "Enter animal's name: ";
				cin >> name; 
				cout << "Enter animal's gender: ";
				cin >> gender; 
				cout << "Enter animal's health: ";
				cin >> health;
				cout << "Enter animal's attack power: ";
				cin >> power;
				cout << "Enter animal's speed: ";
				cin >> speed;
				cout << "Enter animal's condition: ";
				cin >> condition;
				cout << "Select a tail colour: (0-Black 1-Gray 2-Brown) ";
				cin >> tailChoice;
				tailColour tail = static_cast<tailColour>(tailChoice);
				newAnimal = new Falcon(name, gender, health, power, speed, condition, tail);
			}
			else if (animalType == 4) {
				cout << "Enter animal's name: ";
				cin >> name; 
				cout << "Enter animal's gender: ";
				cin >> gender; 
				cout << "Enter animal's health: ";
				cin >> health;
				cout << "Enter animal's attack power: ";
				cin >> power;
				cout << "Enter animal's speed: ";
				cin >> speed;
				cout << "Enter animal's condition: ";
				cin >> condition;
				cout << "Enter animal's specy: (0-Mako 1-Bull 2-Great White 3-Nurse) ";
				cin >> specyChoice;
				sharkSpecies specy = static_cast<sharkSpecies>(specyChoice);
				newAnimal = new Shark(name, gender, health, power, speed, condition, specy);
			}
			else {
				cout << "Invalid animal type selected." << endl;
			}
			if (newAnimal != nullptr) {
				allAnimals.push_back(newAnimal);
				cout << newAnimal->getName() << " created successfully!" << endl;
			}
			break;
		}
		case 2: {
			cout << "Enter team name: ";
			string teamName;
			cin >> teamName; 
			Team* newTeam = new Team(teamName);
			teams.push_back(newTeam);
			cout << "Team " << teamName << " created." << endl;
			break;
		}
		case 3: {
			cout << "Enter trainer name: ";
			string trainerName;
			cin >> trainerName; 
			Trainer* newTrainer = new Trainer(trainerName);
			trainers.push_back(newTrainer);
			cout << "Trainer " << trainerName << " created." << endl;
			break;
		}
		case 4: {
			if (trainers.empty()) {
				cout << "No trainers available. Create a trainer first." << endl;
				break;
			}
			if (allAnimals.empty()) {
				cout << "No animals available. Create animals first." << endl;
				break;
			}
			cout << "Select trainer: " << endl;
			for (int i = 0; i < trainers.size(); i++) { 
				cout << i << ": " << trainers[i]->getTrainerName() << endl;
			}
			int trainerIndex;
			cin >> trainerIndex;
			if (trainerIndex < 0 || trainerIndex >= trainers.size()) { 
				cout << "Invalid trainer index." << endl;
				break;
			}
			cout << "Select animal to assign to trainer:\n";
			for (int i = 0; i < allAnimals.size(); i++) { 
				cout << i << ": " << allAnimals[i]->getName() << endl;
			}
			int animalIndex;
			cin >> animalIndex;
			if (animalIndex < 0 || animalIndex >= allAnimals.size()) {
				cout << "Invalid animal index." << endl;
				break;
			}
			trainers[trainerIndex]->addAnimal(allAnimals[animalIndex]);
			break;
		}
		case 5: {
			if (teams.empty()) {
				cout << "No teams available. Create a team first." << endl;
				break;
			}
			if (allAnimals.empty()) {
				cout << "No animals available. Create animals first." << endl;
				break;
			}
			cout << "Select animal to add: " << endl;
			for (int i = 0; i < allAnimals.size(); i++) { 
				cout << i << ": " << allAnimals[i]->getName() << endl;
			}
			int animal_Index;
			cin >> animal_Index;
			if (animal_Index < 0 || animal_Index >= allAnimals.size()) { 
				cout << "Invalid animal index." << endl;
				break;
			}
			cout << "Select team to add to: " << endl;
			for (int i = 0; i < teams.size(); i++) { 
				cout << i << ": " << teams[i]->getTeamName() << endl;
			}
			int teamIndex;
			cin >> teamIndex;
			if (teamIndex < 0 || teamIndex >= (int)teams.size()) { 
				cout << "Invalid team index." << endl;
				break;
			}
			teams[teamIndex]->addAnimal(allAnimals[animal_Index]);
			break;
		}
		case 6: {
			cout << "~~~ Buff Trained Animals ~~~" << endl;
			if (trainers.empty()) {
				cout << "No trainers to buff. Create a trainer first." << endl;
				break;
			}
			cout << "Select trainer to buff:" << endl;
			for (size_t i = 0; i < trainers.size(); ++i) {
				cout << i << ": " << trainers[i]->getTrainerName() << endl;
			}
			int trainerIdx;
			cout << "Trainer index: ";
			cin >> trainerIdx;
			if (trainerIdx < 0 || trainerIdx >= static_cast<int>(trainers.size())) {
				cout << "Invalid trainer index." << endl;
				break;
			}
			if (!trainers[trainerIdx]->hasTrainedAnimals()) {
				cout << trainers[trainerIdx]->getTrainerName() << " is not training any animals yet." << endl;
				break;
			}
			cout << "Buffing animals for trainer " << trainers[trainerIdx]->getTrainerName() << "." << endl;
			trainers[trainerIdx]->displayTrainedAnimals();
			int attackBuff, healthBuff, conditionBuff;
			cout << "Attack power increase: ";
			cin >> attackBuff;
			cout << "Health recovery: ";
			cin >> healthBuff;
			cout << "Condition increase: ";
			cin >> conditionBuff;
			trainers[trainerIdx]->buffAll(attackBuff, healthBuff, conditionBuff);
			cout << "Animals have been buffed." << endl;
			trainers[trainerIdx]->displayTrainedAnimals();
			break;
		}
		case 7: {
			cout << "\n~~~ Team Information ~~~" << endl;
			if (teams.empty()) {
				cout << "No teams to display. Create a team first." << endl;
				break;
			}
			cout << "Select team to display information for: " << endl;
			for (int i = 0; i < static_cast<int>(teams.size()); i++) { 
				cout << i << ": " << teams[i]->getTeamName() << endl;
			}
			int teamIdx;
			cout << "Team index: ";
			cin >> teamIdx;
			if (teamIdx < 0 || teamIdx >= static_cast<int>(teams.size())) {
				cout << "Invalid team index." << endl;
				break;
			}
			teams[teamIdx]->displayTeamStatus();
			break;
		}
		case 8: {
			cout << "\n~~~ Start Battle ~~~" << endl;
			if (teams.size() < 2) {
				cout << "At least 2 teams are required to start a battle. Currently there are " << teams.size() << " teams." << endl;
				break;
			}
			cout << "Select the first team for the battle:" << endl;
			for (size_t i = 0; i < teams.size(); ++i) {
				cout << i << ": " << teams[i]->getTeamName() << endl;
			}
			int team1Idx;
			cout << "Team 1 index: ";
			cin >> team1Idx;
			if (team1Idx < 0 || team1Idx >= static_cast<int>(teams.size())) {
				cout << "Invalid Team 1 index." << endl;
				break;
			}
			cout << "Select the second team for the battle:" << endl;
			for (size_t i = 0; i < teams.size(); ++i) {
				if (static_cast<int>(i) == team1Idx) {
					continue;
				}
				cout << i << ": " << teams[i]->getTeamName() << endl;
			}
			int team2Idx;
			cout << "Team 2 index: ";
			cin >> team2Idx;
			if (team2Idx < 0 || team2Idx >= static_cast<int>(teams.size()) || team2Idx == team1Idx) {
				cout << "Invalid Team 2 index or same as Team 1." << endl;
				break;
			}
			BattleArena arena(teams[team1Idx], teams[team2Idx]);
			arena.startBattle();
			break;
		}
		case 9: {
			cout << "Exiting the game." << endl;
			for (size_t i = 0; i < allAnimals.size(); ++i) {
				delete allAnimals[i]; 
			}
			allAnimals.clear();
			for (size_t i = 0; i < teams.size(); ++i) {
				delete teams[i];
			}
			teams.clear();
			for (size_t i = 0; i < trainers.size(); ++i) {
				delete trainers[i];
			}
			trainers.clear();
			cout << "Thank you for playing the game!" << endl;
			break;
		}
		default:
			cout << "Invalid choice. Please enter a valid choice." << endl;
			break;
		}
	}
	return 0;
}